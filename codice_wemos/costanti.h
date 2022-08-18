#define AVANTI D3 // pin connected to pin 13 of the arduino board
#define STOP D4 // pin connected to pin 12 of the arduino board
#define INDIETRO D5 // pin connected to pin 8 of the arduino board
#define DESTRA D6 // pin connected to pin 7 of the arduino board
#define SINISTRA D7 // pin connected to pin 6 of the arduino board
// information of WiFi networks and the mqtt server
const char* ssid = "";
const char* password = "";
const char* mqtt_server = "";
const char* mqtt_us = "";
const char* mqtt_pass = "";
//information of WiFi networks and the mqtt server
WiFiClient espClient; // creation of the internet client
PubSubClient client(espClient); // client assignment to mqtt communication
