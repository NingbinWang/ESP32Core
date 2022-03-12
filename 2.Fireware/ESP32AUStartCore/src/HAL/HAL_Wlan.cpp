#include "HAL/HAL.h"
#include "Configs/Config.h"
#include <WiFi.h>
WiFiClient Client;
const char *ssid = "Tianya";
const char *passwd= "344197612w";
const char *host = "1.1.1.1";
const int tcpPort = 80;



bool HAL::Wlan_Init(){
    WiFi.begin(ssid,passwd);
    return 0;
}

void HAL::Wlan_Update(){
    if(WiFi.status() == WL_CONNECTED){
        Serial.println("WiFi connected");
        Serial.println(WiFi.localIP());
        if(Client.connected()){
            if(Client.connect(host,tcpPort)){
                Serial.println("OK");
            }
        }
    }

}