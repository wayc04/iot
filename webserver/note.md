# echarts学习笔记



## 安装

---

使用CDN方法静态导入进行加速

```javascript
https://cdn.jsdelivr.net/npm/echarts@4.3.0/dist/echarts.min.js
```



## 配置语法

---

1. 设置配置信息

echarts库使用json格式进行配置，option 表示使用 json 数据格式的配置来绘制图表

```javascript
echarts.init(document.getElementById('main')).setOption(option);
```



### **标题**

为图表配置标题

```javascript
title: {
	text: 'this is a echarts example'
}
```



### 提示信息

配置提示信息

```javascript
tooltip: {}
```



### 图例组件

图例组件展示了不同系列的标记，颜色和名字

```JavaScript
legend: {
	data: [{
		name: 'sery 1',
		// 强制设置图形为圆
		icon: 'circle',
		// 设置文本颜色
		textStyle: {
			color: 'red'
		}
	}]

}
```



### legend

图例

```
legend: {
}
```



### X轴

配置要在x轴显示的信息

```javascript
xAxis: {
	data: ["1", "2", "3"]
}
```



### y轴

配置要在x轴显示的信息

```javascript
yAxis: {
	data: ["1", "2", "3"]
}
```



### 系列列表

每个系列通过type决定自己的图表类型

```javascript
series: [{
	name: 'sales',// 系列名称
	type: 'bar',//系列图表类型
	data:[1, 2, 3,4, 5] //系列数据内容
}]
```

- **type: 'bar'**：柱状/条形图
- **type: 'line'**：折线/面积图
- **type: 'pie'**：饼图
- **type: 'scatter'**：散点（气泡）图
- **type: 'effectScatter'**：带有涟漪特效动画的散点（气泡）
- **type: 'radar'**：雷达图
- **type: 'tree'**：树型图
- **type: 'treemap'**：树型图
- **type: 'sunburst'**：旭日图
- **type: 'boxplot'**：箱形图
- **type: 'candlestick'**：K线图
- **type: 'heatmap'**：热力图
- **type: 'map'**：地图
- **type: 'parallel'**：平行坐标系的系列
- **type: 'lines'**：线图
- **type: 'graph'**：关系图
- **type: 'sankey'**：桑基图
- **type: 'funnel'**：漏斗图
- **type: 'gauge'**：仪表盘
- **type: 'pictorialBar'**：象形柱图
- **type: 'themeRiver'**：主题河流
- **type: 'custom'**：自定义系列



### 详细配置说明

```JavaScript
theme = {
    // 全图默认背景
    // backgroundColor: 'rgba(0,0,0,0)',

    // 默认色板
    color: ['#ff7f50','#87cefa','#da70d6','#32cd32','#6495ed',
            '#ff69b4','#ba55d3','#cd5c5c','#ffa500','#40e0d0',
            '#1e90ff','#ff6347','#7b68ee','#00fa9a','#ffd700',
            '#6699FF','#ff6666','#3cb371','#b8860b','#30e0e0'],

    // 图表标题
    title: {
        x: 'left',                 // 水平安放位置，默认为左对齐，可选为：
                                   // 'center' ¦ 'left' ¦ 'right'
                                   // ¦ {number}（x坐标，单位px）
        y: 'top',                  // 垂直安放位置，默认为全图顶端，可选为：
                                   // 'top' ¦ 'bottom' ¦ 'center'
                                   // ¦ {number}（y坐标，单位px）
        //textAlign: null          // 水平对齐方式，默认根据x设置自动调整
        backgroundColor: 'rgba(0,0,0,0)',
        borderColor: '#ccc',       // 标题边框颜色
        borderWidth: 0,            // 标题边框线宽，单位px，默认为0（无边框）
        padding: 5,                // 标题内边距，单位px，默认各方向内边距为5，
                                   // 接受数组分别设定上右下左边距，同css
        itemGap: 10,               // 主副标题纵向间隔，单位px，默认为10，
        textStyle: {
            fontSize: 18,
            fontWeight: 'bolder',
            color: '#333'          // 主标题文字颜色
        },
        subtextStyle: {
            color: '#aaa'          // 副标题文字颜色
        }
    },

    // 图例
    legend: {
        orient: 'horizontal',      // 布局方式，默认为水平布局，可选为：
                                   // 'horizontal' ¦ 'vertical'
        x: 'center',               // 水平安放位置，默认为全图居中，可选为：
                                   // 'center' ¦ 'left' ¦ 'right'
                                   // ¦ {number}（x坐标，单位px）
        y: 'top',                  // 垂直安放位置，默认为全图顶端，可选为：
                                   // 'top' ¦ 'bottom' ¦ 'center'
                                   // ¦ {number}（y坐标，单位px）
        backgroundColor: 'rgba(0,0,0,0)',
        borderColor: '#ccc',       // 图例边框颜色
        borderWidth: 0,            // 图例边框线宽，单位px，默认为0（无边框）
        padding: 5,                // 图例内边距，单位px，默认各方向内边距为5，
                                   // 接受数组分别设定上右下左边距，同css
        itemGap: 10,               // 各个item之间的间隔，单位px，默认为10，
                                   // 横向布局时为水平间隔，纵向布局时为纵向间隔
        itemWidth: 20,             // 图例图形宽度
        itemHeight: 14,            // 图例图形高度
        textStyle: {
            color: '#333'          // 图例文字颜色
        }
    },

    // 值域
    dataRange: {
        orient: 'vertical',        // 布局方式，默认为垂直布局，可选为：
                                   // 'horizontal' ¦ 'vertical'
        x: 'left',                 // 水平安放位置，默认为全图左对齐，可选为：
                                   // 'center' ¦ 'left' ¦ 'right'
                                   // ¦ {number}（x坐标，单位px）
        y: 'bottom',               // 垂直安放位置，默认为全图底部，可选为：
                                   // 'top' ¦ 'bottom' ¦ 'center'
                                   // ¦ {number}（y坐标，单位px）
        backgroundColor: 'rgba(0,0,0,0)',
        borderColor: '#ccc',       // 值域边框颜色
        borderWidth: 0,            // 值域边框线宽，单位px，默认为0（无边框）
        padding: 5,                // 值域内边距，单位px，默认各方向内边距为5，
                                   // 接受数组分别设定上右下左边距，同css
        itemGap: 10,               // 各个item之间的间隔，单位px，默认为10，
                                   // 横向布局时为水平间隔，纵向布局时为纵向间隔
        itemWidth: 20,             // 值域图形宽度，线性渐变水平布局宽度为该值 * 10
        itemHeight: 14,            // 值域图形高度，线性渐变垂直布局高度为该值 * 10
        splitNumber: 5,            // 分割段数，默认为5，为0时为线性渐变
        color:['#1e90ff','#f0ffff'],//颜色 
        //text:['高','低'],         // 文本，默认为数值文本
        textStyle: {
            color: '#333'          // 值域文字颜色
        }
    },

    toolbox: {
        orient: 'horizontal',      // 布局方式，默认为水平布局，可选为：
                                   // 'horizontal' ¦ 'vertical'
        x: 'right',                // 水平安放位置，默认为全图右对齐，可选为：
                                   // 'center' ¦ 'left' ¦ 'right'
                                   // ¦ {number}（x坐标，单位px）
        y: 'top',                  // 垂直安放位置，默认为全图顶端，可选为：
                                   // 'top' ¦ 'bottom' ¦ 'center'
                                   // ¦ {number}（y坐标，单位px）
        color : ['#1e90ff','#22bb22','#4b0082','#d2691e'],
        backgroundColor: 'rgba(0,0,0,0)', // 工具箱背景颜色
        borderColor: '#ccc',       // 工具箱边框颜色
        borderWidth: 0,            // 工具箱边框线宽，单位px，默认为0（无边框）
        padding: 5,                // 工具箱内边距，单位px，默认各方向内边距为5，
                                   // 接受数组分别设定上右下左边距，同css
        itemGap: 10,               // 各个item之间的间隔，单位px，默认为10，
                                   // 横向布局时为水平间隔，纵向布局时为纵向间隔
        itemSize: 16,              // 工具箱图形宽度
        featureImageIcon : {},     // 自定义图片icon
        featureTitle : {
            mark : '辅助线开关',
            markUndo : '删除辅助线',
            markClear : '清空辅助线',
            dataZoom : '区域缩放',
            dataZoomReset : '区域缩放后退',
            dataView : '数据视图',
            lineChart : '折线图切换',
            barChart : '柱形图切换',
            restore : '还原',
            saveAsImage : '保存为图片'
        }
    },

    // 提示框
    tooltip: {
        trigger: 'item',           // 触发类型，默认数据触发，见下图，可选为：'item' ¦ 'axis'
        showDelay: 20,             // 显示延迟，添加显示延迟可以避免频繁切换，单位ms
        hideDelay: 100,            // 隐藏延迟，单位ms
        transitionDuration : 0.4,  // 动画变换时间，单位s
        backgroundColor: 'rgba(0,0,0,0.7)',     // 提示背景颜色，默认为透明度为0.7的黑色
        borderColor: '#333',       // 提示边框颜色
        borderRadius: 4,           // 提示边框圆角，单位px，默认为4
        borderWidth: 0,            // 提示边框线宽，单位px，默认为0（无边框）
        padding: 5,                // 提示内边距，单位px，默认各方向内边距为5，
                                   // 接受数组分别设定上右下左边距，同css
        axisPointer : {            // 坐标轴指示器，坐标轴触发有效
            type : 'line',         // 默认为直线，可选为：'line' | 'shadow'
            lineStyle : {          // 直线指示器样式设置
                color: '#48b',
                width: 2,
                type: 'solid'
            },
            shadowStyle : {                       // 阴影指示器样式设置
                width: 'auto',                   // 阴影大小
                color: 'rgba(150,150,150,0.3)'  // 阴影颜色
            }
        },
        textStyle: {
            color: '#fff'
        }
    },

    // 区域缩放控制器
    dataZoom: {
        orient: 'horizontal',      // 布局方式，默认为水平布局，可选为：
                                   // 'horizontal' ¦ 'vertical'
        // x: {number},            // 水平安放位置，默认为根据grid参数适配，可选为：
                                   // {number}（x坐标，单位px）
        // y: {number},            // 垂直安放位置，默认为根据grid参数适配，可选为：
                                   // {number}（y坐标，单位px）
        // width: {number},        // 指定宽度，横向布局时默认为根据grid参数适配
        // height: {number},       // 指定高度，纵向布局时默认为根据grid参数适配
        backgroundColor: 'rgba(0,0,0,0)',       // 背景颜色
        dataBackgroundColor: '#eee',            // 数据背景颜色
        fillerColor: 'rgba(144,197,237,0.2)',   // 填充颜色
        handleColor: 'rgba(70,130,180,0.8)'     // 手柄颜色
    },

    // 网格
    grid: {
        x: 80,
        y: 60,
        x2: 80,
        y2: 60,
        // width: {totalWidth} - x - x2,
        // height: {totalHeight} - y - y2,
        backgroundColor: 'rgba(0,0,0,0)',
        borderWidth: 1,
        borderColor: '#ccc'
    },

    // 类目轴
    categoryAxis: {
        position: 'bottom',    // 位置
        nameLocation: 'end',   // 坐标轴名字位置，支持'start' | 'end'
        boundaryGap: true,     // 类目起始和结束两端空白策略
        axisLine: {            // 坐标轴线
            show: true,        // 默认显示，属性show控制显示与否
            lineStyle: {       // 属性lineStyle控制线条样式
                color: '#48b',
                width: 2,
                type: 'solid'
            }
        },
        axisTick: {            // 坐标轴小标记
            show: true,       // 属性show控制显示与否，默认不显示
            interval: 'auto',
            // onGap: null,
            inside : false,    // 控制小标记是否在grid里 
            length :5,         // 属性length控制线长
            lineStyle: {       // 属性lineStyle控制线条样式
                color: '#333',
                width: 1
            }
        },
        axisLabel: {           // 坐标轴文本标签，详见axis.axisLabel
            show: true,
            interval: 'auto',
            rotate: 0,
            margin: 8,
            // formatter: null,
            textStyle: {       // 其余属性默认使用全局文本样式，详见TEXTSTYLE
                color: '#333'
            }
        },
        splitLine: {           // 分隔线
            show: true,        // 默认显示，属性show控制显示与否
            // onGap: null,
            lineStyle: {       // 属性lineStyle（详见lineStyle）控制线条样式
                color: ['#ccc'],
                width: 1,
                type: 'solid'
            }
        },
        splitArea: {           // 分隔区域
            show: false,       // 默认不显示，属性show控制显示与否
            // onGap: null,
            areaStyle: {       // 属性areaStyle（详见areaStyle）控制区域样式
                color: ['rgba(250,250,250,0.3)','rgba(200,200,200,0.3)']
            }
        }
    },

    // 数值型坐标轴默认参数
    valueAxis: {
        position: 'left',      // 位置
        nameLocation: 'end',   // 坐标轴名字位置，支持'start' | 'end'
        nameTextStyle: {},     // 坐标轴文字样式，默认取全局样式
        boundaryGap: [0, 0],   // 数值起始和结束两端空白策略
        splitNumber: 5,        // 分割段数，默认为5
        axisLine: {            // 坐标轴线
            show: true,        // 默认显示，属性show控制显示与否
            lineStyle: {       // 属性lineStyle控制线条样式
                color: '#48b',
                width: 2,
                type: 'solid'
            }
        },
        axisTick: {            // 坐标轴小标记
            show: false,       // 属性show控制显示与否，默认不显示
            inside : false,    // 控制小标记是否在grid里 
            length :5,         // 属性length控制线长
            lineStyle: {       // 属性lineStyle控制线条样式
                color: '#333',
                width: 1
            }
        },
        axisLabel: {           // 坐标轴文本标签，详见axis.axisLabel
            show: true,
            rotate: 0,
            margin: 8,
            // formatter: null,
            textStyle: {       // 其余属性默认使用全局文本样式，详见TEXTSTYLE
                color: '#333'
            }
        },
        splitLine: {           // 分隔线
            show: true,        // 默认显示，属性show控制显示与否
            lineStyle: {       // 属性lineStyle（详见lineStyle）控制线条样式
                color: ['#ccc'],
                width: 1,
                type: 'solid'
            }
        },
        splitArea: {           // 分隔区域
            show: false,       // 默认不显示，属性show控制显示与否
            areaStyle: {       // 属性areaStyle（详见areaStyle）控制区域样式
                color: ['rgba(250,250,250,0.3)','rgba(200,200,200,0.3)']
            }
        }
    },

    polar : {
        center : ['50%', '50%'],    // 默认全局居中
        radius : '75%',
        startAngle : 90,
        splitNumber : 5,
        name : {
            show: true,
            textStyle: {       // 其余属性默认使用全局文本样式，详见TEXTSTYLE
                color: '#333'
            }
        },
        axisLine: {            // 坐标轴线
            show: true,        // 默认显示，属性show控制显示与否
            lineStyle: {       // 属性lineStyle控制线条样式
                color: '#ccc',
                width: 1,
                type: 'solid'
            }
        },
        axisLabel: {           // 坐标轴文本标签，详见axis.axisLabel
            show: false,
            textStyle: {       // 其余属性默认使用全局文本样式，详见TEXTSTYLE
                color: '#333'
            }
        },
        splitArea : {
            show : true,
            areaStyle : {
                color: ['rgba(250,250,250,0.3)','rgba(200,200,200,0.3)']
            }
        },
        splitLine : {
            show : true,
            lineStyle : {
                width : 1,
                color : '#ccc'
            }
        }
    },

    // 柱形图默认参数
    bar: {
        barMinHeight: 0,          // 最小高度改为0
        // barWidth: null,        // 默认自适应
        barGap: '30%',            // 柱间距离，默认为柱形宽度的30%，可设固定值
        barCategoryGap : '20%',   // 类目间柱形距离，默认为类目间距的20%，可设固定值
        itemStyle: {
            normal: {
                // color: '各异',
                barBorderColor: '#fff',       // 柱条边线
                barBorderRadius: 0,           // 柱条边线圆角，单位px，默认为0
                barBorderWidth: 1,            // 柱条边线线宽，单位px，默认为1
                label: {
                    show: false
                    // position: 默认自适应，水平布局为'top'，垂直布局为'right'，可选为
                    //           'inside'|'left'|'right'|'top'|'bottom'
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                }
            },
            emphasis: {
                // color: '各异',
                barBorderColor: 'rgba(0,0,0,0)',   // 柱条边线
                barBorderRadius: 0,                // 柱条边线圆角，单位px，默认为0
                barBorderWidth: 1,                 // 柱条边线线宽，单位px，默认为1
                label: {
                    show: false
                    // position: 默认自适应，水平布局为'top'，垂直布局为'right'，可选为
                    //           'inside'|'left'|'right'|'top'|'bottom'
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                }
            }
        }
    },

    // 折线图默认参数
    line: {
        itemStyle: {
            normal: {
                // color: 各异,
                label: {
                    show: false
                    // position: 默认自适应，水平布局为'top'，垂直布局为'right'，可选为
                    //           'inside'|'left'|'right'|'top'|'bottom'
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                },
                lineStyle: {
                    width: 2,
                    type: 'solid',
                    shadowColor : 'rgba(0,0,0,0)', //默认透明
                    shadowBlur: 5,
                    shadowOffsetX: 3,
                    shadowOffsetY: 3
                }
            },
            emphasis: {
                // color: 各异,
                label: {
                    show: false
                    // position: 默认自适应，水平布局为'top'，垂直布局为'right'，可选为
                    //           'inside'|'left'|'right'|'top'|'bottom'
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                }
            }
        },
        //smooth : false,
        //symbol: null,         // 拐点图形类型
        symbolSize: 2,          // 拐点图形大小
        //symbolRotate : null,  // 拐点图形旋转控制
        showAllSymbol: false    // 标志图形默认只有主轴显示（随主轴标签间隔隐藏策略）
    },

    // K线图默认参数
    k: {
        // barWidth : null          // 默认自适应
        // barMaxWidth : null       // 默认自适应 
        itemStyle: {
            normal: {
                color: '#fff',          // 阳线填充颜色
                color0: '#00aa11',      // 阴线填充颜色
                lineStyle: {
                    width: 1,
                    color: '#ff3200',   // 阳线边框颜色
                    color0: '#00aa11'   // 阴线边框颜色
                }
            },
            emphasis: {
                // color: 各异,
                // color0: 各异
            }
        }
    },

    // 散点图默认参数
    scatter: {
        //symbol: null,      // 图形类型
        symbolSize: 4,       // 图形大小，半宽（半径）参数，当图形为方向或菱形则总宽度为symbolSize * 2
        //symbolRotate : null,  // 图形旋转控制
        large: false,        // 大规模散点图
        largeThreshold: 2000,// 大规模阀值，large为true且数据量>largeThreshold才启用大规模模式
        itemStyle: {
            normal: {
                // color: 各异,
                label: {
                    show: false
                    // position: 默认自适应，水平布局为'top'，垂直布局为'right'，可选为
                    //           'inside'|'left'|'right'|'top'|'bottom'
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                }
            },
            emphasis: {
                // color: '各异'
                label: {
                    show: false
                    // position: 默认自适应，水平布局为'top'，垂直布局为'right'，可选为
                    //           'inside'|'left'|'right'|'top'|'bottom'
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                }
            }
        }
    },

    // 雷达图默认参数
    radar : {
        itemStyle: {
            normal: {
                // color: 各异,
                label: {
                    show: false
                },
                lineStyle: {
                    width: 2,
                    type: 'solid'
                }
            },
            emphasis: {
                // color: 各异,
                label: {
                    show: false
                }
            }
        },
        //symbol: null,         // 拐点图形类型
        symbolSize: 2           // 可计算特性参数，空数据拖拽提示图形大小
        //symbolRotate : null,  // 图形旋转控制
    },

    // 饼图默认参数
    pie: {
        center : ['50%', '50%'],    // 默认全局居中
        radius : [0, '75%'],
        clockWise : false,          // 默认逆时针
        startAngle: 90,
        minAngle: 0,                // 最小角度改为0
        selectedOffset: 10,         // 选中是扇区偏移量
        itemStyle: {
            normal: {
                // color: 各异,
                borderColor: '#fff',
                borderWidth: 1,
                label: {
                    show: true,
                    position: 'outer'
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                },
                labelLine: {
                    show: true,
                    length: 20,
                    lineStyle: {
                        // color: 各异,
                        width: 1,
                        type: 'solid'
                    }
                }
            },
            emphasis: {
                // color: 各异,
                borderColor: 'rgba(0,0,0,0)',
                borderWidth: 1,
                label: {
                    show: false
                    // position: 'outer'
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                },
                labelLine: {
                    show: false,
                    length: 20,
                    lineStyle: {
                        // color: 各异,
                        width: 1,
                        type: 'solid'
                    }
                }
            }
        }
    },

    map: {
        mapType: 'china',   // 各省的mapType暂时都用中文
        mapLocation: {
            x : 'center',
            y : 'center'
            // width    // 自适应
            // height   // 自适应
        },
        showLegendSymbol : true,       // 显示图例颜色标识（系列标识的小圆点），存在legend时生效
        itemStyle: {
            normal: {
                // color: 各异,
                borderColor: '#fff',
                borderWidth: 1,
                areaStyle: {
                    color: '#ccc'//rgba(135,206,250,0.8)
                },
                label: {
                    show: false,
                    textStyle: {
                        color: 'rgba(139,69,19,1)'
                    }
                }
            },
            emphasis: {                 // 也是选中样式
                // color: 各异,
                borderColor: 'rgba(0,0,0,0)',
                borderWidth: 1,
                areaStyle: {
                    color: 'rgba(255,215,0,0.8)'
                },
                label: {
                    show: false,
                    textStyle: {
                        color: 'rgba(139,69,19,1)'
                    }
                }
            }
        }
    },

    force : {
        // 数据map到圆的半径的最小值和最大值
        minRadius : 10,
        maxRadius : 20,
        density : 1.0,
        attractiveness : 1.0,
        // 初始化的随机大小位置
        initSize : 300,
        // 向心力因子，越大向心力越大
        centripetal : 1,
        // 冷却因子
        coolDown : 0.99,
        // 分类里如果有样式会覆盖节点默认样式
        itemStyle: {
            normal: {
                // color: 各异,
                label: {
                    show: false
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                },
                nodeStyle : {
                    brushType : 'both',
                    color : '#f08c2e',
                    strokeColor : '#5182ab'
                },
                linkStyle : {
                    strokeColor : '#5182ab'
                }
            },
            emphasis: {
                // color: 各异,
                label: {
                    show: false
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                },
                nodeStyle : {},
                linkStyle : {}
            }
        }
    },

    chord : {
        radius : ['65%', '75%'],
        center : ['50%', '50%'],
        padding : 2,
        sort : 'none', // can be 'none', 'ascending', 'descending'
        sortSub : 'none', // can be 'none', 'ascending', 'descending'
        startAngle : 90,
        clockWise : false,
        showScale : false,
        showScaleText : false,
        itemStyle : {
            normal : {
                label : {
                    show : true
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                },
                lineStyle : {
                    width : 0,
                    color : '#000'
                },
                chordStyle : {
                    lineStyle : {
                        width : 1,
                        color : '#666'
                    }
                }
            },
            emphasis : {
                lineStyle : {
                    width : 0,
                    color : '#000'
                },
                chordStyle : {
                    lineStyle : {
                        width : 2,
                        color : '#333'
                    }
                }
            }
        }
    },

    island: {
        r: 15,
        calculateStep: 0.1  // 滚轮可计算步长 0.1 = 10%
    },

    markPoint : {
        symbol: 'pin',         // 标注类型
        symbolSize: 10,        // 标注大小，半宽（半径）参数，当图形为方向或菱形则总宽度为symbolSize * 2
        //symbolRotate : null, // 标注旋转控制
        itemStyle: {
            normal: {
                // color: 各异，
                // borderColor: 各异,     // 标注边线颜色，优先于color 
                borderWidth: 2,            // 标注边线线宽，单位px，默认为1
                label: {
                    show: true,
                    position: 'inside' // 可选为'left'|'right'|'top'|'bottom'
                    // textStyle: null      // 默认使用全局文本样式，详见TEXTSTYLE
                }
            },
            emphasis: {
                // color: 各异
                label: {
                    show: true
                    // position: 'inside'  // 'left'|'right'|'top'|'bottom'
                    // textStyle: null     // 默认使用全局文本样式，详见TEXTSTYLE
                }
            }
        }
    },

    markLine : {
        // 标线起始和结束的symbol介绍类型，如果都一样，可以直接传string
        symbol: ['circle', 'arrow'],  
        // 标线起始和结束的symbol大小，半宽（半径）参数，当图形为方向或菱形则总宽度为symbolSize * 2
        symbolSize: [2, 4],
        // 标线起始和结束的symbol旋转控制
        //symbolRotate : null,
        itemStyle: {
            normal: {
                // color: 各异,           // 标线主色，线色，symbol主色
                // borderColor: 随color,     // 标线symbol边框颜色，优先于color 
                borderWidth: 2,          // 标线symbol边框线宽，单位px，默认为2
                label: {
                    show: false,
                    // 可选为 'start'|'end'|'left'|'right'|'top'|'bottom'
                    position: 'inside',  
                    textStyle: {         // 默认使用全局文本样式，详见TEXTSTYLE
                        color: '#333'
                    }
                },
                lineStyle: {
                    // color: 随borderColor, // 主色，线色，优先级高于borderColor和color
                    // width: 随borderWidth, // 优先于borderWidth
                    type: 'solid',
                    shadowColor : 'rgba(0,0,0,0)', //默认透明
                    shadowBlur: 5,
                    shadowOffsetX: 3,
                    shadowOffsetY: 3
                }
            },
            emphasis: {
                // color: 各异
                label: {
                    show: false
                    // position: 'inside' // 'left'|'right'|'top'|'bottom'
                    // textStyle: null    // 默认使用全局文本样式，详见TEXTSTYLE
                },
                lineStyle : {}
            }
        }
    },

    textStyle: {
        decoration: 'none',
        fontFamily: 'Arial, Verdana, sans-serif',
        fontFamily2: '微软雅黑',    // IE8- 字体模糊并且不支持不同字体混排，额外指定一份
        fontSize: 12,
        fontStyle: 'normal',
        fontWeight: 'normal'
    },

    // 默认标志图形类型列表
    symbolList : [
      'circle', 'rectangle', 'triangle', 'diamond',
      'emptyCircle', 'emptyRectangle', 'emptyTriangle', 'emptyDiamond'
    ],
    loadingText : 'Loading...',
    // 可计算特性配置，孤岛，提示颜色
    calculable: false,              // 默认关闭可计算特性
    calculableColor: 'rgba(255,165,0,0.6)',       // 拖拽提示边框颜色
    calculableHolderColor: '#ccc', // 可计算占位提示颜色
    nameConnector: ' & ',
    valueConnector: ' : ',
    animation: true,
    animationThreshold: 2500,       // 动画元素阀值，产生的图形原素超过2500不出动画
    addDataAnimation: true,         // 动态数据接口是否开启动画效果
    animationDuration: 2000,
    animationEasing: 'ExponentialOut'    //BounceOut
}
```



### example

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>配置语法</title>
</head>
<body>
    <!-- 为 ECharts 准备一个具备大小（宽高）的 DOM -->
    <div id="main" style="width: 600px;height:400px;"></div>

    <script src="https://cdn.jsdelivr.net/npm/echarts@4.3.0/dist/echarts.min.js"></script>
    <script>
        // 设置对应的配置信息
        var myChart = echarts.init(document.getElementById('main'));

        // 指定图表的配置项和数据
        var option = {
            title: {
                text: 'ECharts 入门示例'
            },
            tooltip: {},
            legend: {
                data:['销量']
            },
            xAxis: {
                data: ["衬衫","羊毛衫","雪纺衫","裤子","高跟鞋","袜子"]
            },
            yAxis: {},
            series: [{
                name: '销量',
                type: 'bar',
                data: [5, 20, 36, 10, 10, 20]
            }]
        }

        myChart.setOption(option);
    </script>

</body>
</html>
```



## 饼图

---

饼图主要是通过扇形的弧度表现不同类目的数据在总和中的占比，它的数据格式比柱状图更简单，只有一维的数值，不需要给类目。因为不在直角坐标系上，所以也不需要 xAxis，yAxis。



### example

```javascript
myChart.setOption({
    series : [
        {
            name: '访问来源',
            type: 'pie',    // 设置图表类型为饼图
            radius: '55%',  // 饼图的半径，外半径为可视区尺寸（容器高宽中较小一项）的 55% 长度。
            data:[          // 数据数组，name 为数据项名称，value 为数据项值
                {value:235, name:'视频广告'},
                {value:274, name:'联盟广告'},
                {value:310, name:'邮件营销'},
                {value:335, name:'直接访问'},
                {value:400, name:'搜索引擎'}
            ]
        }
    ]
})
```



## 样式设计

### 颜色主题

---

ECharts4 开始，除了默认主题外，内置了两套主题，分别为 **light** 和 **dark**

```javascript
var chart = echarts.init(dom, 'light');
 
//或者
 
var chart = echarts.init(dom, 'dark');
```

主题编辑器选择喜欢的主题下载

如果你使用 JS 版本，可以将 JS 主题代码保存一个 **主题名.js** 文件，然后在 HTML 中引用该文件，最后在代码中使用该主题。

```javascript
<!-- 引入主题 -->
<script src="https://www.runoob.com/static/js/wonderland.js"></script>
...

// HTML 引入 wonderland.js 文件后，在初始化的时候调用
var myChart = echarts.init(dom, 'wonderland');
// ...
```

如果主题保存为 JSON 文件，那么可以自行加载和注册。

比如上图中我们选中了一个主题，将 JSON 代码保存为 **wonderland.json**。

```javascript
//主题名称是 wonderland
$.getJSON('wonderland.json', function (themeJSON) {
    echarts.registerTheme('wonderland', themeJSON)
    var myChart = echarts.init(dom, 'wonderland');
});
```



### 调色盘

---

调色盘可以在 option 中设置。

调色盘给定了一组颜色，图形、系列会自动从其中选择颜色。

可以设置全局的调色盘，也可以设置系列自己专属的调色盘。

```javascript
option = {
    // 全局调色盘。
    color: ['#c23531','#2f4554', '#61a0a8', '#d48265', '#91c7ae','#749f83',  '#ca8622', '#bda29a','#6e7074', '#546570', '#c4ccd3'],

    series: [{
        type: 'bar',
        // 此系列自己的调色盘。
        color: ['#dd6b66','#759aa0','#e69d87','#8dc1a9','#ea7e53','#eedd78','#73a373','#73b9bc','#7289ab', '#91ca8c','#f49f42'],
        ...
    }, {
        type: 'pie',
        // 此系列自己的调色盘。
        color: ['#37A2DA', '#32C5E9', '#67E0E3', '#9FE6B8', '#FFDB5C','#ff9f7f', '#fb7293', '#E062AE', '#E690D1', '#e7bcf3', '#9d96f5', '#8378EA', '#96BFFF'],
        ...
    }]
}
```



### 直接样式设置

直接的样式设置是比较常用设置方式。纵观 ECharts 的 [option](https://www.echartsjs.com/zh/option.html#title) 中，很多地方可以设置 [itemStyle](https://www.echartsjs.com/zh/option.html#series.itemStyle)、[lineStyle](https://www.echartsjs.com/zh/option.html#series-line.lineStyle)、[areaStyle](https://www.echartsjs.com/zh/option.html#series-line.areaStyle)、[label](https://www.echartsjs.com/zh/option.html#series.label) 等等。这些的地方可以直接设置图形元素的颜色、线宽、点的大小、标签的文字、标签的样式等等。

一般来说，ECharts 的各个系列和组件，都遵从这些命名习惯，虽然不同图表和组件中，`itemStyle`、`label` 等可能出现在不同的地方。



### 高亮样式设置

在鼠标悬浮到图形元素上时，一般会出现高亮的样式。默认情况下，高亮的样式是根据普通样式自动生成的。

如果要自定义高亮样式可以通过 emphasis 属性来定制：

```javascript
// 高亮样式。
emphasis: {
    itemStyle: {
        // 高亮时点的颜色
        color: 'red'
    },
    label: {
        show: true,
        // 高亮时标签的文字
        formatter: '高亮时显示的标签内容'
    }
},
```



## 异步加载数据

---

ECharts 通常数据设置在 setOption 中，如果我们需要异步加载数据，可以配合 jQuery等工具，在异步获取数据后通过 setOption 填入数据和配置项就行。

ECharts 通常数据设置在 setOption 中，如果我们需要异步加载数据，可以配合 jQuery等工具，在异步获取数据后通过 setOption 填入数据和配置项就行。 json 数据：

```javascript
{
    "data_pie" : [
    {"value":235, "name":"视频广告"},
    {"value":274, "name":"联盟广告"},
    {"value":310, "name":"邮件营销"},
    {"value":335, "name":"直接访问"},
    {"value":400, "name":"搜索引擎"}
    ]
}
```

### example

```javascript
var myChart = echarts.init(document.getElementById('main'));
$.get('https://www.runoob.com/static/js/echarts_test_data.json', function (data) {
    myChart.setOption({
        series : [
            {
                name: '访问来源',
                type: 'pie',    // 设置图表类型为饼图
                radius: '55%',  // 饼图的半径，外半径为可视区尺寸（容器高宽中较小一项）的 55% 长度。
                data:data.data_pie
            }
        ]
    })
}, 'json')
```

如果异步加载需要一段时间，我们可以添加 loading 效果，ECharts 默认有提供了一个简单的加载动画。只需要调用 showLoading 方法显示。数据加载完成后再调用 hideLoading 方法隐藏加载动画：

```javascript
var myChart = echarts.init(document.getElementById('main'));
myChart.showLoading();  // 开启 loading 效果
$.get('https://www.runoob.com/static/js/echarts_test_data.json', function (data) {
    myChart.hideLoading();  // 隐藏 loading 效果
    myChart.setOption({
        series : [
            {
                name: '访问来源',
                type: 'pie',    // 设置图表类型为饼图
                radius: '55%',  // 饼图的半径，外半径为可视区尺寸（容器高宽中较小一项）的 55% 长度。
                data:data.data_pie
            }
        ]
    })
}, 'json')
```

### 数据的动态更新

ECharts 由数据驱动，数据的改变驱动图表展现的改变，因此动态数据的实现也变得异常简单。

所有数据的更新都通过 setOption 实现，你只需要定时获取数据，setOption 填入数据，而不用考虑数据到底产生了那些变化，ECharts 会找到两组数据之间的差异然后通过合适的动画去表现数据的变化。

```javascript
var base = +new Date(2014, 9, 3);
var oneDay = 24 * 3600 * 1000;
var date = [];

var data = [Math.random() * 150];
var now = new Date(base);

function addData(shift) {
    now = [now.getFullYear(), now.getMonth() + 1, now.getDate()].join('/');
    date.push(now);
    data.push((Math.random() - 0.4) * 10 + data[data.length - 1]);

    if (shift) {
        date.shift();
        data.shift();
    }

    now = new Date(+new Date(now) + oneDay);
}

for (var i = 1; i < 100; i++) {
    addData();
}

option = {
    xAxis: {
        type: 'category',
        boundaryGap: false,
        data: date
    },
    yAxis: {
        boundaryGap: [0, '50%'],
        type: 'value'
    },
    series: [
        {
            name:'成交',
            type:'line',
            smooth:true,
            symbol: 'none',
            stack: 'a',
            areaStyle: {
                normal: {}
            },
            data: data
        }
    ]
};

setInterval(function () {
    addData(true);
    myChart.setOption({
        xAxis: {
            data: date
        },
        series: [{
            name:'成交',
            data: data
        }]
    });
}, 500);

// 基于准备好的dom，初始化echarts实例
var myChart = echarts.init(document.getElementById('main'));
myChart.setOption(option)
```



## 数据集

ECharts 使用 dataset 管理数据。

dataset 组件用于单独的数据集声明，从而数据可以单独管理，被多个组件复用，并且可以基于数据指定数据到视觉的映射。

### example

```javascript
option = {
    legend: {},
    tooltip: {},
    dataset: {
        // 提供一份数据。
        source: [
            ['product', '2015', '2016', '2017'],
            ['Matcha Latte', 43.3, 85.8, 93.7],
            ['Milk Tea', 83.1, 73.4, 55.1],
            ['Cheese Cocoa', 86.4, 65.2, 82.5],
            ['Walnut Brownie', 72.4, 53.9, 39.1]
        ]
    },
    // 声明一个 X 轴，类目轴（category）。默认情况下，类目轴对应到 dataset 第一列。
    xAxis: {type: 'category'},
    // 声明一个 Y 轴，数值轴。
    yAxis: {},
    // 声明多个 bar 系列，默认情况下，每个系列会自动对应到 dataset 的每一列。
    series: [
        {type: 'bar'},
        {type: 'bar'},
        {type: 'bar'}
    ]
}
```

or

```javascript
option = {
    legend: {},
    tooltip: {},
    dataset: {
        // 这里指定了维度名的顺序，从而可以利用默认的维度到坐标轴的映射。
        // 如果不指定 dimensions，也可以通过指定 series.encode 完成映射，参见后文。
        dimensions: ['product', '2015', '2016', '2017'],
        source: [
            {product: 'Matcha Latte', '2015': 43.3, '2016': 85.8, '2017': 93.7},
            {product: 'Milk Tea', '2015': 83.1, '2016': 73.4, '2017': 55.1},
            {product: 'Cheese Cocoa', '2015': 86.4, '2016': 65.2, '2017': 82.5},
            {product: 'Walnut Brownie', '2015': 72.4, '2016': 53.9, '2017': 39.1}
        ]
    },
    xAxis: {type: 'category'},
    yAxis: {},
    series: [
        {type: 'bar'},
        {type: 'bar'},
        {type: 'bar'}
    ]
};
```



### 数据到图形映射

我们可以在配置项中将数据映射到图形中。

我们可以使用 series.seriesLayoutBy 属性来配置 dataset 是列（column）还是行（row）映射为图形系列（series），默认是按照列（column）来映射。

以下实例我们将通过 seriesLayoutBy 属性来配置数据是使用列显示还是按行显示。

```javascript
option = {
    legend: {},
    tooltip: {},
    dataset: {
        source: [
            ['product', '2012', '2013', '2014', '2015'],
            ['Matcha Latte', 41.1, 30.4, 65.1, 53.3],
            ['Milk Tea', 86.5, 92.1, 85.7, 83.1],
            ['Cheese Cocoa', 24.1, 67.2, 79.5, 86.4]
        ]
    },
    xAxis: [
        {type: 'category', gridIndex: 0},
        {type: 'category', gridIndex: 1}
    ],
    yAxis: [
        {gridIndex: 0},
        {gridIndex: 1}
    ],
    grid: [
        {bottom: '55%'},
        {top: '55%'}
    ],
    series: [
        // 这几个系列会在第一个直角坐标系中，每个系列对应到 dataset 的每一行。
        {type: 'bar', seriesLayoutBy: 'row'},
        {type: 'bar', seriesLayoutBy: 'row'},
        {type: 'bar', seriesLayoutBy: 'row'},
        // 这几个系列会在第二个直角坐标系中，每个系列对应到 dataset 的每一列。
        {type: 'bar', xAxisIndex: 1, yAxisIndex: 1},
        {type: 'bar', xAxisIndex: 1, yAxisIndex: 1},
        {type: 'bar', xAxisIndex: 1, yAxisIndex: 1},
        {type: 'bar', xAxisIndex: 1, yAxisIndex: 1}
    ]
}
```

### example

```javascript
setTimeout(function () {

    option = {
        legend: {},
        tooltip: {
            trigger: 'axis',
            showContent: false
        },
        dataset: {
            source: [
                ['product', '2012', '2013', '2014', '2015', '2016', '2017'],
                ['Matcha Latte', 41.1, 30.4, 65.1, 53.3, 83.8, 98.7],
                ['Milk Tea', 86.5, 92.1, 85.7, 83.1, 73.4, 55.1],
                ['Cheese Cocoa', 24.1, 67.2, 79.5, 86.4, 65.2, 82.5],
                ['Walnut Brownie', 55.2, 67.1, 69.2, 72.4, 53.9, 39.1]
            ]
        },
        xAxis: {type: 'category'},
        yAxis: {gridIndex: 0},
        grid: {top: '55%'},
        series: [
            {type: 'line', smooth: true, seriesLayoutBy: 'row'},
            {type: 'line', smooth: true, seriesLayoutBy: 'row'},
            {type: 'line', smooth: true, seriesLayoutBy: 'row'},
            {type: 'line', smooth: true, seriesLayoutBy: 'row'},
            {
                type: 'pie',
                id: 'pie',
                radius: '30%',
                center: ['50%', '25%'],
                label: {
                    formatter: '{b}: {@2012} ({d}%)'
                },
                encode: {
                    itemName: 'product',
                    value: '2012',
                    tooltip: '2012'
                }
            }
        ]
    };

    myChart.on('updateAxisPointer', function (event) {
        var xAxisInfo = event.axesInfo[0];
        if (xAxisInfo) {
            var dimension = xAxisInfo.value + 1;
            myChart.setOption({
                series: {
                    id: 'pie',
                    label: {
                        formatter: '{b}: {@[' + dimension + ']} ({d}%)'
                    },
                    encode: {
                        value: dimension,
                        tooltip: dimension
                    }
                }
            });
        }
    });

    myChart.setOption(option);

});
```

