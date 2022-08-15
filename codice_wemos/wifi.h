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
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  bool stato_avanti = true;
  bool stato_indietro = true;
  bool stato_destra = true;
  bool stato_sinistra = true;
  bool stato_Stop = true;
  String msg;
  for (int i = 0; i < length; i++) {
    msg +=(char)payload[i];
  }
  Serial.println(msg);

  if(strcmp(topic, "/avanti") == 0){
    if(msg == "true"){
      avanti(stato_avanti);
    }else{
      avanti(!stato_avanti);
    }
  }
  if(strcmp(topic, "/indietro") == 0){
    if(msg == "true"){
      indietro(stato_indietro);
    }else{
      indietro(!stato_indietro);
    }
  }
  if(strcmp(topic, "/destra") == 0){
    if(msg == "true"){
      destra(stato_destra);
    }else{
      destra(!stato_destra);
    }
  }
  if(strcmp(topic, "/sinistra") == 0){
    if(msg == "true"){
      sinistra(stato_sinistra);
    }else{
      sinistra(!stato_sinistra);
    }
  }
  if(strcmp(topic, "/stop") == 0){
    if(msg == "true"){
      Stop(stato_Stop);
    }else{
      Stop(!stato_Stop);
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect("macchinina",  mqtt_us, mqtt_pass)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      // ... and resubscribe
      client.subscribe("/avanti");
      client.subscribe("/indietro");
      client.subscribe("/destra");
      client.subscribe("/sinistra");
      client.subscribe("/ostacolo");
      client.subscribe("/Ultrasuoni");
      client.subscribe("/stop");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
