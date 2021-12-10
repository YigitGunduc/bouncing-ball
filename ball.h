#ifndef BALL_H
#define BALL_H

#include <time.h>
#include <stdio.h>
#include <unistd.h>

#define FILL '@'
#define WIDTH 32
#define RADIUS 3
#define BACKG ' '
#define HEIGHT 64

char board[WIDTH][HEIGHT];
 
typedef struct {
  int x;
  int y;
} vec2;

extern inline void delay(int numOfSec)
{
  int numOfMilliSec = 1000 * numOfSec;
  time_t startTime = clock();
  while(clock() < startTime + numOfMilliSec);
}

extern inline void clear_canvas(void)
{ 
  printf("\033[H\033[J");
}

#endif // BALL_H
