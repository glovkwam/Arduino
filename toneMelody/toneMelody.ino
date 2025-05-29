 /*Just drop this code in,  as a replacement for  Tone Melody sketch. 
 (to find it go to File>Examples>digital>tone_melody ). 
  keep the pitches.h tab in the sketch so you can use the music constants that provides.

 the following sketch should be made to work.
  You may use any internet resources, just not talking.
  You will need to hook up the following

  1. a led to Pin  19    (digital out)
  1. another led to Pin 15 (analog out)
  2. a speaker to pin 8  (digital out)
  3. a button to pin 5   (digital in)
  4. a potentiometer to A1  (analog in)
  
  A. You are to use the breadboard to make the connections and then demo 
  to the instructor it working.  
  B. Once the instructor has signed off on it  take a picture of it 
  with the magical object provided in the shot.
  C. In addition once working, record a 15 second video clip of its functionality.
  D. When done unplug the arduino and wait for further instructions.
  You have ~ 60 minutes.
  
*/


#include "pitches.h"

int solo[] = {  NOTE_DS5, NOTE_C5, NOTE_DS5, NOTE_C6, NOTE_FS5, 0};

int soloDurations[] = {
  4, 4, 4, 8, 6, 4
};

int riff[] = {
  NOTE_F2, NOTE_F2, NOTE_G2, NOTE_F2, NOTE_GS2, NOTE_F2, NOTE_AS2, NOTE_A2
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int riffDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4
};

float transpose[] = {0.5, 1.0, 2, 1.4};

// constants won't change. They're used here to set pin numbers:
const int button1Pin = 5;     // a btn
const int led1Pin =  19;      // this is for led  out
const int led2Pin =  15;      // this is for second led  out
const int speakPin = 8;    // new position for speaker

const int analogInPin0 = A2;  // Analog input pin for the pot


int button1State = 1;         // variable for reading toggle btn
int sensorValue0 = 0;        // value read from the pot
int outputValue0 = 0;        // value output after map



void setup() {

  Serial.begin(9600);
  // initialize the led pin as an output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT_PULLUP);
 
}



void loop() {
  // read the btn pin
  button1State = digitalRead(button1Pin);

  // read the pot and read the photocell
  sensorValue0 = analogRead(analogInPin0);
 

  // map it to the range of the analog out for the pot
  outputValue0 = map(sensorValue0, 0, 1023, 0, 255);
  

  // change the analog out value:
  //Serial.println(outputValue1);

  Serial.println("ON");

  if (button1State == HIGH) {
    // pick a transpose value;
    int whicht = int(random(4));
    for (int thisNote = 0; thisNote < 6; thisNote++) {

      int noteDuration = 1000 / soloDurations[thisNote];
      tone(speakPin, solo[thisNote]*transpose[whicht], constrain(noteDuration * (outputValue0 * .02) , 1, 500) );

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = constrain( noteDuration * (outputValue0 * .02) * 1.1, 1, 500);
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(speakPin);

      // toggle the led
      digitalWrite(led1Pin, !digitalRead(led1Pin));
      analogWrite(led2Pin, outputValue0);
    }

  } else {
    // pick a transpose value;
    int whicht = int(random(4));

    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / riffDurations[thisNote];
      tone(speakPin, riff[thisNote]*transpose[whicht], constrain(noteDuration * (outputValue0 * .006) , 1, 500));
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = constrain(noteDuration * (outputValue0 * .006) * 1.1 , 1, 500);
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(speakPin);
      // toggle the led
      digitalWrite(led1Pin, !digitalRead(led1Pin));
      analogWrite(led2Pin, outputValue0);
    }

  }


}    
                          
                          
                           
     