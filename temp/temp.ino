/*
 * IT462 George saab Lab temp sensor
 */
//turns on a fan
int  tempSensor = 5; //pin decl for temp sensor
float sensorValue = 0; //temp sensor reading
float val = 0; //partial calculation
float tempcel=0; //Celsuis Temperture
float tempf=0; //Fahrenheit Temp
float diff=24.03; //differential
int delayTime = 1000; //declared delay time


void SerialOutput(){
  Serial.print("sensorValue="); //Output to screen label
  Serial.print(sensorValue); //Output sensor reading to screen
  Serial.print("\n"); //drop a line
  Serial.print("val="); //output to screen
  Serial.print(val); //output to screen
  Serial.print("\n"); //drop a line
  Serial.print("tempcel="); //output to screen
  Serial.print(tempcel); //output to screen
  Serial.print("\n"); //drop a line
  Serial.print("tempf="); //output to screen
  Serial.print(tempf); //output to screen
  Serial.print("\n"); //drop a line
  
  
}

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); //turn on serial coms
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(tempSensor); // read sensor data
  val = ((sensorValue*3.3)/1024); //address voltage level
  tempcel = (val*100)-diff; //calculate temp in cel
  tempf = tempcel*9/5+32; //calculate temp in Feh
  SerialOutput(); //output to screen
  delay(delayTime); // delay based on variiable setting

}
