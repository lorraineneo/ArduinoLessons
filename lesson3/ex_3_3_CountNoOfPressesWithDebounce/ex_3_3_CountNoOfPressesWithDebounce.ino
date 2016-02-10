/**
 * This program is solving the 'bouncing' problem faced by the physical 
 * button.
 * 
 * It detects and only registers a press or release of the button when 
 * the button state changes from HIGH to LOW (press) 
 * or LOW to HIGH (release)
 */

int buttonPin = 2;
int pressed = 0; // Counter
int prevButtonState = HIGH; //not pressed initially
int currButtonState = HIGH; //not pressed initially

void setup()
{
  Serial.begin(9600); //Setup Serial communication with computer
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop(){
  currButtonState = digitalRead(buttonPin); //Read currButtonState
  
  if (currButtonState == LOW && prevButtonState == HIGH) //Just Pressed
  {
    prevButtonState = LOW; //Update
    pressed++; //Increase counter
    Serial.println(pressed);  
  }
  
  if (currButtonState == HIGH && prevButtonState == LOW) //Just Released
  {
    prevButtonState = HIGH; //Update
  }  
}
