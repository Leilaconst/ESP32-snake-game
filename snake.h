#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"

//Constant variables

// Variables
extern int current_size;
extern int direction;
extern bool start_game;
extern bool game_over;

extern std::deque<Point> snake;

//functions
void move();
void checkCollisions();
Point checkBounds(Point newHead, Point head);
void initSnake();
void drawSnake();
void drawTile(int x, int y);
void eraseTile(int x, int y);
void replay();
void gameOverScreen();


#endif