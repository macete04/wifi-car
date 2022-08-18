#include <SoftwareSerial.h>

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

#define SOFTRX 7
#define SOFTTX 8

#define M_STOP 0

SoftwareSerial serial2(SOFTRX, SOFTTX);

void indietro(int);
void dritto(int);
void destra(int);
void sinistra(int);
//void Stop();

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

  pinMode(SOFTRX, INPUT);
  pinMode(SOFTTX, OUTPUT);

  delay(2000);
  
  Serial.begin(57600);
  serial2.begin(57600);

  delay(2000);
}

void loop() {
  if(serial2.available()){
    int vel = serial2.read(); 
    if(serial2.read() == "avanti"){
    dritto(vel);
    }else{
      if(serial2.read() == "indietro"){
        indietro(vel);
      }
    }
    if(serial2.read() == "destra"){
      destra(vel);
    }else{
      if(serial2.read() == "indietro"){
        sinistra(vel);
      }
    }
  }
}



/*void Stop(){
  analogWrite(MOTOR_PIN_D1, M_STOP);
  analogWrite(MOTOR_PIN_D2, M_STOP);
  analogWrite(MOTOR_PIN_S1, M_STOP);
  analogWrite(MOTOR_PIN_S2, M_STOP);
}*/

void indietro(int vel){
  digitalWrite(SENSO_I_PIN_D1, HIGH);
  digitalWrite(SENSO_I_PIN_D2, LOW);
  digitalWrite(SENSO_I_PIN_S1, LOW);
 digitalWrite(SENSO_I_PIN_S2, HIGH);

  digitalWrite(SENSO_A_PIN_D1, LOW);
  digitalWrite(SENSO_A_PIN_D2, HIGH);
  digitalWrite(SENSO_A_PIN_S1, HIGH);
  digitalWrite(SENSO_A_PIN_S2, LOW);
  
  analogWrite(MOTOR_PIN_D1, vel);
  analogWrite(MOTOR_PIN_D2, vel);
  analogWrite(MOTOR_PIN_S1, vel);
  analogWrite(MOTOR_PIN_S2, vel);
}

void sinistra(int vel){
  digitalWrite(SENSO_I_PIN_D1, LOW);
  digitalWrite(SENSO_I_PIN_D2, HIGH);
  digitalWrite(SENSO_I_PIN_S1, LOW);
  digitalWrite(SENSO_I_PIN_S2, HIGH);

  digitalWrite(SENSO_A_PIN_D1, HIGH);
  digitalWrite(SENSO_A_PIN_D2, LOW);
  digitalWrite(SENSO_A_PIN_S1, HIGH);
  digitalWrite(SENSO_A_PIN_S2, LOW);
  
  analogWrite(MOTOR_PIN_D1, vel);
  analogWrite(MOTOR_PIN_D2, vel);
  analogWrite(MOTOR_PIN_S1, vel);
  analogWrite(MOTOR_PIN_S2, vel);
}

void destra(int vel){
  digitalWrite(SENSO_I_PIN_D1, HIGH);
  digitalWrite(SENSO_I_PIN_D2, LOW);
  digitalWrite(SENSO_I_PIN_S1, HIGH);
  digitalWrite(SENSO_I_PIN_S2, LOW);

  digitalWrite(SENSO_A_PIN_D1, LOW);
  digitalWrite(SENSO_A_PIN_D2, HIGH);
  digitalWrite(SENSO_A_PIN_S1, LOW);
  digitalWrite(SENSO_A_PIN_S2, HIGH);
  
  analogWrite(MOTOR_PIN_D1, vel);
  analogWrite(MOTOR_PIN_D2, vel);
  analogWrite(MOTOR_PIN_S1, vel);
  analogWrite(MOTOR_PIN_S2, vel);
}
void dritto(int vel){
  digitalWrite(SENSO_I_PIN_D1, LOW);
  digitalWrite(SENSO_I_PIN_D2, HIGH);
  digitalWrite(SENSO_I_PIN_S1, HIGH);
  digitalWrite(SENSO_I_PIN_S2, LOW);

  digitalWrite(SENSO_A_PIN_D1, HIGH);
  digitalWrite(SENSO_A_PIN_D2, LOW);
  digitalWrite(SENSO_A_PIN_S1, LOW);
  digitalWrite(SENSO_A_PIN_S2, HIGH);
  
  analogWrite(MOTOR_PIN_D1, vel);
  analogWrite(MOTOR_PIN_D2, vel);
  analogWrite(MOTOR_PIN_S1, vel);
  analogWrite(MOTOR_PIN_S2, vel);
}
