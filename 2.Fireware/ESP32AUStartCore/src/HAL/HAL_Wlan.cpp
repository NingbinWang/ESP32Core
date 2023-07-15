#include "HAL/HAL.h"
#include "Configs/Config.h"
#include <WiFi.h>
#include <WiFiUdp.h>
WiFiClient Client;
const char *ssid = "KingHome";
const char *passwd= "18896963287";
const char *host = "192.168.1.169";
const int tcpPort = 80;
WiFiUDP udp;


bool HAL::Wlan_Init(){
    WiFi.begin(ssid,passwd);
    udp.begin(7788);
    return 0;
}

void HAL::Wlan_Update(){
   if(WiFi.status() == WL_CONNECTED)
   {
     Serial.println("");
     Serial.println("WIFI EONNECTED! IP =");
     Serial.println(WiFi.localIP());
   }else{
     return;
   }
   int packetSize = udp.parsePacket();
   if(packetSize)
   {
     char buffer[255];
     int len = udp.read(buffer,sizeof(buffer)-1);
     if(len>0){
        buffer[len]='\0';
        Serial.println(buffer);
     }
   }

}