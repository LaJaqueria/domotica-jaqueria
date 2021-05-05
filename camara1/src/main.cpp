// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
wifi::WiFiComponent *wifi_wificomponent;
ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace api;
esp32_camera::ESP32Camera *esp32_camera_esp32camera;
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  // async_tcp:
  // esphome:
  //   name: camara1
  //   platform: ESP32
  //   board: nodemcu-32s
  //   arduino_version: espressif32@1.12.4
  //   build_path: camara1
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  App.pre_setup("camara1", __DATE__ ", " __TIME__);
  // wifi:
  //   ap:
  //     ssid: Camera
  //     password: password
  //     id: wifi_wifiap
  //     ap_timeout: 1min
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: LIGHT
  //   fast_connect: false
  //   networks:
  //   - ssid: LAJAQUERIA
  //     password: aUYJ63QE
  //     id: wifi_wifiap_2
  //     priority: 0.0
  //   use_address: camara1.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("camara1.local");
  wifi::WiFiAP wifi_wifiap_2 = wifi::WiFiAP();
  wifi_wifiap_2.set_ssid("LAJAQUERIA");
  wifi_wifiap_2.set_password("aUYJ63QE");
  wifi_wifiap_2.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap_2);
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("Camera");
  wifi_wifiap.set_password("password");
  wifi_wificomponent->set_ap(wifi_wifiap);
  wifi_wificomponent->set_ap_timeout(60000);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_LIGHT);
  wifi_wificomponent->set_fast_connect(false);
  App.register_component(wifi_wificomponent);
  // ota:
  //   password: jaqueriatemp
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 3232
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(3232);
  ota_otacomponent->set_auth_password("jaqueriatemp");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   password: jaqueriatemp
  //   id: api_apiserver
  //   port: 6053
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("jaqueriatemp");
  api_apiserver->set_reboot_timeout(900000);
  // esp32_camera:
  //   name: Camara 1
  //   external_clock:
  //     pin: 27
  //     frequency: 20000000.0
  //   i2c_pins:
  //     sda: 25
  //     scl: 23
  //   data_pins:
  //   - 17
  //   - 35
  //   - 34
  //   - 5
  //   - 39
  //   - 18
  //   - 36
  //   - 19
  //   vsync_pin: 22
  //   href_pin: 26
  //   pixel_clock_pin: 21
  //   reset_pin: 15
  //   resolution: 800X600
  //   jpeg_quality: 10
  //   id: esp32_camera_esp32camera
  //   max_framerate: 10.0
  //   idle_framerate: 0.1
  //   contrast: 0
  //   brightness: 0
  //   saturation: 0
  //   vertical_flip: true
  //   horizontal_mirror: true
  //   test_pattern: false
  esp32_camera_esp32camera = new esp32_camera::ESP32Camera("Camara 1");
  App.register_component(esp32_camera_esp32camera);
  esp32_camera_esp32camera->set_data_pins({17, 35, 34, 5, 39, 18, 36, 19});
  esp32_camera_esp32camera->set_vsync_pin(22);
  esp32_camera_esp32camera->set_href_pin(26);
  esp32_camera_esp32camera->set_pixel_clock_pin(21);
  esp32_camera_esp32camera->set_reset_pin(15);
  esp32_camera_esp32camera->set_jpeg_quality(10);
  esp32_camera_esp32camera->set_vertical_flip(true);
  esp32_camera_esp32camera->set_horizontal_mirror(true);
  esp32_camera_esp32camera->set_contrast(0);
  esp32_camera_esp32camera->set_brightness(0);
  esp32_camera_esp32camera->set_saturation(0);
  esp32_camera_esp32camera->set_test_pattern(false);
  esp32_camera_esp32camera->set_external_clock(27, 20000000.0f);
  esp32_camera_esp32camera->set_i2c_pins(25, 23);
  esp32_camera_esp32camera->set_max_update_interval(100.0f);
  esp32_camera_esp32camera->set_idle_update_interval(10000.0f);
  esp32_camera_esp32camera->set_frame_size(esp32_camera::ESP32_CAMERA_SIZE_800X600);
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  App.setup();
}

void loop() {
  App.loop();
}
