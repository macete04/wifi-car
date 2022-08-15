/*#include <Servo.h>

void Ultra_suoni_f();
//void Ultra_suoni_d();
//void Ultra_suoni_s();
//void servo();
int i = 0;

long Durata[3] = {0};
long Distanza[3] = {0};

/*void Ultra_suoni_f(){
  digitalWrite(TRIGGER, LOW);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  Durata[0] = pulseIn(ECHO, HIGH);
  Distanza[0] = 0.034 * Durata[0] / 2;
  if(Distanza[0] <= 30){
    Stop();
    client.publish("/ostacolo", String(false).c_str(), true);
  }
  client.publish("/Ultrasuoni", String(Distanza[0]).c_str(), true);
  return;
}*/
