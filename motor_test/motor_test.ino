int firstPin = 9;
int secondPin = 10;
long firstPreviousMillis = 0;
long secondPreviousMillis = 0;
int firstLEDState = LOW;
int secondLEDState = LOW;

unsigned long firstDelay = 1000;
unsigned long secondDelay = 1500;

void setup() {
 pinMode(firstPin, OUTPUT);
 pinMode(secondPin, OUTPUT);
}

void loop() {
  
  
  unsigned long firstCurrentMillis = millis();
  unsigned long secondCurrentMillis = millis();
  
  if (firstCurrentMillis - firstPreviousMillis > firstDelay)
  {
    firstPreviousMillis = firstCurrentMillis;

    if (firstLEDState == LOW)
      firstLEDState = HIGH;
    else
      firstLEDState = LOW;
  }

  if (secondCurrentMillis - secondPreviousMillis > secondDelay)
  {
    secondPreviousMillis = secondCurrentMillis;

    if (secondLEDState == LOW)
      secondLEDState = HIGH;
    else
      secondLEDState = LOW;
  }

  digitalWrite(secondPin, secondLEDState);
  digitalWrite(firstPin, firstLEDState);
  
}
