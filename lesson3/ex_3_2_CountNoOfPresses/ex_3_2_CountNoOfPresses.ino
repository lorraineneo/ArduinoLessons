/**
 * This program demonstrates the behaviour of button "bouncing"
 * which is a physical phenomenon where a single press of the  
 * momentary button causes a unpredictable number of "presses".
 *  
 * The program is supposedly keeps a counter "pressed" of the number
 * of times the button is pressed, and prints it out the Serial
 * Monitor.
 */

int buttonPin = 2;
int pressed = 0; // counter to keep track of the # of presses

void setup()
{
  Serial.begin(9600); // setup Serial communication
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop(){
  int buttonval = digitalRead(buttonPin); //Read button State
  
  if (buttonval == LOW) //Pressed
  {
    pressed++; //Increment the pressed variable
    Serial.println(pressed);  //Print out to Serial Monitor
  }  
}
