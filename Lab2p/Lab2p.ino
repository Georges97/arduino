/*
 * IT462 George saab Lab 4
 */
 const int lightSensor = 5; //light sensor variable
 float sensValue = 0; //variable to hold sensor reading
 const int button = 3; //pin for button reads
 const int LED1 = 2;
 const int LED4 = 5;
 const int LED3 = 7;
 const int LED2 = 8;
 int buttonval = 0; //variable to hold button read
 int ledflag = 0;
 int ledState = LOW;
 unsigned long previousMillis = 0; //will store last time LED was updated
 const long interval = 30000; //interval at which it will blink
 int var = 0;

 

 

 

void SerialOutput(){
    Serial.print("Light Sensor Value"); //sens to screen
    Serial.print(sensValue, 2); //output variable to screen
    Serial.print("\n"); //drop down a line
}


void setup() {
  // put your setup code here, to run once:
  blinks();
  pinMode(button, INPUT); //setup button pin for input reads
  Serial.begin(9600); //Begins Serial coms at 9600 baud rate
  digitalWrite(LED1, HIGH);
  

}

void blinks(){
  var = 0;
  while (var < 5){
    var++;
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    delay(1000);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    delay(1000);
  }
}


void buttoncheck(){
  buttonval = (digitalRead(button)==HIGH);  //Read the pin position to obtain button state
  if (buttonval == HIGH){
    if (ledflag == 0) {
      ledflag = 1;
      digitalWrite(LED4, HIGH); //turn on
    }
  else {
   ledflag = 0;
   digitalWrite(LED4, LOW); //turn off 
  }
  }
}

void lightRead(){
  if (sensValue <= 300) {
    digitalWrite(LED3, HIGH); //turn on LED3 when dark
  }
  else {
    digitalWrite(LED3, LOW); //turn off LED3
  }


  if (sensValue > 300) {
      digitalWrite(LED2, HIGH); //turn on LED2 when light
    }
    else {
      digitalWrite(LED2, LOW); //turn off LED2
    }
}

void LowtoHigh(){
  // loop from the lowest pin to the highest:
unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(LED1, ledState);
  }
  
}


void loop() {
  // put your main code here, to run repeatedly:
  sensValue = analogRead(lightSensor); //import sensor data into the sensval variable
  buttoncheck();
  lightRead();
  LowtoHigh();
  SerialOutput();
  delay(1000);
  
  
  
    
}
