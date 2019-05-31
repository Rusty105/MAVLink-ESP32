#include <Arduino.h>
#include <SSD1306.h>
#include <SPI.h>
#include <Wire.h>
// #include <LoRa.h>

/**************** DEFINITIONS *****************/
#define TTGO // Using TTGO ESP32 LoRa Board
#define TELEMETRY_SPEED 57600 // port speed for Telemetry

#define OLED_SDA 4
#define OLED_SCL 15
#define OLED_RST 16
#define LED 2
#define LORA_BAND 915 //

SSD1306 display(0x3c, OLED_SDA, OLED_SCL);

 /*
// Definitions for LoRa SX 1278
#define SCK 5 // GPIO5 - SX1278's SCK
#define MISO 19 // GPIO19 - SX1278's MISO
#define MOSI 27 // GPIO27 - SX1278's MOSI
#define SS 18 // GPIO18 - SX1278's CS
#define RST 14 // GPIO14 - SX1278's RESET
#define DI0 26 // GPIO26 - SX1278's IRQ (interrupt request)
*/


void display_draw() {
display.clear();
display.setFont (ArialMT_Plain_10);
display.setTextAlignment (TEXT_ALIGN_LEFT);
display.drawString (0, 0, "Testing again");
display.display();

}  // display_draw

void setup() {
// Configure OLED by setting the OLED Reset HIGH, LOW, and then back HIGH
pinMode(OLED_RST, OUTPUT);
digitalWrite(OLED_RST, HIGH);
delay(100);
digitalWrite(OLED_RST, LOW);
delay(100);
digitalWrite(OLED_RST, HIGH);
display.init();
display.flipScreenVertically();

display.clear();
display.setFont (ArialMT_Plain_10);
display.setTextAlignment (TEXT_ALIGN_LEFT);
display.drawString (0, 0, "MAVLink Reader");
delay(4000);
display.display();

pinMode(LED, OUTPUT);
} // setup

void loop() {
/*  display.clear();
  display.setFont (ArialMT_Plain_10);
  display.setTextAlignment (TEXT_ALIGN_LEFT);
  display.drawString (0, 0, "Testing");
  display.display();
  */
  // toggle the led to give a visual indication the packet was sent
digitalWrite(LED, HIGH);
delay(250);
digitalWrite(LED, LOW);
delay(250);
display_draw();
} // loop
