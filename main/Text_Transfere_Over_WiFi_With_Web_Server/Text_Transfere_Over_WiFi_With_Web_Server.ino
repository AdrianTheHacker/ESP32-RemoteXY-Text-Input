#include <WiFi.h>


const char* ssid = "ESP32's WiFi Access Point";
const char* password = "Password";

WiFiServer server(80);
String header;

void setup() {
  Serial.begin(9600);

  Serial.println("Setting Up AP");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("Access Point IP Address: ");
  Serial.println(IP);

  server.begin();
}

void loop() {
  listenForClient();
}

void listenForClient() {
  // Shows webpage for user
  // In Future it'll the message which will be displayed on the LCD Screen.

  WiFiClient client = server.available();
  if(client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println("Connection: close");
    client.println();
    Serial.println("New Client.");
    client.println("<!DOCTYPE html><html><h1>Hello, World!</h1></html>");
  }
}