/*
 * Written for Arduino Uno or Nano or similar
 * Detects mains voltage when using a mains optoisolator
 * See https://www.youtube.com/RalphBacon video #111 for full details
 * 
 * Connect pin 2 of your Arduino to one of the channels on the module.
 */
#define voltPin 2
bool mainsDetected = false;

void setup() {
  // Set up Serial Monitor (aka debug window)
  Serial.begin(9600);
  
  // We don't need a PULLUP as the pin is approx 3.3v or zero volts
  pinMode(voltPin, INPUT);

  Serial.println("Setup Completed");
}

void loop() {
  // If we now detect mains voltage and previously there was none...
  if (digitalRead(voltPin) == LOW && mainsDetected == true) {
    mainsDetected = false;
    Serial.println("No mains voltage detected.");
  }

  // If we now detect NO mains voltage and previously there was some...
  if (digitalRead(voltPin) == HIGH && mainsDetected == false) {
    mainsDetected = true;
    Serial.println("Mains voltage detected.");
  }
}


