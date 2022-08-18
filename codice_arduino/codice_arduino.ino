#include <Servo.h>
#define MOTOR_PIN_D1 3  // right motor_1 pin
#define MOTOR_PIN_D2 9  // right motor_2 pin
#define MOTOR_PIN_S1 10 // lesft motor_1 pin
#define MOTOR_PIN_S2 11 // lesft motor_2 pin

#define SENSO_1_PIN_D1 5  // right motor_1 direction_1 pin
#define SENSO_2_PIN_D1 2  // right motor_1 direction_2 pin
#define SENSO_1_PIN_D2 4  // right motor_2 direction_1 pin
#define SENSO_2_PIN_D2 18 // right motor_2 direction_2 pin

#define SENSO_1_PIN_S1 17 // left motor_1 direction_1 pin
#define SENSO_2_PIN_S1 16 // left motor_1 direction_2 pin
#define SENSO_1_PIN_S2 15 // left motor_2 direction_1 pin
#define SENSO_2_PIN_S2 14 // left motor_2 direction_2 pin

#define AVANTI 13 // pin connected to pin D3 of the wemos board
#define STOP 12 // pin connected to pin D4 of the wemos board
#define INDIETRO 8 // pin connected to pin D5 of the wemos board
#define DESTRA 7 // pin connected to pin D6 of the wemos board
#define SINISTRA 6 // pin connected to pin D7 of the wemos board

#define M_STOP 0 // stop speed of the motors
#define VEL 127 // constant speed of the motors

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

  pinMode(SENSO_1_PIN_D1, OUTPUT);
  pinMode(SENSO_2_PIN_D1, OUTPUT);
  pinMode(SENSO_1_PIN_D2, OUTPUT);
  pinMode(SENSO_2_PIN_D2, OUTPUT);

  pinMode(SENSO_1_PIN_S1, OUTPUT);
  pinMode(SENSO_2_PIN_S1, OUTPUT);
  pinMode(SENSO_1_PIN_S2, OUTPUT);
  pinMode(SENSO_2_PIN_S2, OUTPUT);

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
}



void Stop(){
  analogWrite(MOTOR_PIN_D1, M_STOP);
  analogWrite(MOTOR_PIN_D2, M_STOP);
  analogWrite(MOTOR_PIN_S1, M_STOP);
  analogWrite(MOTOR_PIN_S2, M_STOP);
}

void indietro(){
  digitalWrite(SENSO_2_PIN_D1, HIGH);
  digitalWrite(SENSO_2_PIN_D2, LOW);
  digitalWrite(SENSO_2_PIN_S1, LOW);
 digitalWrite(SENSO_2_PIN_S2, HIGH);

  digitalWrite(SENSO_1_PIN_D1, LOW);
  digitalWrite(SENSO_1_PIN_D2, HIGH);
  digitalWrite(SENSO_1_PIN_S1, HIGH);
  digitalWrite(SENSO_1_PIN_S2, LOW);
  
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}

void sinistra(){
  digitalWrite(SENSO_2_PIN_D1, LOW);
  digitalWrite(SENSO_2_PIN_D2, HIGH);
  digitalWrite(SENSO_2_PIN_S1, LOW);
  digitalWrite(SENSO_2_PIN_S2, HIGH);

  digitalWrite(SENSO_1_PIN_D1, HIGH);
  digitalWrite(SENSO_1_PIN_D2, LOW);
  digitalWrite(SENSO_1_PIN_S1, HIGH);
  digitalWrite(SENSO_1_PIN_S2, LOW);
  
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}

void destra(){
  digitalWrite(SENSO_2_PIN_D1, HIGH);
  digitalWrite(SENSO_2_PIN_D2, LOW);
  digitalWrite(SENSO_2_PIN_S1, HIGH);
  digitalWrite(SENSO_2_PIN_S2, LOW);

  digitalWrite(SENSO_1_PIN_D1, LOW);
  digitalWrite(SENSO_1_PIN_D2, HIGH);
  digitalWrite(SENSO_1_PIN_S1, LOW);
  digitalWrite(SENSO_1_PIN_S2, HIGH);
  
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}
void dritto(){
  digitalWrite(SENSO_2_PIN_D1, LOW);
  digitalWrite(SENSO_2_PIN_D2, HIGH);
  digitalWrite(SENSO_2_PIN_S1, HIGH);
  digitalWrite(SENSO_2_PIN_S2, LOW);

  digitalWrite(SENSO_1_PIN_D1, HIGH);
  digitalWrite(SENSO_1_PIN_D2, LOW);
  digitalWrite(SENSO_1_PIN_S1, LOW);
  digitalWrite(SENSO_1_PIN_S2, HIGH);
  
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}
