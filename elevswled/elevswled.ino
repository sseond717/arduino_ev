const int call_btn1 = 15;
const int call_btn2 = 16;
const int call_btn3 = 17;

const int floor_1 = 7;
const int between_1 = 8;
const int between_2 = 9;
const int floor_2 = 10;
const int between_3 = 11;
const int between_4 = 12;
const int floor_3 = 13;
int current_floor = 7;
int tg_f= 7;
void setup() {
  pinMode(call_btn1, INPUT);
  pinMode(call_btn2, INPUT);
  pinMode(call_btn3, INPUT);

  pinMode(floor_1, OUTPUT);
  pinMode(between_1, OUTPUT);
  pinMode(between_2, OUTPUT);
  pinMode(floor_2, OUTPUT);
  pinMode(between_3, OUTPUT);
  pinMode(between_4, OUTPUT);
  pinMode(floor_3, OUTPUT);
  
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}void loop(){
  digitalWrite(current_floor, 1);
  if (digitalRead(call_btn1) == 1) {
    tg_f = floor_1 ;
    digitalWrite(1, 1); 
    move();
  } else digitalWrite(1, 0); 
  if (digitalRead(call_btn2) == 1) {
    tg_f = floor_2;
    digitalWrite(2, 1);
    move();
  } else digitalWrite(2, 0);
  if (digitalRead(call_btn3) == 1) {
    tg_f = floor_3;
    digitalWrite(3, 1); 
    move();
  } else digitalWrite(3, 0);
  }
void move() {
  if(tg_f > current_floor){
    up(tg_f);
  }
  else if(tg_f < current_floor){
  	down(tg_f);
  }
}void down(int tg) {
  for (int i = current_floor; i >= tg_f; i--) {
    digitalWrite(i, 1);
    delay(500);
    digitalWrite(i, 0);
  }
  current_floor = tg_f;
}
void up(int tg){
  for(int i = current_floor; i <= tg_f; i++){
  	digitalWrite(i,1);
  	delay(500);
  	digitalWrite(i,0);
  }
  current_floor = tg_f;
}