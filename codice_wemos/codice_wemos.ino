/*
 Basic ESP8266 MQTT example
 This sketch demonstrates the capabilities of the pubsub library in combination
 with the ESP8266 board/library.
 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic" every two seconds
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary
  - If the first character of the topic "inTopic" is an 1, switch ON the ESP Led,
    else switch it off
 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.
 To install the ESP8266 board, (using Arduino 1.6.4+):
  - Add the following 3rd party board manager under "File -> Preferences -> Additional Boards Manager URLs":
       http://arduino.esp8266.com/stable/package_esp8266com_index.json
  - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
  - Select your ESP8266 in "Tools -> Board"
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "costanti.h"
#include "motori.h"
#include "wifi.h"
#include "sensori.h"

void setup() {
  Serial.begin(115200);
  pinMode(AVANTI, OUTPUT);
  pinMode(STOP, OUTPUT);
  pinMode(INDIETRO, OUTPUT);
  pinMode(DESTRA, OUTPUT);
  pinMode(SINISTRA, OUTPUT);
  //pinMode(ECHO, INPUT);
  //pinMode(TRIGGER, OUTPUT);
  //servo1.attach(A5);
    
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  Setup_M();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
}
