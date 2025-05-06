#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "realme narzo 20";
const char* password = "jendela00";

ESP8266WebServer server(80);
String webpage;

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(D0, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);

  // Nyambungin ke Wifi
  Serial.println();
  Serial.println("Konfigurasi Akses Poin...");

  // Mengatur Wifi
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  // Print Status Koneksi
  Serial.println("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Isi dari Webpage
  webpage += "<h1>ESP8266 Web Kontrol Ini punya Luthfi</h1>";
  webpage += "<>LED 1 : ";
  webpage += "<a href=\"/LED1on\"><button>ON</button></a><a href=\"/LED1off\"><button>OFF</button></a></p><br>";
  webpage += "<>LED 2 : ";
  webpage += "<a href=\"/LED2on\"><button>ON</button></a><a href=\"/LED2off\"><button>OFF</button></a></p><br>";
  webpage += "<>LED 3 : ";
  webpage += "<a href=\"/LED3on\"><button>ON</button></a><a href=\"/LED3off\"><button>OFF</button></a></p><br>";

  // Membuat Tampilan Web
  server.on("/", []() {
    server.send(200, "text/html", webpage);
  });

  // Bagian ini untuk Merespon Perintah yang Masuk
  // LED 1
  server.on("/LED1on", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D0, HIGH);
    delay(1000);
  });

  // LED 2
  server.on("/LED2on", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D2, HIGH);
    delay(1000);
  });

  // LED 3
  server.on("/LED3on", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D3, HIGH);
    delay(1000);
  });

  // LED 1 OFF
  server.on("/LED1off", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D0, LOW);
    delay(1000);
  });

  // LED 2 OFF
  server.on("/LED2off", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D2, LOW);
    delay(1000);
  });

  // LED 3 OFF
  server.on("/LED3off", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D3, LOW);
    delay(1000);
  });

  server.begin();
  Serial.println("Web Server dijalankan");

}

void loop() {
  server.handleClient();
}
