// Visit <IP address>/wifi for the WiFi administration panel
#include "RoamingWiFiManager.h"

RoamingWiFiManager manager;

void setup() {
    Serial.begin(115200);
    manager.init({{"ssid","password"}}); // replace with your known network(s)
}

void loop() {
    manager.loop();
}
