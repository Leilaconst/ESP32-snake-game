#include "display.h"
#include <string>

int score; 

void writeScore(){

  display.setCursor(75, 0);
  display.fillRect(65, 0, 63, 7, SSD1306_BLACK);

  std::string text = "SCORE:" + std::to_string(score);

  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.println(text.c_str());
}
void incScore(){
  score++;
}