//#define ECHO 5
//#define TRIGGER 6
#define SOFTRX D6
#define SOFTTX D3

//Servo servo1;

WiFiClient espClient;
PubSubClient client(espClient);

SoftwareSerial serial2(SOFTRX, SOFTTX);

const bool debug = false;
