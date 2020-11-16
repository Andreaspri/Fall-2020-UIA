#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "snake.h"
#include "snake.c"



int main() {
    snake* tail = malloc(sizeof(snake));

    tail->head = true;
    tail->tailX = width/2;
    tail->tailY = height/2;
    srand(time(0));
    Fruit(tail);

    while (!GameOver)
    {
        Draw(tail);
        tail = TailFunction(tail);
        SnakeDirection();
        Movement(tail);
        Fruit(tail);
        usleep(55555);
        GameEnd(tail);
        system("cls");
    }
    free(tail);
    printf("Game Over\n");
    printf("Final score: %i\n",score);
    system("pause");
    system("pause");
    system("pause");


    return 0;
}
