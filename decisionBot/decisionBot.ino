#include <Servo.h>
#define THINK 180
#define YES 135
#define MAYBE 90
#define NO 45
#define arrow 9
#define button 8

Servo motor;
void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(0));
  motor.attach(arrow);
  motor.write(YES);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool buttonState = digitalRead(button);
  int result = 0;
  if (!buttonState) {
    Serial.print("ThinkAction ");
    motor.write(THINK);
    result = thinkAction();
    Serial.print(" - ");
    Serial.print(result);
    Serial.print(" - ");    
  }
  if (result == 1) {
    yes();
  }
  else if (result == 2) {
    maybe();
  }
  else if (result == 3) {
    no();
  }
}

int thinkAction() {
  int number = biasedRandom();
  delay(700);
  return number;
}

void thinking() {
  motor.write(THINK);
  Serial.print("thinking - ");
}

void yes() {
  motor.write(YES);
  Serial.println("yes");
}

void maybe() {
  motor.write(MAYBE);
  Serial.println("maybe");
}

void no() {
  motor.write(NO);
  Serial.println("no");
}

int biasedRandom() {
  long number = random(0, 10);
  Serial.print(number);
  int result;
  if (number < 5) 
    result = 1;
  else if (number < 7)
    result = 2;
  else
    result = 3;
  return result;
}

