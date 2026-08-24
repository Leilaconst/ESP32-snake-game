#include "buzzer.h"
#include "pitches.h"
#include <Arduino.h>

int duration = 300;

int melody[LENGTH] = {
  NOTE_C5, NOTE_E5, NOTE_G5, NOTE_D5, NOTE_FS5, NOTE_A5, NOTE_E5, NOTE_GS5, NOTE_B5};


int melody2[LENGTH] = {
  NOTE_AS5, NOTE_G5, NOTE_E5, NOTE_GS5, NOTE_F5, NOTE_D5, NOTE_FS5, NOTE_DS3, NOTE_C5};

void jingle(){
  for(int note=0; note < LENGTH; note++){
    tone(18, melody[note], duration);
  }
}

void gameOverTone(){
  for(int note=0; note < LENGTH; note++){
    tone(18, melody2[note], duration);
  }
}

void scoreTone(){
  tone(18, NOTE_C5, duration-100);
}