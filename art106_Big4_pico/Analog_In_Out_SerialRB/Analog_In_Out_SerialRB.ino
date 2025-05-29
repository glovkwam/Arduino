/*
  
*/

// These constants won't change. They're used to give names to the pins used:
const int anaRedPin = A0;  // Analog input to BoardPin 31  ( see photocell circuit for complete connetion)
const int ledRedPin = 15; // Analog output pin  attached to BoardPin 20
const int anaBluPin = A1;  // Analog input to BoardPin 32  ( see photocell circuit for complete connetion)
const int ledBluPin = 16; // Analog output pin  attached to BoardPin 21
int sensorValueR = 0;        // value read from the pot
int outputValueR = 0;        // value output to the PWM (analog out)
int sensorValueB = 0;        // value read from the pot
int outputValueB = 0;        // value output to the PWM (analog out)


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  // pinMode(ledRedPin, OUTPUT);
  // pinMode(ledBluPin, OUTPUT);

}

void loop() {
  // channel red
  // read the analog in value:
  sensorValueR = analogRead(anaRedPin);
  // map it to the range of the analog out:
  outputValueR = map(sensorValueR, 0, 1000, 0, 255);
  // change the analog out value:
  analogWrite(ledRedPin, outputValueR);

  // channel blue
  // read the analog in value:
  sensorValueR = analogRead(anaRedPin);
  // map it to the range of the analog out:
  outputValueR = map(sensorValueR, 0, 1000, 0, 255);
  // change the analog out value:
  analogWrite(ledBluPin, outputValueR);

  // print the results to the Serial Monitor:  hit shift command/control M to open it.
  Serial.print("sensor = ");
  Serial.print(sensorValueR);
  Serial.print("\t output = ");
  Serial.print(outputValueR);
  Serial.print("sensor = ");
  Serial.print(sensorValueB);
  Serial.print("\t output = ");
  Serial.println(outputValueB);
  // wait 20 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(20);
}
