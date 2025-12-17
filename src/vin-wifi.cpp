#include "vin-wifi.h"
#include <WiFi.h>

void VincentESP32WiFiManager::printMAC() {
    uint8_t mac[6];

    WiFi.mode(WIFI_STA);
    WiFi.setBandMode(WIFI_BAND_MODE_5G_ONLY);
    Serial.printf("ESP32 WiFi MAC Address: %s\n", WiFi.macAddress().c_str());
}

void VincentESP32WiFiManager::init(String ssid, String password) {
    WiFi.mode(WIFI_STA);
    WiFi.setSleep(false);
    WiFi.setBandMode(WIFI_BAND_MODE_5G_ONLY);


    WiFi.onEvent(handleWiFiEvent);

}

void VincentESP32WiFiManager::onWifiEvent(AwsEventHandler handler) {
    _wifiEventHandler = handler;
}

void VincentESP32WiFiManager::handleWiFiEvent(WiFiEvent_t event) {

    if (_wifiEventHandler) {
        _wifiEventHandler(event);
    }
}

