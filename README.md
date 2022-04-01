# ESP32CORE
此项目的重点在于如何打造一个开方的ESP32的验证平台，方便开发者对于ESP32的各类验证，通过这些芯片的验证与能力的交叉从而得到比较强的提升

# 硬件设计
硬件具体仿照Peak的方案来做的，可拓展性比较小，但基本上能够验证到的都验证到了。
具体如下：

![](/4.Docs/1.Images/sch.png)

后续还有layout尚未完成。

# 外观设计


# 软件设计
软件上还是借鉴了稚晖君的Peak,但本人基本重新构造了一边，后续等完成板子后，再去完善数据同步的一些问题。

## 总体框架图

具体如下：

![](/4.Docs/1.Images/framework.png)

具体可以看到这边主要设计了页面调度与消息框架，并分离出FrameWork层的工作空间与Application的设计，Framework层主要负责对于顶层StatusBar的更新，通过SystemNotify的功能通知，而该通知功能主要的数据传输功能又是来自PingPongBuffer。主要的页面管理是来自于PagesManger,而utils主要是做功能拓展的，比如将SD卡这种功能服务放在这里。

主要目的是设计一个比较完善的机制用于数据传输与设计，为后面的项目做好相关的准备

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

