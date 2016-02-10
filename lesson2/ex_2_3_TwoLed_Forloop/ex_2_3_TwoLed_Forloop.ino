int redLEDPin=2; //Declare redLEDPin an int, and set to pin 2 
int yellowLEDPin=4; //Declare yellowLEDPin an int, and set to pin 4 
int redOnTime=250; //Declare redOnTime an int, and set to 250 mseconds 
int redOffTime=250; //Declare redOffTime an int, and set to 250 
int yellowOnTime=250; //Declare yellowOnTime an int, and set to 250
int yellowOffTime=250; //Declare yellowOffTime an int, and set to 250

void setup() {
  pinMode(redLEDPin, OUTPUT);  // Tell Arduino that redLEDPin is an output pin
  pinMode(yellowLEDPin, OUTPUT);  //Tell Arduino that yellowLEDPin is an output pin
}

void loop() {

  for (int i = 0; i < 3; i++){
    digitalWrite(redLEDPin,HIGH); //Turn red LED on
    delay(redOnTime);             //Leave on for redOnTime
    digitalWrite(redLEDPin,LOW);  //Turn red LED off
    delay(redOffTime);            //Leave off for redOffTime
  }
 

  digitalWrite(yellowLEDPin,HIGH); //Turn red LED on
  delay(yellowOnTime);             //Leave on for redOnTime
  digitalWrite(yellowLEDPin,LOW);  //Turn red LED off
  delay(yellowOffTime);            //Leave off for redOffTime
}
