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

  bool av = LOW; // variable for wemos signal reception
  bool in = LOW; // variable for wemos signal reception
  bool de = LOW; // variable for wemos signal reception
  bool si = LOW; // variable for wemos signal reception
  bool s = LOW; // variable for wemos signal reception

void indietro();  // function prototype back, serves to make go back
void dritto();  // straight function prototype, serves to move forward
void destra();  // right function prototype, serves to make it go right
void sinistra();  // left function prototype, serves to make left go
void Stop();  // stop function prototype, it is used to make it stop

void setup() {
  // pin mode setting
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
  // pin mode setting

  Serial.begin(9600); // initialization of the serial
}

void loop() {
  //polling function for reading the signals received from the wemos card
  av = digitalRead(AVANTI); 
  s = digitalRead(STOP);
  in = digitalRead(INDIETRO);
  de = digitalRead(DESTRA);
  si = digitalRead(SINISTRA);
  //polling function for reading the signals received from the wemos card

  if(av == HIGH){
    dritto(); // call of the function if the signal is positive
  }
  if(s == HIGH){
    Stop(); // call of the function if the signal is positive
  }
  if(de == HIGH){
    destra(); // call of the function if the signal is positive
  }
  if(si == HIGH){
    sinistra(); // call of the function if the signal is positive
  }
  if(in == HIGH){
    indietro(); // call of the function if the signal is positive
  }
}



void Stop(){//speed setting = 0 on the motors
  analogWrite(MOTOR_PIN_D1, M_STOP);
  analogWrite(MOTOR_PIN_D2, M_STOP);
  analogWrite(MOTOR_PIN_S1, M_STOP);
  analogWrite(MOTOR_PIN_S2, M_STOP);
}

void indietro(){
  // setting of the running direction of the motors
  digitalWrite(SENSO_2_PIN_D1, HIGH);
  digitalWrite(SENSO_2_PIN_D2, LOW);
  digitalWrite(SENSO_2_PIN_S1, LOW);
  digitalWrite(SENSO_2_PIN_S2, HIGH);
  
  digitalWrite(SENSO_1_PIN_D1, LOW);
  digitalWrite(SENSO_1_PIN_D2, HIGH);
  digitalWrite(SENSO_1_PIN_S1, HIGH);
  digitalWrite(SENSO_1_PIN_S2, LOW);
  // setting of the running direction of the motors
  // speed setting = 127 on motors
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}

void sinistra(){
  // setting of the running direction of the motors
  digitalWrite(SENSO_2_PIN_D1, LOW);
  digitalWrite(SENSO_2_PIN_D2, HIGH);
  digitalWrite(SENSO_2_PIN_S1, LOW);
  digitalWrite(SENSO_2_PIN_S2, HIGH);

  digitalWrite(SENSO_1_PIN_D1, HIGH);
  digitalWrite(SENSO_1_PIN_D2, LOW);
  digitalWrite(SENSO_1_PIN_S1, HIGH);
  digitalWrite(SENSO_1_PIN_S2, LOW);
  // setting of the running direction of the motors
  // speed setting = 127 on motors
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}

void destra(){
  // setting of the running direction of the motors
  digitalWrite(SENSO_2_PIN_D1, HIGH);
  digitalWrite(SENSO_2_PIN_D2, LOW);
  digitalWrite(SENSO_2_PIN_S1, HIGH);
  digitalWrite(SENSO_2_PIN_S2, LOW);

  digitalWrite(SENSO_1_PIN_D1, LOW);
  digitalWrite(SENSO_1_PIN_D2, HIGH);
  digitalWrite(SENSO_1_PIN_S1, LOW);
  digitalWrite(SENSO_1_PIN_S2, HIGH);
  // setting of the running direction of the motors
  // speed setting = 127 on motors
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}
void dritto(){
  // setting of the running direction of the motors
  digitalWrite(SENSO_2_PIN_D1, LOW);
  digitalWrite(SENSO_2_PIN_D2, HIGH);
  digitalWrite(SENSO_2_PIN_S1, HIGH);
  digitalWrite(SENSO_2_PIN_S2, LOW);

  digitalWrite(SENSO_1_PIN_D1, HIGH);
  digitalWrite(SENSO_1_PIN_D2, LOW);
  digitalWrite(SENSO_1_PIN_S1, LOW);
  digitalWrite(SENSO_1_PIN_S2, HIGH);
  // setting of the running direction of the motors
  // speed setting = 127 on motors
  analogWrite(MOTOR_PIN_D1, VEL);
  analogWrite(MOTOR_PIN_D2, VEL);
  analogWrite(MOTOR_PIN_S1, VEL);
  analogWrite(MOTOR_PIN_S2, VEL);
}
