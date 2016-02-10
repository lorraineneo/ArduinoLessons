/**
 * This program uses a randomly lighted led to test the user reaction time
 * Program approached used: Function decomposition
 */

//Initialisation of the global variables 
int buttonPin = 2;
int ledPin = 4;
unsigned long startTime = 0, pressedTime = 0, timeTaken = 0;


void setup()
{
  //initializes the pseudo-random generator, 
  //causing it to start at an arbitrary point in its random sequence.
  randomSeed(analogRead(0)); 
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop(){ 
  randomLightUp(); // calls function "randomLightUp()"
  keepCheckingTillPressed();  // calls function keepCheckingTillPressed()
}

void randomLightUp(){
  //randomly generate a waitTime between 1sec to 9sec
  long waitTime = random(1000,9000); 
  delay(waitTime);
  
  digitalWrite(ledPin,HIGH); //turn ledPin ON
  
  //update startTime since ledPin is on
  
  startTime = millis(); //millis() returns # of milliseconds 
  Serial.print("Start: "); //since the program started (unsigned long)
  Serial.println(startTime);  
}

void keepCheckingTillPressed()
{
  boolean isButtonPressed = false; //indicator that button is pressed
  int currButtonState = HIGH; //initially button NOT pressed
 
  //Keep looping as long as button is NOT pressed
  while (!isButtonPressed) 
  {
    currButtonState = digitalRead(buttonPin); //get currButtonState
    if (currButtonState == LOW) //button just pressed
    {
      Serial.println("button pressed");
      recordPressedTime(); // calls function "recordPressedTime()"
      digitalWrite(ledPin, LOW); //switch off the led
      isButtonPressed = true; //set so that while loop will stop
    } 
  }
}

void recordPressedTime()
{
  pressedTime = millis(); //records the current time 
  Serial.print("End: ");
  Serial.println(pressedTime);
  timeTaken = pressedTime - startTime; //calculates the timeTaken
  Serial.print("Reaction: ");
  Serial.print(timeTaken);
  Serial.println(" milliseconds");  
}



