#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILL '.'
#define WIDTH 32
#define RADIUS 3
#define BACKG ' '
#define HEIGHT 64
#define NUM_OF_PARTICLES 10

char board[WIDTH][HEIGHT];

typedef struct {
  int x;
  int y;
} vec2;

vec2 centers[NUM_OF_PARTICLES];
vec2 speeds[NUM_OF_PARTICLES];

void delay(int numOfSec)
{
  int numOfMilliSec = 1000 * numOfSec;
  time_t startTime = clock();
  while(clock() < startTime + numOfMilliSec);
}

void init_paticles(void)
{
  srand(time(NULL));   // Initialization, should only be called once.
  for (int i = 0; i < NUM_OF_PARTICLES; i++)
  {
    centers[i].x =  rand() % WIDTH;
    centers[i].y =  rand() % HEIGHT;

    speeds[i].x = 1;
    speeds[i].y = 1;
  }
}

void clear_canvas(void)
{ 
  printf("\033[H\033[J");
}

void update_canvas(void)
{
  for (int i = 0; i <= WIDTH; i++)
  {
    for (int j = 0; j <= HEIGHT; j++)
    {
      board[i][j] = BACKG;
    }
  }

  for (int j = 0; j < NUM_OF_PARTICLES; j++)
  {
    if (centers[j].y <= HEIGHT && centers[j].x <= WIDTH) {
      board[centers[j].x][centers[j].y] = FILL;
    } 
  }
}

void draw_canvas(void)
{
  for (int i = 0; i <= WIDTH; i++)
  {
    for (int j = 0; j < HEIGHT; j++)
    {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

void step(void)
{
  for (int i = 0; i < NUM_OF_PARTICLES; i++)
  {
    int center_x = centers[i].x;
    int center_y = centers[i].y;

    if (center_x > WIDTH || center_x < 0)
    {
      speeds[i].x *= -1;
    }

    if (center_y > HEIGHT || center_y < 0)
    {
      speeds[i].y *= -1;
    }
    centers[i].x += speeds[i].x;
    centers[i].y += speeds[i].y;
  }
}

void run(void)
{
  init_paticles();
  for (;;)
  {
    update_canvas();
    draw_canvas();
    step();
    delay(100);
    clear_canvas();
  }
}

int main(void)
{
  run();
  return 0;
}
