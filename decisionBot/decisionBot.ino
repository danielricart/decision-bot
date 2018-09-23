#include <Servo.h>

// Some alias that help us understand and read the code. Change de numbers here and the angles will change everywhere!
#define THINK_ANGLE 180   //angle of the "THINK" position
#define YES_ANGLE 135     //angle of the "YES" position
#define MAYBE_ANGLE 90    //angle of the "MAYBE" position
#define NO_ANGLE 45       //angle of the "NO" position

//Assign a number of Pin from your Arduino board. You can change the number but you need to move your Arduino wires!
#define arrow 9     //port used for the motor controlling the arrow
#define button 8    //port used for connecting the button

//assign values to different options. We'll use this later.
#define YES 1
#define MAYBE 2
#define NO 3


Servo motor;        //starts motor
void setup() {
  
  randomSeed(analogRead(0));    // a seed improves the randomness by provding diferent values that will make your options less likely to repeat.
  motor.attach(arrow);          // to move the arrow we need to connect it to the motor by adding the number of Pin that we defined before.
  motor.write(THINK_ANGLE);     // moves your arrow to the starting position, Thinking.
  pinMode(button, INPUT_PULLUP);//starts the button

  Serial.begin(115200);
}

void loop() {

  bool buttonState = digitalRead(button);   // save the state of the button in a variable to know if you are pressing the button or not.
  int thinkResult = 0;
  if (!buttonState) {
    Serial.print("ThinkAction ");
    motor.write(THINK_ANGLE);
    thinkResult = thinkAction();
    Serial.print(" - ");
    Serial.print(thinkResult);
    Serial.print(" - ");    
  }
  if (thinkResult == YES) {
    yes();
  }
  else if (thinkResult == MAYBE) {
    maybe();
  }
  else if (thinkResult == NO) {
    no();
  }
}

int thinkAction() {
  int number = biasedRandom();
  delay(700);
  return number;
}

void thinking() {
  motor.write(THINK_ANGLE);
  Serial.print("thinking - ");
}

void yes() {
  motor.write(YES_ANGLE);
  Serial.println("yes");
}

void maybe() {
  motor.write(MAYBE_ANGLE);
  Serial.println("maybe");
}

void no() {
  motor.write(NO_ANGLE);
  Serial.println("no");
}

int biasedRandom() {
  //here you define how often each option will appear by creating a bias.
  long number = random(0, 10); //create a new number from 0 to 10 (10 not included)
  Serial.print(number);
  if (number < 5) 
    return YES;
  else if (number < 7)
    return MAYBE;
  else
    return NO;
}

