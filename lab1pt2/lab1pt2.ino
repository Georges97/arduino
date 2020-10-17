/*
 * IT462 George saab Lab 1 part 2
 */
int timer = 100;           



void setup() {

  // use a for loop to initialize each pin as an output:
  for (int Pins = 1; Pins < 6; Pins++) {

    pinMode(Pins, OUTPUT);

  }
}

void LowtoHigh(){
    // loop from the lowest pin to the highest:

    for (int Pins = 1; Pins < 6; Pins++) {

      digitalWrite(Pins, HIGH); // turn the pin on range 1 through 5
  
      delay(timer);
  
      digitalWrite(Pins, LOW); // turn the pin off range 1 through 5

  }
}

void HightoLow(){
    // loop from the highest pin to the lowest:
     for (int Pins = 5; Pins >= 1; Pins--) {

      digitalWrite(Pins, HIGH);  // turn the pin on range 1 through 5
  
      delay(timer);
      
      digitalWrite(Pins, LOW); // turn the pin off range 1 through 5
  }

}

void loop() {

  LowtoHigh();
  
  HightoLow();
  
 
}
