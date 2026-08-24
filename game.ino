#include <Wire.h>
#include <Arduino.h>
#include "display.h"
#include "joystick.h"
#include "score.h"
#include "snake.h"
#include "food.h"
#include "buzzer.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool start_game;
bool game_over;

//Timer
unsigned long lastMove = 0;
const unsigned long moveInterval = 150;
const int BUTTON = 4;

void setup(){
  Serial.begin(9600);

  //Setup OLED
  Wire.begin(21,22);
  
   // Initialize OLED screen
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Infinite loop to terminate program
  }

  //Setup Joystick
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  // Display initialization information
  display.setCursor(0, 0);
  display.println(F("SNAKE"));
  display.drawLine(0, 15, 127, 15, SSD1306_WHITE);

  //Buzzer setup
  pinMode(BUZZER,OUTPUT);

  //Button setup
  pinMode(BUTTON, INPUT_PULLUP);

  //INITIATE  
  initSnake();
  start_game = false;
  game_over = false;
  display.display();
}

void loop(){
  //Game Start
  if(digitalRead(BUTTON) == LOW && start_game == false && game_over == false){
    jingle();
    delay(3000);
    start_game = true;
  }

  //Game Loop
  if(start_game == true && game_over == false && millis() - lastMove >= moveInterval){
    readJoystick();
    move();
    checkCollisions();
    
    lastMove = millis();
  }

  if(digitalRead(BUTTON) == LOW && start_game == false && game_over == true){
    replay();
  }
} 