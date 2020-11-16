//
// Created by Andreas on 16.11.2020.
//

#ifndef SOME_GAME_MAYBE_SNAKE_H
#define SOME_GAME_MAYBE_SNAKE_H

typedef struct Body
{
    int tailX;
    int tailY;
    bool head;
} snake ;

int CheckFruit(snake* tail,int x,int y);

void Fruit(snake* tail);

void SnakeDirection();

void Movement(snake* tail);

int CheckTail(snake* tail,int i, int j);

void Draw(snake* tail);

snake* TailFunction(snake* tail);

void GameEnd(snake* tail);

#endif //SOME_GAME_MAYBE_SNAKE_H
