// inclusion of libraries and files
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "costanti.h"
#include "motori.h"
#include "wifi.h"
// inclusion of libraries and files

void setup() {
  Serial.begin(115200); // initialization of the serial
  // pin mode setting
  pinMode(AVANTI, OUTPUT);
  pinMode(STOP, OUTPUT);
  pinMode(INDIETRO, OUTPUT);
  pinMode(DESTRA, OUTPUT);
  pinMode(SINISTRA, OUTPUT);
  // pin mode setting
  
  setup_wifi(); // function call for wifi
  client.setServer(mqtt_server, 1883);  // setting the mqtt server to connect to
  client.setCallback(callback); // setting the function to be performed when the server receives a message
  Setup_M();  // call of the function for the standard predisposition of the motors
}

void loop() {
  if (!client.connected()) {  // check if the card is connected to the mqtt server if it is not connected
    reconnect();
  }
  client.loop();  // function necessary for the operation of mqtt communication
  
}
