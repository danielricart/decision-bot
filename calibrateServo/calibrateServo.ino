#include <Servo.h>
#define MIN 1
#define MAX 180

Servo myservo; 
int angle = 179;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(8, INPUT_PULLUP);
myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (angle > MIN && angle < MAX) {
    myservo.write(angle);
    angle--;
    Serial.println(angle);
  }
  delay(200);  
}
