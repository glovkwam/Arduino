
/* 
This test program, is a simple version of the haptic interface for the Micro Sense
its goal is to activate and demonstrate all devices hooked up and working.
follow the diagram that goes with this test pr0gram "micro_sense_v1.jpg"
each device and a specific place it should go , using the circtuit options we 
have covered.  details on the motor driver and motors in class.
*/

byte sbbtnPin = 20;  // standby switch ( turns it on and off)
byte togbtnPin = 2;
byte mombtnPin = 6;
byte speakerPin = 8;
byte ledStatusPin = 3; 

byte sbbtnState = 0;
byte togbtnState = 0;
byte mombtnState = 0;

const int analogInPinPC_R = A0;  // ADC0 Analog input pin that the Right Photocell is attached to Hpin 31
int sensorValueR = 0;            // raw value
int outputValueR = 0;            // mapped value
const int analogOutPinR1 = 12;   // IN1 motor driver pins for Right motor
const int analogOutPinR2 = 13;   // IN2 motor driver pins  for Right motor
byte ledR = 16;                   // pin for Red led

const int analogInPinPC_B = A1;  // ADC1 Analog input pin that the BLue Photocell is attached to Hpin 32
int sensorValueB = 0;            // raw value
int outputValueB = 0;            // mapped value
const int analogOutPinB1 = 10;   // IN3 motor driver pins for Left motor
const int analogOutPinB2 = 11;   // IN4 motor driver pins for Left motor
byte ledB = 15;                  // pin for Blue led

const int analogInPinPot = A2;  // ADC2 Analog input pin for pot  Hpin 34 for update speed
int sensorPot = 0;              //
int outputPot = 0;
int oct;

void setup() {
  pinMode(sbbtnPin, INPUT_PULLUP);
  pinMode(togbtnPin, INPUT_PULLUP);
  pinMode(mombtnPin, INPUT_PULLUP);
  // pinMode(ledR, OUTPUT);
  // pinMode(ledB, OUTPUT);
  pinMode(ledStatusPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // read the digital inputs
  sbbtnState = digitalRead(sbbtnPin);
  togbtnState = digitalRead(togbtnPin);
  mombtnState = digitalRead(mombtnPin);

  // have the red and blue leds on
  // digitalWrite(ledR,HIGH);
  // digitalWrite(ledB,HIGH);


  // read the analog inputs
  sensorValueR = analogRead(analogInPinPC_R);  // Red photocell read
  sensorValueB = analogRead(analogInPinPC_B);  // Blue photocell read
  sensorPot = analogRead(analogInPinPot);      // Pot read

   // main logic of program
    
    mapPhotocellPotData();
  

  if (sbbtnState == LOW) {  //standby switch
     
    digitalWrite(ledStatusPin,!digitalRead(ledStatusPin));  // toggle the led pin with every pass

    changeLed(outputValueR, outputValueB, outputPot);

    if (togbtnState == LOW) {
      // nosound , just light and prints only
        printButtonsData();
        printPhotocellData();

    } else {
      if (mombtnState == LOW) {
        oct = 2;  // low sounds
      } else {
        oct = 4;  // higher sounds
      }
       playspeaker(oct);
     
    }

  } else {
    //  standby do nothing
  }

  delay(8);  // slight pause so the readings will be able to reset

}



void mapPhotocellPotData() {
  // map input for motor signal output ( from Red signal) // ADJUST THIS
  outputValueR = map(constrain(sensorValueR, 0, 1023), 0, 1000, 0, 255);

  //map input for motor signal output ( from Blue signal)  // ADJUST THIS
  outputValueB = map(constrain(sensorValueB, 0, 1023), 0, 1000, 0, 255);

  // maps the pot  // ADJUST THIS
  outputPot = map(constrain(sensorPot, 0, 1023), 0, 1023, 0, 255);  //map input for motor signal output ( Left signal)
}


void printButtonsData() {
  Serial.print("standby btn is = ");
  Serial.print(sbbtnState);
  Serial.print(" togglemode btn is = ");
  Serial.print(togbtnState);
  Serial.print("  soundchange btn = ");
  Serial.println(mombtnState);
}

void printPhotocellData() {
  Serial.print("red eye raw = ");
  Serial.print(sensorValueR);
  Serial.print(" red eye mapped = ");
  Serial.print(outputValueR);
  Serial.print("  blue eye mapped = ");
  Serial.print(sensorValueB);
  Serial.print(" blue eye mapped = ");
  Serial.print(outputValueB);
  Serial.print(" \t sensorPot raw = ");
  Serial.print(sensorPot);
  Serial.print(" \t outputPot = ");
  Serial.println(outputPot);
}



void changeLed(int pulsemoveR, int pulsemoveB, int timedelay) {
  analogWrite(ledR, 0);
  analogWrite(ledR, pulsemoveR);
  analogWrite(ledB, 0);
  analogWrite(ledB, pulsemoveB);
  delay(timedelay);
}

void playspeaker(int ol) {
  
  // this take both photocell values and then scales them up with ol  
  tone(speakerPin, (outputValueR + outputValueB) * ol, outputValueB);
  delay(outputPot);  // the pot will control the tempo of the notes played
  noTone(speakerPin);
}
