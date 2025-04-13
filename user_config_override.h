/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS     MY_IP                // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY        MY_GW                // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS            MY_DNS               // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

#ifdef MY_DNS2
#undef  WIFI_DNS2
#define WIFI_DNS2           MY_DNS2              // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!!
*/



#define USE_HEAT_INDEX

//#define USE_HOME_ASSISTANT                                   // Enable Home Assistant Discovery Support (+12k code, +6 bytes mem)
//  #define HOME_ASSISTANT_DISCOVERY_PREFIX   "homeassistant"  // Home Assistant discovery prefix
//  #define HOME_ASSISTANT_LWT_TOPIC   "homeassistant/status"  // home Assistant Birth and Last Will Topic (default = homeassistant/status)
//  #define HOME_ASSISTANT_LWT_SUBSCRIBE    true               // Subscribe to Home Assistant Birth and Last Will Topic (default = true)

#ifdef USE_EMULATION_HUE
#undef USE_EMULATION_HUE
#endif
#ifdef USE_EMULATION_WEMO
#undef USE_EMULATION_WEMO
#endif

#define USE_DISCOVERY

#define USE_BERRY                                // Enable Berry scripting language
#define USE_BERRY_DEBUG
//#define USE_BERRY_PSRAM                        // Allocate Berry memory in PSRAM if PSRAM is connected - this might be slightly slower but leaves main memory intact

// LVGL per https://tasmota.github.io/docs/LVGL/
#define USE_LVGL
#define USE_DISPLAY
#define USE_DISPLAY_LVGL_ONLY
#define USE_UNIVERSAL_DISPLAY
#undef USE_DISPLAY_MODES1TO5
#undef USE_DISPLAY_LCD
#undef USE_DISPLAY_SSD1306
#undef USE_DISPLAY_MATRIX
#undef USE_DISPLAY_SEVENSEG

#define USE_ADC_VCC                              // Display Vcc in Power status

// Device list
// QWIICMUX // can be omitted since the OLED screen that demands 400KHz is damaged and I have a new SPI one
// QWIIC Joystick
// 512 Kib EEPROM
// MAX17043 LiPo battery meter
#define USE_MAX17043                           // [I2cDriver83] Enable MAX17043 fuel-gauge systems Lipo batteries sensor (I2C address 0x36) (+0k9 code)
// BMA400 accelerometer
// LPS25HB vacuum-reference barometer
// SCD30 CO2 sensor
#define USE_SCD30                              // [I2cDriver29] Enable Sensiron SCd30 CO2 sensor (I2C address 0x61) (+3k3 code)
// AHT20 humidity sensor
#define USE_AHT2x                              // [I2cDriver43] Enable AHT20/AM2301B instead of AHT1x humidity and temperature sensor (I2C address 0x38) (+0k8 code)
#ifdef USE_VEML6070
#undef USE_VEML6070
// I2cDriver12 0
#endif
// SGP30 VOC mockery of a sensor
#define USE_SGP30                              // [I2cDriver18] Enable SGP30 sensor (I2C address 0x58) (+1k1 code)
// SPS30 particle sensor
#define USE_SPS30                              // [I2cDriver30] Enable Sensiron SPS30 particle sensor (I2C address 0x69) (+1.7 code)
// On Waveshare
// W25Q128JVSIQ 16-Mbit external flash
// PCF85063 RTC
#define USE_RTC_CHIPS                          // Enable RTC chip support and NTP server - Select only one
#define USE_PCF85063                         // [I2cDriver92] Enable PCF85063 RTC support (I2C address 0x51)
// QMI8658 6-axis IMU
// driver is in Berry
// pin-transistor-voice-coil buzzer
#ifndef USE_BUZZER
#define USE_BUZZER
#endif
// 4-wire SPI ST7789V2 LCD controller, 240x280
#define USE_SPI                                  // Hardware SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)
#define USE_DISPLAY_ST7789                   // [DisplayModel 12] Enable ST7789 module

/*
5.79inch e-Paper display (G), e-ink display, 792x272, Red/Yellow/Black/White, SPI Interface

PWR 	Power on/off control
BUSY 	Busy status output pin
RST 	External reset, low active
DC 	Data/Command selection (high for data, low for command)
CS 	SPI chip selection, low active
CLK 	SPI SCK pin
DIN 	SPI MOSI pin
GND 	Ground
VCC 	Power (3.3V / 5V input)

792 × 272 pixels
*/

/*
Wiring notes

So, I think everything can run through the 13-pin header.

QWIIC will map to VCC3V3:GND:SDA:SCL which is the same I2C buss as the IMU and RTC.

GND will be split to support VBUS being boost-regulated to 5V for the particulate sensor.

SPI is a bit messier since I have *three* SPI screens.
 * The built-in screen uses GPIO 4-8 inclusive and GPIO 15. This is wired on the board.
 * The 1.5" OLED screen is probably moot due to the built-in. Only 1 GPIO needed
 * The WaveShare 5.79" screen will hopefully be able to do SPI with a second peripheral on GPIO 2-3:16-18:U0TX:U0RX.

SPI0 and SPI1 are used for PSRAM, which I think I'll need for a GUI. That means I need to figure out what Tasmota thinks 1 and 2 are.
The SPI part of the ESP32 S3 manual says that SPI2 and SPI3 can go to any I/O pins. SPI2 is fastest on GPIO 9-14.

N.B. 3-wire SPI leaves DC pinned low.

See Excel doc

for a: wire1.scan() print(format("%x", a)) end
Returns 0b0xxxxxxx format addresses
#0x14 - BMA400 IMU
#0x20 - Joystick
0x36 - MAX17043 battery gauge - has Tasmota driver
#0x38 - AHT20 humidity - has Tasmota driver
0x50 - EEPROM
0x51 - RTC (onboard) - has Tasmota driver
0x58 - SGP30 VOC - has Tasmota driver
#0x5d - LPS25HB pressure
#0x61 - SCD30 CO2 - has Tasmota driver
0x6b - IMU (onboard) - my Berry driver
0x70 - QWIIC mux - Berry wire1.write(0x70, 0xff, 0, 0)
0x7e - Device ID range is 0x7C-7F

Enable all mux ports
wire1.write(0x70, 0xff, 0, 0)

*/

#ifndef USE_RULES
#define USE_RULES
#endif

#endif  // _USER_CONFIG_OVERRIDE_H_
