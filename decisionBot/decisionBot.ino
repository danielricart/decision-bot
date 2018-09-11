#define think 7
#define arrow 8
#define thinking 9
#define yes 10
#define maybe 11
#define no 12


void setup() {
  // put your setup code here, to run once:
  pinMode(yes, OUTPUT);
  pinMode(no, OUTPUT);
  pinMode(maybe, OUTPUT);
  pinMode(thinking, OUTPUT);
  pinMode(think, INPUT_PULLUP);
  Serial.begin(115200);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  bool buttonState = digitalRead(think);
  int result = 0;
  if (!buttonState) {
    digitalWrite(yes, 0);
    digitalWrite(maybe, 0);
    digitalWrite(no, 0);
    digitalWrite(thinking, 1);
    Serial.print("ThinkAction ");
    result = thinkAction();
    Serial.print(" - ");
    Serial.print(result);
    Serial.println(" ");    
  }
  if (result == 1) {
    digitalWrite(yes, !buttonState);
    Serial.print("yes");
  }
  else if (result == 2) {
    digitalWrite(maybe, !buttonState);
    Serial.print("maybe");
  }
  else if (result == 3) {
    digitalWrite(no, !buttonState);
    Serial.print("no");
  }
  digitalWrite(thinking, !buttonState);
}

int thinkAction() {
  int number = biasedRandom();
  delay(700);
  return number;
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

