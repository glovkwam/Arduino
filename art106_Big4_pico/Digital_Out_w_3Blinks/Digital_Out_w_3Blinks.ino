/*
  Blink fast and slow with a timer changing 
  more info on pinMode and digitalOut
  https://arduino-pico.readthedocs.io/en/latest/digital.html

  SD

*/

int dcounter = 330;
int dir = 20;
// the setup function runs once when you press reset or power the board
void setup() {

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // digital output being set for the led
  pinMode(10, OUTPUT);  //gppin8 , BoardPin 11
  pinMode(15, OUTPUT); //gppin 15, BoardPin 20 
  pinMode(27, OUTPUT); //gppin 27, BoardPin 32 
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on by making the voltage high
  delay(dcounter);                  // wait for a period of time in milliseconds
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(dcounter);


  digitalWrite(27, HIGH);  // turn the LED on by making the voltage high
  delay(dcounter);                  // wait for a period of time in milliseconds
  digitalWrite(8, HIGH);   // turn the LED off by making the voltage LOW
  delay(dcounter);



// Remember to refer to the pinout map on the class web page.
// Look for which Io pin this is it should be PinIO 8, which is 11th BoardPin on the pico  
  digitalWrite(27, LOW);  
  delay(dcounter);
  digitalWrite(8, LOW);
  delay(dcounter);

  digitalWrite(15, HIGH);  // This is pinio15, which physical pin is it?
  delay(dcounter);
  digitalWrite(15, LOW);
  delay(dcounter);

  // This is aa simple timer variable for the delay (dcounter)
  // dir is used to change the value each time through the list and the if statement 
  // changes it when the values for dcounter go to high or low.

  if (dcounter > 350) {
    dir = -20;
  }

  if (dcounter < 30) {
    dir = 20;
  }
  dcounter += dir;


  // This is used to send a message back from the Pico to the arduino software.
  // the println command is used to watch the progress of the program and is used for debugging.
  Serial.println(dcounter);




}