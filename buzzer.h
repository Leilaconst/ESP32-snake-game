#ifndef BUZZER_H
#define BUZZER_H
#include "pitches.h"

#define BUZZER 12
#define LENGTH 9

extern int duration; 

void jingle();
void scoreTone();
void gameOverTone();
#endif