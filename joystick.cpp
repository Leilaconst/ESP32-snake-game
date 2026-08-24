#include "joystick.h"
#include "snake.h"
#include <Arduino.h>

int stick_x;
int stick_y;
int digital;

#define THRESHOLD_HIGH 3500
#define THRESHOLD_LOW  500

void readJoystick(){
  stick_x = analogRead(X_pin);
  stick_y = analogRead(Y_pin);

  if(stick_y >= THRESHOLD_HIGH && direction != 0){
    direction = 1;
  }
  else if(stick_y <= THRESHOLD_LOW && direction != 1){
    direction = 0;
  }
  else if(stick_x <= THRESHOLD_LOW && direction != 3){
    direction = 2;
  }
  else if(stick_x >= THRESHOLD_HIGH && direction != 2){
    direction = 3;
  }
}

void readDigital(){
  digital = digitalRead(SW_pin);
  if(digital == HIGH){

  }
}
