/*
  Fading

  This example shows how to fade an LED using the analogWrite() function.

 Use and Led at BoardPin 20 (PinIo 15)
*/

const int analogOutPin = 14; // Analog output pin that the LED is attached to BoardPin 20

void setup() {
  // nothing happens in setup
}

void loop() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(analogOutPin, fadeValue); // 0- 255
    // wait for 30 milliseconds to see the dimming effect
    delay(100);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(analogOutPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(100);
  }
}
