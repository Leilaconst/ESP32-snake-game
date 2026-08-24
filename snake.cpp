#include "snake.h"
#include <Arduino.h>
#include "display.h"
#include "food.h"
#include "score.h"
#include "buzzer.h"

std::deque<Point> snake;
int direction;

// Setup
void initSnake(){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    
    // Display initialization information
    display.setCursor(0, 0);
    display.println(F("SNAKE"));
    display.drawLine(0, 15, 127, 15, SSD1306_WHITE);

    display.setTextSize(1);

    snake.push_front(Point{COLS/2+1, ROWS/2});
    snake.push_front(Point{COLS/2, ROWS/2});
    snake.push_front(Point{COLS/2-1, ROWS/2});
    
    direction = 2;
    score = 0;

    writeScore();
    drawSnake();
    placeFood();
    display.display();
}

void drawSnake() {
    for(Point p: snake){
        drawTile(p.x, p.y);
    }
}

void drawTile(int x, int y){
    display.fillRect(TILE*x, TILE*y + OFFSET, TILE, TILE, SSD1306_WHITE);
}

void eraseTile(int x, int y){
    display.fillRect(TILE*x, TILE*y + OFFSET, TILE, TILE, SSD1306_BLACK);
}

void checkCollisions(){
    Point head = snake.front();
    std::deque<Point> tempSnake = snake;
    tempSnake.pop_front();

    for(Point p: tempSnake){
        if(head.x == p.x && head.y == p.y){
            start_game = false;
            game_over = true;
            gameOverTone();
            gameOverScreen();
        }
    }
}

Point checkBounds(Point newHead, Point head){
    
    if(newHead.x < 0){
        return newHead = Point{COLS-1, head.y};
    }
    else if(newHead.x > COLS-1){
        return newHead = Point{0, head.y};
    }
    else if(newHead.y < 0){
        return newHead = Point{head.x, ROWS-1};
    }
    else if(newHead.y > ROWS-1){
        return newHead = Point{head.x, 0};
    }
    else{
        return newHead;
    }
}


void move(){
    Point head = snake.front();
    Point tail = snake.back();
    Point newHead;

    if(direction == 0){
        newHead = Point{head.x, head.y-1};
        newHead = checkBounds(newHead, head);
    }
    else if(direction == 1){
        newHead = Point{head.x, head.y+1};
        newHead = checkBounds(newHead, head);
    }
    else if(direction == 2){
        newHead = Point{head.x-1, head.y};
        newHead = checkBounds(newHead, head);
    }
    else{
        newHead = Point{head.x+1, head.y};
        newHead = checkBounds(newHead, head);
    }

    snake.push_front(newHead);

    if (newHead.x == food.x && newHead.y == food.y){
        drawTile(newHead.x, newHead.y);
        incScore();
        writeScore();
        scoreTone();
        placeFood();
    }
    else{
        snake.pop_back();
        eraseTile(tail.x, tail.y);
        drawTile(newHead.x, newHead.y);
    }

    display.display();
}

void replay(){
    std::deque<Point> tempEmpty;
    snake = tempEmpty;

    display.clearDisplay();
    initSnake();

    display.setCursor(0, 0);
    display.println(F("SNAKE"));
    display.drawLine(0, 15, 127, 15, SSD1306_WHITE);


    start_game = false;
    game_over = false;
    display.display();

}

void gameOverScreen(){
    display.clearDisplay();
    display.setCursor(SCREEN_WIDTH/2 - 30, SCREEN_HEIGHT/2-12);
    display.println(F("GAME OVER!"));

    display.println(F("Push button to replay"));
    display.display();

}

