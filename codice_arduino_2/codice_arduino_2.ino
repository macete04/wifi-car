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

SoftwareSerial serial2(SOFTRX, SOFTTX);

void indietro();
void dritto();
void destra();
void sinistra();
void v_motor(int);

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

  Serial.begin(9600);
  serial2.begin(9600);

  delay(2000);
}

void loop() {
  int msg;
  while (serial2.available()) {
    msg = serial2.read();
    //Serial.println(msg);
    if (msg >= 0 && msg <= 100) {
      int vel = map(msg, 0, 100, 0, 255);
      v_motor(vel);
    } else {
      switch (msg) {
        case 101:
          dritto();
          break;
        case 102:
          indietro();
          break;
        case 103:
          destra();
          break;
        case 104:
          sinistra();
          break;
        default:
          break;
      }
    }
  }
}



void v_motor(int vel) {
  analogWrite(MOTOR_PIN_D1, vel);
  analogWrite(MOTOR_PIN_D2, vel);
  analogWrite(MOTOR_PIN_S1, vel);
  analogWrite(MOTOR_PIN_S2, vel);
  //Serial.println(serial2.read());
}

void indietro() {
  //Serial.println("indietro");
  digitalWrite(SENSO_I_PIN_D1, HIGH);
  digitalWrite(SENSO_I_PIN_D2, LOW);
  digitalWrite(SENSO_I_PIN_S1, LOW);
  digitalWrite(SENSO_I_PIN_S2, HIGH);

  digitalWrite(SENSO_A_PIN_D1, LOW);
  digitalWrite(SENSO_A_PIN_D2, HIGH);
  digitalWrite(SENSO_A_PIN_S1, HIGH);
  digitalWrite(SENSO_A_PIN_S2, LOW);
}

void sinistra() {
  digitalWrite(SENSO_I_PIN_D1, LOW);
  digitalWrite(SENSO_I_PIN_D2, HIGH);
  digitalWrite(SENSO_I_PIN_S1, LOW);
  digitalWrite(SENSO_I_PIN_S2, HIGH);

  digitalWrite(SENSO_A_PIN_D1, HIGH);
  digitalWrite(SENSO_A_PIN_D2, LOW);
  digitalWrite(SENSO_A_PIN_S1, HIGH);
  digitalWrite(SENSO_A_PIN_S2, LOW);
}

void destra() {
  digitalWrite(SENSO_I_PIN_D1, HIGH);
  digitalWrite(SENSO_I_PIN_D2, LOW);
  digitalWrite(SENSO_I_PIN_S1, HIGH);
  digitalWrite(SENSO_I_PIN_S2, LOW);

  digitalWrite(SENSO_A_PIN_D1, LOW);
  digitalWrite(SENSO_A_PIN_D2, HIGH);
  digitalWrite(SENSO_A_PIN_S1, LOW);
  digitalWrite(SENSO_A_PIN_S2, HIGH);

}
void dritto() {
  //Serial.println("dritto");
  digitalWrite(SENSO_I_PIN_D1, LOW);
  digitalWrite(SENSO_I_PIN_D2, HIGH);
  digitalWrite(SENSO_I_PIN_S1, HIGH);
  digitalWrite(SENSO_I_PIN_S2, LOW);

  digitalWrite(SENSO_A_PIN_D1, HIGH);
  digitalWrite(SENSO_A_PIN_D2, LOW);
  digitalWrite(SENSO_A_PIN_S1, LOW);
  digitalWrite(SENSO_A_PIN_S2, HIGH);
}
