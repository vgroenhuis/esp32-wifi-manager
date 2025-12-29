# roaming-wifi-manager
Wifi connectivity manager aimed for iotroam networks at university, supporting active roaming. Useful for static and mobile robots

## features

- display mac address to serial so that you can register it at iotroam.nl
- connect to iotroam with given password
- use 5 GHz band by default
- active roaming: periodically scan networks asynchronously, connecting to a significantly stronger hotspot if available
- http endpoint at /wifi with status information, available networks and BSSID's, and some other generic data
- designed for easy integration with other ESP32-C5 projects
- control LED on ESP32-C5 (official devkit or waveshare) to show wifi status

## options
Add VIN_DEBUG=3 to build flags to enable outputting debug information to Serial

## LED color
- red: boot
- orange: setup
- bright orange: scanning networks (synchronously)
- blue: processing scanned networks
- orange flashing: connecting to best network
- green: connected
- red: not connected (invalid credentials, access point unreachable or another error)

## HTTP endpoints

- /wifi : dashboard (html)
- /wifi/status : json object with status information
- /wifi/scan (POST)
- /wifi/networks : json array with known networks
- /wifi/connect (POST)
- /wifi/settings
- /wifi/autoscan (POST)



## todo

- network scan interval, make it work
- checkbox to enable/disable auto-switching to other bssid
- save connection info bssid for quicker reload at next startup
- consider skipping connection in setup() and (re)connect in loop instead
- make web graph showing signal strength of connected (green), alternative bssid's at same ssid (dark green), other known networks (dark blue) and unknown networks (gray)