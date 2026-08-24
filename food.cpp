#include "snake.h"
#include "display.h"

Point food;

void placeFood(){

  bool collision;
  do {
    int randX = random(0, COLS);
    int randY = random(0, ROWS);
    food = Point{randX, randY};

    collision = false;
    for(Point p : snake){
      if(p.x == food.x && p.y == food.y){
        collision = true;
        break;
      }
    }
  } while(collision);

  drawTile(food.x, food.y);
}