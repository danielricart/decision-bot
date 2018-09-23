#include <Servo.h>

// Some alias that help us understand and read the code
#define THINK 180   //angle of the "THINK" position
#define YES 135     //angle of the "YES" position
#define MAYBE 90    //angle of the "MAYBE" position
#define NO 45       //angle of the "NO" position
#define arrow 9     //port used for the motor controlling the arrow
#define button 8    //port used for connecting the button

Servo motor;        //motor represnetation
void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(0));    // improves random
  motor.attach(arrow);          // setup the motor to the assigned port
  motor.write(THINK);             // initialize the default position to thinking
  pinMode(button, INPUT_PULLUP);//setup the button port in the special "button mode". makes connections easier and the readings are more reliable

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool buttonState = digitalRead(button);   // save the state of the button in a variable
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

