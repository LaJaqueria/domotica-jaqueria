// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using namespace binary_sensor;
logger::Logger *logger_logger;
web_server_base::WebServerBase *web_server_base_webserverbase;
captive_portal::CaptivePortal *captive_portal_captiveportal;
wifi::WiFiComponent *wifi_wificomponent;
ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace api;
using namespace spi;
spi::SPIComponent *spi_spicomponent;
rc522_spi::RC522Spi *rc522_spi_rc522spi;
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  // async_tcp:
  // esphome:
  //   name: lectornfc
  //   platform: ESP32
  //   board: esp32doit-devkit-v1
  //   arduino_version: espressif32@1.12.4
  //   build_path: lectornfc
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  App.pre_setup("lectornfc", __DATE__ ", " __TIME__);
  // binary_sensor:
  // logger:
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   hardware_uart: UART0
  //   level: DEBUG
  //   logs: {}
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  App.register_component(logger_logger);
  // web_server_base:
  //   id: web_server_base_webserverbase
  web_server_base_webserverbase = new web_server_base::WebServerBase();
  App.register_component(web_server_base_webserverbase);
  // captive_portal:
  //   id: captive_portal_captiveportal
  //   web_server_base_id: web_server_base_webserverbase
  captive_portal_captiveportal = new captive_portal::CaptivePortal(web_server_base_webserverbase);
  App.register_component(captive_portal_captiveportal);
  // wifi:
  //   ap:
  //     ssid: Lectornfc Fallback Hotspot
  //     password: HlobYi8l2xIN
  //     id: wifi_wifiap
  //     ap_timeout: 1min
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: LIGHT
  //   fast_connect: false
  //   networks:
  //   - ssid: LAJAQUERIA
  //     password: password
  //     id: wifi_wifiap_2
  //     priority: 0.0
  //   use_address: lectornfc.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("lectornfc.local");
  wifi::WiFiAP wifi_wifiap_2 = wifi::WiFiAP();
  wifi_wifiap_2.set_ssid("LAJAQUERIA");
  wifi_wifiap_2.set_password("password");
  wifi_wifiap_2.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap_2);
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("Lectornfc Fallback Hotspot");
  wifi_wifiap.set_password("HlobYi8l2xIN");
  wifi_wificomponent->set_ap(wifi_wifiap);
  wifi_wificomponent->set_ap_timeout(60000);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_LIGHT);
  wifi_wificomponent->set_fast_connect(false);
  App.register_component(wifi_wificomponent);
  // ota:
  //   password: <password>
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 3232
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(3232);
  ota_otacomponent->set_auth_password("<password>");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   password: <password>
  //   id: api_apiserver
  //   port: 6053
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("<password>");
  api_apiserver->set_reboot_timeout(900000);
  // spi:
  //   clk_pin:
  //     number: 18
  //     mode: OUTPUT
  //     inverted: false
  //   mosi_pin:
  //     number: 23
  //     mode: OUTPUT
  //     inverted: false
  //   miso_pin:
  //     number: 19
  //     mode: INPUT
  //     inverted: false
  //   id: spi_spicomponent
  spi_spicomponent = new spi::SPIComponent();
  App.register_component(spi_spicomponent);
  // rc522_spi:
  //   cs_pin:
  //     number: 15
  //     mode: OUTPUT
  //     inverted: false
  //   update_interval: 1s
  //   id: rc522_spi_rc522spi
  //   spi_id: spi_spicomponent
  rc522_spi_rc522spi = new rc522_spi::RC522Spi();
  rc522_spi_rc522spi->set_update_interval(1000);
  App.register_component(rc522_spi_rc522spi);
  spi_spicomponent->set_clk(new GPIOPin(18, OUTPUT, false));
  spi_spicomponent->set_miso(new GPIOPin(19, INPUT, false));
  rc522_spi_rc522spi->set_spi_parent(spi_spicomponent);
  spi_spicomponent->set_mosi(new GPIOPin(23, OUTPUT, false));
  rc522_spi_rc522spi->set_cs_pin(new GPIOPin(15, OUTPUT, false));
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  App.setup();
}

void loop() {
  App.loop();
}
