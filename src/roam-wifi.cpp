#include "esp32-wifi-manager.h"
#include <WiFi.h>

void RoamingWifiManager::printMAC() {
    uint8_t mac[6];

    WiFi.mode(WIFI_STA);
    WiFi.setBandMode(WIFI_BAND_MODE_5G_ONLY);
    Serial.printf("ESP32 WiFi MAC Address: %s\n", WiFi.macAddress().c_str());
}

void RoamingWifiManager::init(String ssid, String password) {

}