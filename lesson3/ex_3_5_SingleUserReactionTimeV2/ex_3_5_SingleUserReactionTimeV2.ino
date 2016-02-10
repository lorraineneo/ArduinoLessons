/**
 * This is another version of single user reaction timer
 * This piece of code is shorter, done with less function decomposition
 * It also uses an infinite while loop, and when the button signal is pressed (set to LOW) 
 * for the first time, it will do the computation of the time taken, and exit out of the loop 
 * using the "break" loop command.
 */

//Initialisation of the global variables 
int buttonPin = 2;
int ledPin = 4;
unsigned long startTime = 0, endTime = 0, timeTaken = 0;

void setup()
{
   randomSeed(analogRead(0)); //millis() returns # of milliseconds
                              // since the program started (unsigned long)
   Serial.begin(9600); //start serial communication with the computer
   pinMode(ledPin, OUTPUT);
   pinMode(buttonPin, INPUT_PULLUP);
}


void randomLightUp(){
  long wait = random(1000,9000); //randomly generate a wait between 1sec to 9sec
  delay(wait);
  startTime = millis(); //records the start time
  Serial.print("Start: ");
  Serial.println(startTime);
  digitalWrite(ledPin,HIGH); //turns on the led
}

void loop(){ 
  
  randomLightUp(); //calls the function randomLightUp()
  
  while(true){ //Infinite loop till break statement
    if (digitalRead(buttonPin) == LOW){ //When button is pressed
        endTime = millis(); //records the currTime when button is pressed
        Serial.print("End: ");
        Serial.println(endTime);
        timeTaken = endTime - startTime; //calculate timeTaken
        Serial.print("Reaction: ");
        Serial.print(timeTaken);
        Serial.println(" milliseconds");
        digitalWrite(ledPin, LOW); //switch off the led
        delay(50);
        break; //exit the infinite while loop
    }    
  }  
}


