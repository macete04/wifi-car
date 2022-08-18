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
  if(debug == true){
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  }
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if(debug == true){
      Serial.print(".");
    }
  }

  randomSeed(micros());
  if(debug == true){
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  if(debug == true){
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
  }
  String msg;
  for (int i = 0; i < length; i++) {
    msg +=(char)payload[i];
  }
  if(debug == true){
    Serial.println(msg);
  }

  if(strcmp(topic, "/movimento") == 0){
    int vel = map(payload.distanza, 0.0, 100.0, 0, 255);
    Serial.println(vel);
    if(payload.direzione == "destra"){
      Serial.println("destra");
    }else{
      if(payload.direzione == "sinstra"){
        Serial.println("sinistra");
      }
    }
    if(payload.verso == "avanti"){
      Serial.println("avanti");
    }else{
      if(payload.verso == "indietro"){
        Serial.println("indietro");
      }
    }
  } 
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    if(debug == true){
      Serial.print("Attempting MQTT connection...");
    }
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect("macchinina",  mqtt_us, mqtt_pass)) {
      if(debug == true){
        Serial.println("connected");
      }
      // Once connected, publish an announcement...
      // ... and resubscribe
      client.subscribe("/movimento");
      client.subscribe("/ostacolo");
      client.subscribe("/Ultrasuoni");
    } else {
      if(debug == true){
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
      }
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
