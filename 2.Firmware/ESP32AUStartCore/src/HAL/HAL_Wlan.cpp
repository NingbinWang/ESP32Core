#include "HAL/HAL.h"
#include "Configs/Config.h"
#include <WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "KingHome";
const char *passwd= "18896963287";

IPAddress remote_IP(192, 168, 1, 169);// 自定义远程监 IP 地址

WiFiUDP udp;
unsigned int localUdpPort = 7788;

bool HAL::Wlan_Init(){
  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false); //关闭STA模式下wifi休眠，提高响应速度
  WiFi.begin(ssid, passwd);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print(".");
  }
  Serial.print("Connected, IP Address: ");
  Serial.println(WiFi.localIP());


    return 0;
}

void HAL::Wlan_Update(){
  int recv_length;
  char recvbuff[255];  //存储接收到的数据
  recv_length=udp.parsePacket();    //获取接收的数据的长度
  if(recv_length)                       //如果有数据那么recv_length不为0
  {
    int len = udp.read(recvbuff, 255);  //读取数据到recvbuff中
    if (len > 0)
    {
      Serial.println(recvbuff);  //串口打印网口收到的数据
    }
    
    //将接收到的数据发送回去
    udp.beginPacket(udp.remoteIP(),udp.remotePort());  //准备发送数据到目标IP和目标端口
    udp.print("Receive:");
    udp.println(recvbuff);  //数据放入发送的缓冲区
    udp.endPacket();              //发送
    
    for(int i=0;i<255;i++)     //清空接收数组
    {recvbuff[i] = 0;}
  }
//Serial.println("wait");

}