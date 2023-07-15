# ESP32CORE
此项目的重点在于如何打造一个开源的ESP32的开发板，这个开发板主要的目的是为了学习lvgl的框架。

# 硬件设计
硬件主要带一个SPI的LCD屏幕，MPU6050，拨码器与SD卡槽，将其他的引脚都引出来，主要是做4层板子，采用画板软件为AD22。

## ESP32无法进入下载模式，每次都是超时的问题
我查过自己焊接的ESP32焊接点饱满，DTR与RTS均有作用，ESP_EN与BOOT引脚有拉低，时序也满足，RX,TX链路全部通的，不知道为何就是不起作用。难道CH340C（注意原理图上虽然写着CH340G但要使用CH340C）不能正常工作？陷入了自我怀疑的状态。

在网上搜了无数的资料，才知道这个自带flash的ESP32-PICO-D4是超级脆弱，注意，注意，焊接的时候，用锡膏涂一下引脚和PCB，在中间加点焊油，热风枪一定要控制在280度以内，血泪史啊！！！


硬件具体如下：

![](/4.Docs/1.Images/sch.png)

## PCB的设计
![](/4.Docs/1.Images/pcb.png)

## PCB3D的显示
![](/4.Docs/1.Images/3dboard.png)


# 软件设计
设计一套关于服务->应用的框架，所有的底层工作都有Framework来完成。然后将App层面的页面管理与相关的数据工作都进行解构，最终让用户可以很方便的进行页面上的移植与设计自己的页面。

## 总体框架图

具体如下：

![](/4.Docs/1.Images/framework.png)

具体可以看到这边主要设计了页面调度与消息框架，并分离出FrameWork层的工作空间与Application的设计，Framework层主要负责相关的服务，而主要的业务全部交给App来完成。

## 页面管理

主要是参考ios设计具体网址： [iosviewcontroller](https://developer.apple.com/documentation/uikit/uiviewcontroller)

而这边的设计具体流程图如下：

![](/4.Docs/1.Images/view.png)

以代码中的SystemInfos为例：具体可以看SystemInfos.cpp

在执行 onViewLoad (页面开始加载)时初始化视图和数据；在 onViewDidAppear（页面即将显示） 执行过渡动画，在动画结束时显示地图容器。

在有外部事件触发后，依次执行onViewWillDisappear(页面即将消失)、 onViewDidDisappear （页面消失完成）、onViewDidUnload（页面卸载完成）。

而页面的自更新为onViewDidDisappear 到onViewWillAppear

### 消息框架

消息框架提供数据的分发和处理。其使用订阅发布机制完成，将 HAL 层的接收到的传感器数据发布，转发给对应的订阅者进行数据处理。

以IMU 为例，IMU 数据处理节点每秒读取一次IMU数据，然后发起 publish ，由消息框架将IMU 数据推送给订阅者。在运动数据处理节点中订阅 IMU 数据。在收到 IMU数据之后，运动数据处理节点根据 IMU 数据计算航向角等信息。

## Framework

主要是页面管理、时钟信息、存储服务、时间、数据流记录

### Utils 

framework主要服务代码：

* StorageService
* Time

### Pages
主机页面

### PagesManager

主要用于管理页面，具体的类如下：

* PageBase:基础页面类

* PageFactory：创建页面类

* PageManager:页面管理类

* PageManagerAnim:动画管理类

* PageManagerDrag:动画管理类

* PageManagerBase:动画管理类

* PageManagerSrate:动画管理类

### Notification
主要用于通知

### Resources
资源管理

* Font: 字体资源

* Image: 图像资源

* ResourcePool: 资源池管理

## HAL

lib与kernel的集合，主要用于支持外设的数据初始化与更新的

### lvgl的初始化的框架

![](/4.Docs/1.Images/lvgl.png)

# 参考


