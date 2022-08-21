const char* ssid = "";
const char* password = "";
const char* mqtt_server = "";
const char* mqtt_us = "";
const char* mqtt_pass = "";

unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void callback(char* topic, byte* payload, unsigned int length);
void setup_wifi();
void riconnessione();

void setup_wifi() {
  delay(10);
  if (debug == true) {
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
  }
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (debug == true) {
      Serial.print(".");
    }
  }

  randomSeed(micros());
  if (debug == true) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  if (debug == true) {
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
  }
  String msg;
  String dir;
  String ver;
  byte e;
  int primo_numero;
  int secondo_numero;
  int terzo_numero;
  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }
  for (int i = 14; i < 17; i++) {
    dir += msg[i];
  }
  for (int i = 45; i < 48; i++) {
    int a = bitRead(msg[i], 0);
    int b = bitRead(msg[i], 1);
    int c = bitRead(msg[i], 2);
    int d = bitRead(msg[i], 3);
    if(a == 1){
      bitSet(e, 0);
    }
    if(b == 1){
      bitSet(e, 1);
    }
    if(c == 1){
      bitSet(e, 2);
    }
    if(d == 1){
      bitSet(e, 3);
    }
    switch(i){
      case 45:
        primo_numero = e *100;
        break;
      case 46:
        secondo_numero = e *10;
        break;
      case 47:
        terzo_numero = e;
        break;
    }
    e = 0;
  }
  int vel = primo_numero + secondo_numero + terzo_numero;
  for (int i = 28; i < 31; i++) {
    ver += msg[i];
  }

  if (debug == true) {
    Serial.println(msg);
    Serial.println(ver);
    Serial.println(vel);
    Serial.println(dir);
  }

  if (strcmp(topic, "/movimento") == 0) {
    
    serial2.write(vel);
    //Serial.println(vel);
    delay(10);
    if (dir == "des") {
      int right = 103;
      //serial2.write(right);
      //Serial.println(right);
      delay(10);
    } else {
      if (dir == "sin") {
        int left = 104;
        //serial2.write(left);
        //Serial.println(left);
        delay(10);
      }
    }
    if (ver == "ava") {
      int forward = 101;
      serial2.write(forward);
      //Serial.println(forward);
      delay(10);
    } else {
      if (ver == "ind") {
        int back = 102;
        serial2.write(back);
        //Serial.println(back);
        delay(10);
      }
    }
  }
}

void riconnessione() {
  // Loop until we're reconnected
  while (!client.connected()) {
    if (debug == true) {
      Serial.print("Attempting MQTT connection...");
    }
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect("",  mqtt_us, mqtt_pass)) {
      if (debug == true) {
        Serial.println("connected");
      }
      // Once connected, publish an announcement...
      // ... and resubscribe
      client.subscribe("/movimento");
      client.subscribe("/ostacolo");
      client.subscribe("/Ultrasuoni");
    } else {
      if (debug == true) {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
      }
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
