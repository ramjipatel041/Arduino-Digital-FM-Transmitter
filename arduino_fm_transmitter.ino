#include <FMTX.h>
#include <SPI.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiSpi.h"


#define CS_PIN 7
#define RST_PIN 9
#define DC_PIN 8
#define Down_Key 15
#define UP_Key 14


float frequency = 87.0;
float tolerance = 0.001;


SSD1306AsciiSpi oled;


void setup() {
  fmtx_init(frequency, EUROPE);
  oled.begin(&Adafruit128x64, CS_PIN, DC_PIN, RST_PIN);
  oled.setFont(Adafruit5x7);


  pinMode(Down_Key, INPUT);
  pinMode(UP_Key, INPUT);


  oled.clear();
  oled.set2X();
  oled.println("   FM-TR   ");
  oled.setRow(3);
  oled.setCol(40);
  oled.set2X();
  fmtx_set_freq(frequency);
  oled.println(frequency, 1);
}


void loop() {
  if (digitalRead(Down_Key) == 0 && frequency > 87.0) {
    delay(130);
    frequency = frequency - 0.1;
    fmtx_set_freq(frequency);
    if (frequency < 100.0) {
      oled.setRow(3);
      oled.println("           ");
      oled.setRow(3);
      oled.setCol(40);
      oled.println(frequency, 1);
    }
    if ((frequency - 100.0) >= -tolerance) {
      oled.setRow(3);
      oled.println("           ");
      oled.setRow(3);
      oled.setCol(35);
      oled.println(frequency, 1);
    }
  }
  if (digitalRead(UP_Key) == 0 && frequency < 108.0) {
    delay(130);
    frequency = frequency + 0.1;
    fmtx_set_freq(frequency);
    if (frequency < 100.0) {
      oled.setRow(3);
      oled.println("           ");
      oled.setRow(3);
      oled.setCol(40);
      oled.println(frequency, 1);
    }
    if ((frequency - 100.0) >= -tolerance) {
      oled.setRow(3);
      oled.println("           ");
      oled.setRow(3);
      oled.setCol(35);
      oled.println(frequency, 1);
    }
  }
}