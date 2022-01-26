//Initialisation

int LEDState = 0;

//add note library
#include "pitches.h"  

int LEDPin1 = 9;
int LEDPin2 = 10;
int LEDPin3 = 11;
int buttonPin = 7;
int buttonNew;
int buttonOld = 1;
int dt = 100;
int buzzerPin = 3;

// Song 1:Pink Panther theme
//notes in the melody
// change this to make the song slower or faster
int tempoone=140; 
int melodyone[] = {
  
  // Score available at https://musescore.com/benedictsong/the-pink-panther

  REST,2, REST,4, REST,8, NOTE_DS4,8, 
  NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
  NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
  NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
  NOTE_E4,2, REST,4, REST,8, NOTE_DS4,4,

  NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
  NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_G4,8, NOTE_B4,-8, NOTE_E5,8,
  NOTE_DS5,1,   
  NOTE_D5,2, REST,4, REST,8, NOTE_DS4,8, 
  NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
  NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
  
  NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
  NOTE_E4,-4, REST,4,
  REST,4, NOTE_E5,-8, NOTE_D5,8, NOTE_B4,-8, NOTE_A4,8, NOTE_G4,-8, NOTE_E4,-8,
  NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8,   
  NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, NOTE_E4,16, NOTE_E4,16, NOTE_E4,2,
 
};
// there are two values per note (pitch and duration), so for each note there are four bytes
int notesone=sizeof(melodyone)/sizeof(melodyone[0])/2; 

// this calculates the duration of a whole note in ms (60s/tempo)*4 beats
int wholenoteone = (60000 * 4) / tempoone;

int dividerone = 0;
int noteDurationone = 0;
//Initialisation complete for Song 1

//Song 2: Nokia Ringtone
// change this to make the song slower or faster
int tempo = 180;
int melodytwo[] = {

  // Nokia Ringtone 
  // Score available at https://musescore.com/user/29944637/scores/5266155
  
  NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, 
  NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4, 
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
  NOTE_A4, 2, 
};
// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melodytwo) / sizeof(melodytwo[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;
int divider = 0;
int noteDuration = 0;
//Initialisation of song 2 completed

//Song 3: Asa Branca- Luiz Gonzaga
 // change this to make the song slower or faster
 int tempoab = 120;  
 int melodythree[] = {
// Source for the score: Score available at https://musescore.com/user/190926/scores/181370
        
          NOTE_G4,8, NOTE_A4,8, NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_B4,4, 
          NOTE_C5,4, NOTE_C5,2, NOTE_G4,8, NOTE_A4,8,
          NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_C5,4,
        
          NOTE_B4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
          NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,
          NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,
        
          NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
          NOTE_G4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
          NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,
        
          NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,
          NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
          NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,
        
          NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
          NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,
          NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
          NOTE_G4,-2, REST,4
          
};
// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notesab = sizeof(melodythree) / sizeof(melodythree[0]) / 2;
        
// this calculates the duration of a whole note in ms
int wholenoteab = (60000 * 4) / tempoab;
int dividerab = 0, noteDurationab = 0;

void setup(){
  Serial.begin(9600);
  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin3, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  }

void loop(){

  buttonNew = digitalRead(buttonPin);
  if(buttonOld==0 && buttonNew==1){
  
    if(LEDState==0){
      //iterate over the notes of the melody
      for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

      //while the song plays, make  the lights flicker
      //Flicker 1- Calm 1
          analogWrite(LEDPin1,random(200)+135);
          analogWrite(LEDPin2,random(200)+135);
          analogWrite(LEDPin3,random(200)+135);
          delay(random(200));
          
    // calculates the duration of each note
    dividerone = melodyone[thisNote + 1];
    if (dividerone > 0) {
      // regular note, just proceed
      noteDurationone = (wholenoteone) / dividerone;
    } else if (dividerone < 0) {
      // dotted notes are represented with negative durations!!
      noteDurationone = (wholenoteone) / abs(dividerone);
      noteDurationone *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzerPin, melodyone[thisNote], noteDurationone*0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDurationone);
    
    // stop the waveform generation before the next note.
    noTone(buzzerPin);
  }
      LEDState = 1;
     }
     else if(LEDState == 1){
        
          
        // iterate over the notes of the melody.
        // Remember, the array is twice the number of notes (notes + durations)
        for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
          //Flicker 1- Calm 1
          analogWrite(LEDPin1,random(300)+150);
          analogWrite(LEDPin2,random(300)+150);
          analogWrite(LEDPin3,random(300)+150);
          delay(random(200));
          
          // calculates the duration of each note
          divider = melodytwo[thisNote + 1];
          if (divider > 0) {
            // regular note, just proceed
            noteDuration = (wholenote) / divider;
          } else if (divider < 0) {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenote) / abs(divider);
            noteDuration *= 1.5; // increases the duration in half for dotted notes
          }
      
          // we only play the note for 90% of the duration, leaving 10% as a pause
          tone(buzzerPin, melodytwo[thisNote], noteDuration * 0.9);
      
          // Wait for the specief duration before playing the next note.
          delay(noteDuration);
      
          // stop the waveform generation before the next note.
          noTone(buzzerPin);
        }
        LEDState = 2;
      }
      else if(LEDState == 2){
        for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

          //Flicker 1- Calm 1
          analogWrite(LEDPin1,random(120)+180);
          analogWrite(LEDPin2,random(120)+180);
          analogWrite(LEDPin3,random(120)+180);
          delay(random(200));
          LEDState = 3;
          // calculates the duration of each note
          dividerab = melodythree[thisNote + 1];
          if (dividerab > 0) {
            // regular note, just proceed
            noteDurationab = (wholenoteab) / dividerab;
          } else if (dividerab < 0) {
            // dotted notes are represented with negative durations!!
            noteDurationab = (wholenoteab) / abs(dividerab);
            noteDurationab *= 1.5; // increases the duration in half for dotted notes
          }
      
          // we only play the note for 90% of the duration, leaving 10% as a pause
          tone(buzzerPin, melodythree[thisNote], noteDurationab * 0.9);
      
          // Wait for the specief duration before playing the next note.
          delay(noteDurationab);
      
          // stop the waveform generation before the next note.
          noTone(buzzerPin);
       }
        LEDState = 3;
     }
   
     else{
      analogWrite(LEDPin1,0);
      analogWrite(LEDPin2,0);
      analogWrite(LEDPin3,0);
      LEDState = 0;
      noTone(buzzerPin);
     }
    
    }
    buttonOld = buttonNew;
    delay(dt);
}
