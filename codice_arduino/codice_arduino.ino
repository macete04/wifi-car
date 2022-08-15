#include <Servo.h>
#define MOTOR_PIN_D1 3
#define MOTOR_PIN_D2 9
#define MOTOR_PIN_S1 10
#define MOTOR_PIN_S2 11

#define SENSO_A_PIN_D1 5
#define SENSO_I_PIN_D1 2
#define SENSO_A_PIN_D2 4
#define SENSO_I_PIN_D2 18

#define SENSO_A_PIN_S1 17
#define SENSO_I_PIN_S1 16
#define SENSO_A_PIN_S2 15
#define SENSO_I_PIN_S2 14

#define AVANTI 13
#define STOP 12
#define INDIETRO 8
#define DESTRA 7
#define SINISTRA 6

#define M_STOP 0
#define VEL 127

  bool av = LOW;
  bool in = LOW;
  bool de = LOW;
  bool si = LOW;
  bool s = LOW;

void indietro();
void dritto();
void destra();
void sinistra();
void Stop();

void setup() {
  pinMode(MOTOR_PIN_D1, OUTPUT);
  pinMode(MOTOR_PIN_D2, OUTPUT);
  pinMode(MOTOR_PIN_S1, OUTPUT);
  pinMode(MOTOR_PIN_S2, OUTPUT);

  pinMode(SENSO_A_PIN_D1, OUTPUT);
  pinMode(SENSO_I_PIN_D1, OUTPUT);
  pinMode(SENSO_A_PIN_D2, OUTPUT);
  pinMode(SENSO_I_PIN_D2, OUTPUT);

  pinMode(SENSO_A_PIN_S1, OUTPUT);
  pinMode(SENSO_I_PIN_S1, OUTPUT);
  pinMode(SENSO_A_PIN_S2, OUTPUT);
  pinMode(SENSO_I_PIN_S2, OUTPUT);

  pinMode(AVANTI, INPUT);
  pinMode(STOP, INPUT);
  pinMode(INDIETRO, INPUT);
  pinMode(DESTRA, INPUT);
  pinMode(SINISTRA, INPUT);

  Serial.begin(9600);
}

void loop() {
  av = digitalRead(AVANTI);
  s = digitalRead(STOP);
  in = digitalRead(INDIETRO);
  de = digitalRead(DESTRA);
  si = digitalRead(SINISTRA);

  if(av == HIGH){
    dritto();
  }
  if(s == HIGH){
    Stop();
  }
  if(de == HIGH){
    destra();
  }
  if(si == HIGH){
    sinistra();
  }
  if(in == HIGH){
    indietro();
  }
  /*int i = 0;
  while(i < 1){
    dritto();
    i++;
    //Serial.println(i);
  }
  delay(5000);
  Stop();
  delay(5000);
  i = 0;
  while(i < 1){
    indietro();
    i++;
    //Serial.println(i);
  }
  delay(5000);
  Stop();
  delay(5000);
  i = 0;
  while(i < 1){
    destra();
    i++;
  }
  delay(5000);
  Stop();
  delay(5000);
  i = 0;
  while(i < 1){
    sinistra();
    i++;
  }
  delay(5000);
  Stop();
  delay(5000);
  i = 0;*/
}



void Stop(){
  analogWrite(MOTOR_PIN_D1, M_STOP);
  analogWrite(MOTOR_PIN_D2, M_STOP);
  analogWrite(MOTOR_PIN_S1, M_STOP);
  analogWrite(MOTOR_PIN_S2, M_STOP);
}

void indietro(){
  digitalWrite(SENSO_I_PIN_D1, HIGH);
  digitalWrite(SENSO_I_PIN_D2, LOW);
  digitalWrite(SENSO_I_PIN_S1, LOW);
 digitalWrite(SENSO_I_PIN_S2, HIGH);

  digitalWrite(SENSO_A_PIN_D1, LOW);
  digitalWrite(SENSO_A_PIN_D2, HIGH);
  digitalWrite(SENSO_A_PIN_S1, HIGH);
  digitalWrite(SENSO_A_PIN_S2, LOW);
  
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}

void sinistra(){
  digitalWrite(SENSO_I_PIN_D1, LOW);
  digitalWrite(SENSO_I_PIN_D2, HIGH);
  digitalWrite(SENSO_I_PIN_S1, LOW);
  digitalWrite(SENSO_I_PIN_S2, HIGH);

  digitalWrite(SENSO_A_PIN_D1, HIGH);
  digitalWrite(SENSO_A_PIN_D2, LOW);
  digitalWrite(SENSO_A_PIN_S1, HIGH);
  digitalWrite(SENSO_A_PIN_S2, LOW);
  
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}

void destra(){
  digitalWrite(SENSO_I_PIN_D1, HIGH);
  digitalWrite(SENSO_I_PIN_D2, LOW);
  digitalWrite(SENSO_I_PIN_S1, HIGH);
  digitalWrite(SENSO_I_PIN_S2, LOW);

  digitalWrite(SENSO_A_PIN_D1, LOW);
  digitalWrite(SENSO_A_PIN_D2, HIGH);
  digitalWrite(SENSO_A_PIN_S1, LOW);
  digitalWrite(SENSO_A_PIN_S2, HIGH);
  
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}
void dritto(){
  digitalWrite(SENSO_I_PIN_D1, LOW);
  digitalWrite(SENSO_I_PIN_D2, HIGH);
  digitalWrite(SENSO_I_PIN_S1, HIGH);
  digitalWrite(SENSO_I_PIN_S2, LOW);

  digitalWrite(SENSO_A_PIN_D1, HIGH);
  digitalWrite(SENSO_A_PIN_D2, LOW);
  digitalWrite(SENSO_A_PIN_S1, LOW);
  digitalWrite(SENSO_A_PIN_S2, HIGH);
  
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}
