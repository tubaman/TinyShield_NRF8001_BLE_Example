#define BLE_DEBUG 1

#include "SPI.h"
#include "lib_aci.h"
#include "aci_setup.h"
#include "uart_over_ble.h"
#include "services.h"

uint8_t ble_rx_buffer[21];
uint8_t ble_rx_buffer_len = 0;

//when using this project in the Arduino IDE, delete the following include and rename UART.h to UART.ino

void setup(void)
{
  Serial.begin(115200);
  BLEsetup();
}

void loop() {
  aci_loop();//Process any ACI commands or events
  
  if(ble_rx_buffer_len){
    Serial.println(ble_rx_buffer_len);
    Serial.println((char*)ble_rx_buffer);
    uint8_t sendBuffer[20]="Test";
    uint8_t length=5;
    lib_aci_send_data(PIPE_UART_OVER_BTLE_UART_TX_TX, sendBuffer, length);
    ble_rx_buffer_len=0;
  }

}
