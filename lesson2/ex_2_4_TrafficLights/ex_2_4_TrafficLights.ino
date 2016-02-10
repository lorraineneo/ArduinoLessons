/**
 * This code simulates the traffic light signals
 * Green (5 secs, rest 250ms)
 * Blinking Green (10 x 250ms)
 * Yellow (3 x 250ms)
 * Red (5 secs, rest 250ms)
 */
int timer = 250;           // The higher the number, the slower the timing.
int greenLed = 4;
int yellowLed = 3;
int redLed = 2;
void setup() {
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 2; thisPin < 5; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  
  digitalWrite(greenLed, HIGH);
  delay(5000);
  digitalWrite(greenLed, LOW);
  delay(timer);
  
  for (int times = 0; times < 10; times++){
        digitalWrite(greenLed, HIGH);
   		delay(timer);
   		digitalWrite(greenLed, LOW);
    	delay(timer);
    
  }
  
  for (int times = 0; times < 3; times++){
   	digitalWrite(yellowLed, HIGH);
   	delay(timer);
   	digitalWrite(yellowLed, LOW);
    delay(timer);
  }
  
  digitalWrite(redLed, HIGH);
  delay(5000);
  digitalWrite(redLed, LOW);
  delay(timer);
  
  
}
