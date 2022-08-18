void avanti(bool);  // forward function prototype, serves to move straight
void indietro(bool);  // back function prototype, serves to make go back
void destra(bool);  // right function prototype, serves to make it go right
void sinistra(bool);  // left function prototype, serves to make left go
void Stop(bool);  // stop function prototype, it is used to make it stop
void Setup_M(); // Setup_M function prototype, it is used to initialize the motors in one direction and with one speed

void Setup_M(){
  digitalWrite(AVANTI, LOW);
  digitalWrite(STOP, HIGH);
  digitalWrite(INDIETRO, LOW);
  digitalWrite(DESTRA, LOW);
  digitalWrite(SINISTRA, LOW);
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
