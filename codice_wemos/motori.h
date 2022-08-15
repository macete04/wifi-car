void avanti(bool);
void indietro(bool);
void destra(bool);
void sinistra(bool);
void Stop(bool);
void Setup_M();

void Setup_M(){
  digitalWrite(AVANTI, LOW);
  digitalWrite(STOP, HIGH);
  digitalWrite(INDIETRO, LOW);
  digitalWrite(DESTRA, LOW);
  digitalWrite(SINISTRA, LOW);
  client.publish("/ostacolo", String(false).c_str(), true);
}
void Stop(bool msg){
  digitalWrite(STOP, msg);
}

void avanti(bool msg){
  digitalWrite(AVANTI, msg);
}

void indietro(bool msg){
  digitalWrite(INDIETRO, msg);
}

void destra(bool msg){
  digitalWrite(DESTRA, msg);
}

void sinistra(bool msg){
  digitalWrite(SINISTRA, msg);
}
