#include <Servo.h>

Servo rear_l;
Servo rear_r;
Servo front;
long premillis1 = 0;
long premillis2 = 0;

void setup() {
  rear_l.attach(3);
  rear_r.attach(4);
  front.attach(5);
  front.write(163);
  rear_l.write(0);
  rear_r.write(0);
  Serial.begin(9600);
  delay(10000);
}

void loop() {
  static int i = 0, j = 163, t = 0, flg1 = 0, flg2 = 0, flg3 = 0, pointer = 0;
  static unsigned long ima = 0;
  unsigned long currentmillis = millis();
  if (currentmillis - premillis1 > 1) {
    premillis1 = currentmillis;
    rear_l.write(i);
    rear_r.write(i);

    if(flg1 == 0) i= i+3;
    else          i = i-3;
    if(i == 180 | i == 0) flg1 = !flg1;

    Serial.print("rear ");
    Serial.print(i);
    Serial.print(" ");
    console();
  }
  if (currentmillis > 75000){
    Serial.print(currentmillis - ima); //Never delete this line.
    if(pointer == 1){
      if(currentmillis - premillis2 > 200) {
        premillis2 = currentmillis;
        if(flg2 == 1 && ((currentmillis - ima) < 12500)) j--;
        else front.write(j);

        if(flg2 == 0) j--;
        else          j++;
        if(flg2 == 0 && j == 133)   ima = currentmillis;
        if(j == 133)   flg2 = 1;
        if(j == 163)   pointer = 5;
      } 
    } else {
        pointer += 1;
    }
  }
  Serial.print(currentmillis / 1000);
}

void console() {
  Serial.print(rear_l.read());
  Serial.print(" ");
  Serial.print(rear_r.read());
  Serial.print(" ");
  Serial.println(front.read());
}
