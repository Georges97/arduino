const int Relay1=7; //relay variable

int timer=0; // counter varible
int button = 3; // button input declaration
int LED1=8; //LED declaration
int LED2=10; //LED declaration
int LED3=5; //LED declartation
int buttonState=0; //variable to track button pushes
int countdownState=0; //track if countdown should run
int buttonval=0; //variable to hold button reads
int var = 0;

void SerialOutput(){
  Serial.print("Timer="); //provide text to explain output
  Serial.print(timer); //output variable x value
  Serial.print("\n"); // drop down a line
  Serial.print("buttonState="); //provide text to explain output
  Serial.print(buttonState); //output variable x value
  Serial.print("\n"); // drop down a line
  Serial.print("countdownState="); //provide text to explain output
  Serial.print(countdownState); //output variable x value
  Serial.print("\n"); // drop down a line
}

//makes a blink function for LED1 to blink three times
void blinks(){
  var = 0;
  while (var < 3){
    var++;
    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED1, LOW);
    delay(1000);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(Relay1, OUTPUT);
  pinMode(button,INPUT); //button setup
  pinMode(LED1, OUTPUT); //LED setup
  pinMode(LED2, OUTPUT); //LED setup
  pinMode(LED3, OUTPUT); //LED setup
  Serial.begin(9600); //setup serial comms
  digitalWrite(Relay1, HIGH); //turn off relay
  blinks(); //Calls the blink function

}




void buttonCheck(){
  buttonval = digitalRead(button);  //check for button press
  if ((buttonval == 1) && (buttonState == 0))
  {
    //if the button is pushed for the first time startup timer etc.
    Serial.print("button pushed and state should change");
    countdownState=1; //set variable to 1 to run countdown used in countdownCheck function
    buttonState=1; //increment buttonState by 1
    Serial.print(buttonState);
    digitalWrite(LED2, HIGH); //turn on LED
    
  }
  else if ((buttonval == 1) && (buttonState == 1)){
    // if the button is  pushed for the second time - reset everything and shutdown the counting function through countdownState=0
    digitalWrite(LED2, LOW); //turn Off 
    digitalWrite(Relay1, HIGH); //turn off relay
    digitalWrite(LED3, LOW); //turn off LED
    countdownState = 0; //set variable to 1 to run countdown
    buttonState--; //decrement buttonState by 1
    timer=0; //reset the timer
  }
  else {
     
  }
}

void countdownCheck(){
  if ((countdownState == 1) && (timer != 30)) { 
    //if the countdown is set to run (countdownState==1) and max time not met, turn on relay, led and increment the timer counter
    timer++; // increment timer
    digitalWrite(Relay1, LOW); //turn on relay
    digitalWrite(LED3, HIGH); //turn on LED
    
    
  }
  if ((countdownState ==1) && (timer == 30)){
    //if we hit the maximum timer counter value of 5, reset countdownState to turn off counting and reset buttonState and timer
    countdownState = 0;//reset countdownState to off
    timer = 0; //reset the timer to 0
    digitalWrite(Relay1, HIGH); //turn off relay
    digitalWrite(LED3, LOW); //turn off LED
    
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, HIGH);// turn on
  buttonCheck();
  countdownCheck();
  SerialOutput();
  delay(1000);
}
