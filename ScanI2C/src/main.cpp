#include <Arduino.h>
#include <Wire.h>

int SDA_pin = D5;
int SCL_pin = D6;

void setup() {
  Wire.begin(SDA_pin, SCL_pin);
  Serial.begin(9600); 
}

void loop() {
  byte error, address;
  int nDevices;
  Serial.println("I2C Scanner. Scanning ...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C terbaca pada alamat 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");
      nDevices++;
    } else if (error == 4) {
      Serial.print("Ada error yang tidak diketahui pada alamat 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }    
  }
  if (nDevices == 0) {
    Serial.println("Tidak ada perangkat I2C ditemukan\n");
  } else {
    Serial.println("Selesai\n");
  }
  delay(5000);
}
