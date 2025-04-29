#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 26, 2);
int SDA_pin = D5;
int SCL_pin = D6;

void setup() {
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Assalamu'alaikum Warahmatullahi Wabarakatuh");
  lcd.setCursor(0, 1);
  lcd.print("Selamat datang di I2C Scanner");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(300);
}
