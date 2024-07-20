#include "esp_camera.h"
#include <WiFi.h>
#include "esp_http_server.h"

// ===================
// 选择摄像头型号
// ===================
#define CAMERA_MODEL_AI_THINKER // 有PSRAM

#include "camera_pins.h"

// ===========================
// 输入你的WiFi凭证
// ===========================
const char *ssid = "iQOO";
const char *password = "aaa12345678";

// 函数声明
void initializeCameraServer();
void setupLedFlash(int pin);

// 用于通过HTTP流式传输捕获的图像的函数
esp_err_t capture_handler(httpd_req_t *req) {
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) {
        httpd_resp_send_500(req);
        return ESP_FAIL;
    }

    httpd_resp_set_type(req, "image/jpeg");
    httpd_resp_set_hdr(req, "Content-Disposition", "inline; filename=capture.jpg");
    httpd_resp_send(req, (const char *)fb->buf, fb->len);
    esp_camera_fb_return(fb);
    return ESP_OK;
}

// 启动摄像头服务器的函数
void initializeCameraServer() {
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    httpd_handle_t server = NULL;

    httpd_uri_t capture_uri = {
        .uri       = "/capture",
        .method    = HTTP_GET,
        .handler   = capture_handler,
        .user_ctx  = NULL
    };

    if (httpd_start(&server, &config) == ESP_OK) {
        httpd_register_uri_handler(server, &capture_uri);
    }
}

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_VGA; // 设置为640x480分辨率
  config.pixel_format = PIXFORMAT_JPEG;  // 用于流媒体
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;  // 设置初始图像质量
  config.fb_count = 1;

  // 如果有PSRAM IC，使用UXGA分辨率和更高JPEG质量进行初始化
  // 为更大的预分配帧缓冲区。
  if (config.pixel_format == PIXFORMAT_JPEG) {
    if (psramFound()) {
      config.jpeg_quality = 10;  // 有PSRAM时，降低jpeg_quality值以提高图像质量
      config.fb_count = 2;
      config.grab_mode = CAMERA_GRAB_LATEST;
    } else {
      // 如果没有PSRAM，限制帧大小
      config.frame_size = FRAMESIZE_SVGA;
      config.fb_location = CAMERA_FB_IN_DRAM;
    }
  } else {
    // 面部检测/识别的最佳选择
    config.frame_size = FRAMESIZE_240X240;
#if CONFIG_IDF_TARGET_ESP32S3
    config.fb_count = 2;
#endif
  }

  // 初始化摄像头
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("摄像头初始化失败，错误代码 0x%x", err);
    return;
  }

  sensor_t *s = esp_camera_sensor_get();
  // 初始传感器垂直翻转，颜色有点饱和
  if (s->id.PID == OV3660_PID) {
    s->set_vflip(s, 1);        // 翻转回去
    s->set_brightness(s, 1);   // 提高一点亮度
    s->set_saturation(s, -2);  // 降低饱和度
  }
  // 确保摄像头配置未被覆盖
  if (config.pixel_format == PIXFORMAT_JPEG) {
    s->set_framesize(s, FRAMESIZE_VGA); // 设置为640x480分辨率
  }

  WiFi.begin(ssid, password);
  WiFi.setSleep(false);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi 已连接");

  initializeCameraServer();

  Serial.print("摄像头准备好了！使用 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("/capture' 进行连接");
}

void loop() {
  // 什么也不做。所有操作都在另一个任务中由网络服务器完成
  delay(10000);
}
