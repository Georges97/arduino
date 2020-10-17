/*
 * IT462 George saab Lab 1
 */
 int LEDP13 = 13; // Pin 13 is named LED
 int x=0; //set inital counter at start up

void range(){
    digitalWrite(LEDP13, HIGH); //turn on pin 13
    delay(1000); //wait for 1 second
    digitalWrite(LEDP13, LOW); //turn of pin 13
    delay(1000); //wait for 1 second
}

void SerialOutput(){
    Serial.print("int value="); //provide text to explain output
    Serial.print(x); //output variable x value
    Serial.print("\n"); //drop down a line
}


void setup() {
  // put your setup code here, to run once:
  pinMode(LEDP13, OUTPUT); //Initialize Pin as Output
  Serial.begin(9600); //Begins Serial coms at 9600 baud rate
  

}




void loop() {
  // put your main code here, to run repeatedly:
    SerialOutput();
    if ((x > 7) && (x < 16))
    {
        range();
        
    }
    else if ((x > 29) && (x < 59))
    {
        range();
    }
    else
    {
        digitalWrite(LEDP13, LOW); //turn off pin 13
        delay(1000); //wait for 1 second
    }
    x++; //increment the variable with each loop

}
