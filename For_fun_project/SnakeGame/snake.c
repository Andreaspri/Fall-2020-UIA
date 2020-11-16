//
// Created by Andreas on 16.11.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <conio.h>




int score = -10;
const int height = 35;
const int width = 50;
char array[1][35][50] = {0};
int fruitX, fruitY;
bool GameOver = false;
enum direction { stop, left, right, up, down};
enum direction dir;



int CheckFruit(snake* tail,int x,int y)
{
    for (int i = score/10;i>=0;i--)
        if ((tail+i)->tailX == x && (tail+i)->tailY == y)
            return 5;
    return 4;
}

void Fruit(snake* tail)
{
    if (tail->tailX == fruitX && tail->tailY == fruitY || score/10 == -1)
    {

        while (true){
            fruitX = rand() % (width-2);
            fruitY = rand() % (height-2);
            if (fruitX == 0)
                fruitX++;
            if (fruitY == 0)
                fruitY++;
            if (width/2 % 2 == 1)
            {
                if (fruitX % 2 == 1 && CheckFruit(tail,fruitX,fruitY) == 4)
                    break;
            }
            else if (width/2 % 2 == 0)
            {
                if (fruitX % 2 == 0 && CheckFruit(tail,fruitX,fruitY) == 4)
                    break;
            }
        }
        score += 10;
    }

}

void SnakeDirection()
{
    if(kbhit()){
        switch (getch())
        {
            case 'w':
                if (dir == down)
                    break;
                dir = up;
                break;
            case 's':
                if (dir == up)
                    break;
                dir = down;
                break;
            case 'a':
                if (dir == right)
                    break;
                dir = left;
                break;
            case 'd':
                if (dir == left)
                    break;
                dir = right;
                break;
            case 'x':
                dir = stop;
                break;
        }
    }
}

void Movement(snake* tail)
{
    if (dir == up)
        tail->tailY-=1;
    else if (dir == down)
        tail->tailY+=1;
    else if (dir == left)
        tail->tailX-=2;
    else if (dir == right)
        tail->tailX+=2;
}

int CheckTail(snake* tail,int i, int j)
{
    for (int k=0; k <= score/10 ;k++) {
        if ((tail + k)->tailX == j && (tail + k)->tailY == i && (tail + k)->head == true)
            return 1;
        else if ((tail + k)->tailX == j && (tail + k)->tailY == i)
            return 2;
    }
    return 3;
}

void Draw(snake* tail)
{
    printf("\t\tScore: %i\n",score);
    for (int i=0; i < height; i++)
    {
        for (int j=0; j < width;j++) {

            if (j == 0 || j == width - 2 || (i == 0 && j != width-1) || (i == height - 1 && j != width-1))
                array[0][i][j] = '#';
            else if (j == width -1)
                array[0][i][j] = '\n';
            else if (CheckTail(tail, i, j) == 2)
                array[0][i][j] = 'o';
            else if (CheckTail(tail,i,j) == 1)
                array[0][i][j] = 'O';

            else if (fruitX == j && fruitY == i)
                array[0][i][j] = 'F';
            else
                array[0][i][j] = ' ';
        }
    }
    printf("%s",array[0]);
    memset(array,0,sizeof(array));
}

snake* TailFunction(snake* tail)
{
    tail = (snake*) realloc(tail,sizeof(snake)*(score/10+1));
    for (int i=score/10;i>0;i--)
    {
        (tail+i)->tailX = (tail+(i-1))->tailX;
        (tail+i)->tailY = (tail+(i-1))->tailY;
        (tail+i)->head = false;
    }
    return tail;
}

void GameEnd(snake* tail)
{
    if (tail->tailX <= 0 || tail->tailX >= width-2)
        GameOver = true;
    else if (tail->tailY <= 0 || tail->tailY >= height-1)
        GameOver = true;
    for (int i=1;i<=score/10;i++)
    {
        if (tail->tailX == (tail+i)->tailX && tail->tailY == (tail+i)->tailY)
            GameOver = true;
    }

}

