const int kPinPot = A0;
const int kPinLed = 2;

void setup()
{
  pinMode(kPinPot, INPUT);
  pinMode(kPinLed, OUTPUT);
}

void loop()
{
  int ledBrightness;
  int sensorValue = 0;

  sensorValue = analogRead(kPinPot);
  ledBrightness = map(sensorValue, 0, 1023, 0, 255);

  analogWrite(kPinLed, ledBrightness);
}

