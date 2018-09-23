/*
2018 Daniel Ricart Sanchez
Code for testing that the button works.
When the button is pressed the builtin LED lights.
*/

#define button 8

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button)) {
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off (LOW is the voltage level)
  }
  else {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)  
  }
}
