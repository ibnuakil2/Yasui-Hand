#include <Servo.h>
#include <Wire.h>

#define btnUp   2

boolean statusBtnUp   = false;

boolean statusAkhirBtnUp   = false;

boolean UP   = false;
int menuItem = 1;
Servo jempol;

int STBY = 6; //standby
int STBY_ = 11;

//motor jari mannis dan kelingking
int AIN1 = 5; //Direction
int AIN2 = 4; //Direction
int PWMA = 14;

//Motor jari tengah
int BIN1 = 7; //Direction
int BIN2 = 8; //Direction
int PWMB = 15;

//motor jari telunjuk
//int AIN2_ = 9;
//int AIN1_ = 10;

//motor jempol
int BIN1_ = 12; //Direction
int BIN2_ = 13; //Direction

int little;
int middle;
int index;
int thumb;

void setup(){
  Serial.begin(9600);
  Serial.println (menuItem);
  Serial.println("masukan mode");
  jempol.attach(3);
  
//untuk jari tengah dan kelingkinng
pinMode(STBY, OUTPUT);
pinMode(AIN1, OUTPUT);
pinMode(AIN2, OUTPUT);
pinMode(BIN1, OUTPUT);
pinMode(BIN2, OUTPUT);
pinMode(PWMA, OUTPUT);
pinMode(PWMB, OUTPUT);

// unntuk telunjuk dan jempol
pinMode(STBY_, OUTPUT);
//pinMode(AIN1_, OUTPUT);
//pinMode(AIN2_, OUTPUT);
pinMode(BIN1_, OUTPUT);
pinMode(BIN2_, OUTPUT);

}

void loop(){
  pinch();
}
 

void pinch(){ 
  move(1, 255, 1);
  move(2, 255, 1);
  move(3,255, 1);
  delay(600);
  jempol.write(60);
  berhenti();
  
}

void tripod(){
  move(1, 255, 1);
  move(2,255, 0);
  move(4,255, 1);
  delay(600); 
  jempol.write(70);
  berhenti();
  
  
}

void grip(){
  move(1, 255, 0);
  move(2, 255, 0);
  move(4, 255, 0);
  delay(600);
  jempol.write(70);
  berhenti();
  
}
void move(int motor, int speed, int direction){
digitalWrite(STBY, HIGH);
digitalWrite(STBY_, HIGH);

boolean inPin1 = LOW;
boolean inPin2 = HIGH;

if(direction == 1){
inPin1 = HIGH;
inPin2 = LOW;
}


if(motor == 1){
  digitalWrite(AIN1, inPin1);
  digitalWrite(AIN2, inPin2);
}
  //---------------------------
  if(motor == 2){
  digitalWrite(BIN1, inPin1);
  digitalWrite(BIN2, inPin2);
  
}
  //----------------------
  if(motor == 3){
  digitalWrite(AIN1_, inPin1);
  digitalWrite(AIN2_, inPin2);
  
}
  //-----------------------------
  if(motor == 4){
   digitalWrite(BIN1_, inPin1);
   digitalWrite(BIN2_, inPin2);
  
}
  //----------------------------
  
}

void berhenti(){
//enable standby
digitalWrite(STBY, LOW);
digitalWrite(STBY_, LOW);
delay(1000000);
}
