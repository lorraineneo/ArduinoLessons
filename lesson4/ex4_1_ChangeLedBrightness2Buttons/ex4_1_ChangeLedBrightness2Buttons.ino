const int kPinButton1 = 2;
const int kPinButton2 = 3;
const int kPinLed = 9;
int ledBrightness = 128; //Initial brightness at 50%

void setup()
{
  pinMode(kPinButton1, INPUT_PULLUP); 
  pinMode(kPinButton2, INPUT_PULLUP);
  pinMode(kPinLed, OUTPUT);
}

void loop()
{
  if (digitalRead(kPinButton1) == LOW) {
    //decrease brightness if button 1 is pressed
    ledBrightness--; 
  }
  else if (digitalRead(kPinButton2) == LOW) {
    //increase brightness if button 2 is pressed
    ledBrightness++;
  }
  //ensure that the brightness of LED is between 0 and 255
  ledBrightness = constrain(ledBrightness, 0, 255);

  analogWrite(kPinLed, ledBrightness);
  delay(20);
}

