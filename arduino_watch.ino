
#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

RTC_DS1307 RTC;
char monthString[37]= {"JanFebMarAprMayJunJulAugSepOctNovDec"};
int  monthIndex[122] ={0,3,6,9,12,15,18,21,24,27,30,33};

void setup() {
  Wire.begin();
  RTC.begin(); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.clearDisplay();
}


void loop() {
  DateTime now = RTC.now();
  display.setTextSize(2);
  display.setCursor(20,0);
  display.print(now.hour(), DEC);
  printDigits(now.minute());
  printDigits(now.second());
  display.setTextSize(1);
  display.setCursor(32,15);
  display.print(now.day(), DEC);
  printDigits(now.month());
  printDigits(now.year());
  display.display();
  delay(100);
  display.clearDisplay();

}
void printDigits(int digits){
  display.print(":");
  if(digits < 10)
    display.print('0');
    display.print(digits);
  }
