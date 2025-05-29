//sd notes, a simple example of analog input being mapped and output to a analog output.
// These constants won't change. They're used to give names to the pins used:
const int ana0Pin = A0;  // Analog input 0 or BoardPin 31  ( see potiameter circuit for complete connetion)
const int ledPin = 15; // Analog output pin  attached to BoardPin 20
int sensorValue1 = 0;        // value read from the pot
int outputValue1 = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}


void loop() {
  // channel 1
  // read the analog in value:
  sensorValue1 = analogRead(ana0Pin);
  // map it to the range of the analog out:
  outputValue1 = map(sensorValue1, 0, 1000, 0, 255);
  // change the analog out value:
  analogWrite(ledPin, outputValue1);
    // print the results to the Serial Monitor:  hit shift command/control M to open it.
  Serial.print("sensor = ");
  Serial.print(sensorValue1);
  Serial.print("\t output = ");
  Serial.println(outputValue1);

  // wait 20 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(20);
}
