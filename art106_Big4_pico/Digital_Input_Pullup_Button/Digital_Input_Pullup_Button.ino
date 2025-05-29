/*
  button_pullup
  shows how to hook up a simple button circuit.
  The Input_Pullup option will  set the Input pin to 3v (high), 
  and only when the button is pressed, it causes the pin to be set to ground (down).
  https://arduino-pico.readthedocs.io/en/latest/digital.html

  See diagram # __

  SD

*/
// these pin numbers are based on software IO pins , not hardware pins
int inputPin1 = 2; //io 2 is  Board Pin 4
int ledPin1 = 15; // io 15 is BoardPin 20
int ledPin2 = 16; // io 16 is BoardPin 21

void setup() {
   // INPUT_PULLUP when used, will set that Pin to 3.3v 
   //(high and then listen to when it changes).
  pinMode(inputPin1, INPUT_PULLUP); 
  pinMode(ledPin1, OUTPUT);  
  pinMode(ledPin2, OUTPUT);  
  //This is the function for setting up the serial feature.
  Serial.begin(9600);
}

void loop() {

  int btn1 = digitalRead(inputPin1);
  // this will measure whether there is 3.3v in the circuit or whether in this case its set to ground.
  // So if we complete the circuit and press the button, then the var ( btn1 ) is set to 0, as it is now grounded.
  Serial.println(btn1);

  if (btn1 == 0) {
    // when the button is pressed, it goes to ground, or 0.
    Serial.println("Low is On");
    digitalWrite(ledPin1, HIGH);  
    digitalWrite(ledPin2, HIGH);  
  } else {
    // when the button is not on, the circuit remains high ( 3.3v).
    Serial.println("High is Off");
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
  delay(50);
  
}