#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILL '@'
#define WIDTH 32
#define RADIUS 3
#define BACKG ' '
#define HEIGHT 64

static char board[WIDTH][HEIGHT];

typedef struct {
  int x;
  int y;
} vec2;

static vec2 ball_center = {.x = 16, .y = 8};
static vec2 ball_speed = {.x = -2, .y = -2};

void delay(int numOfSec)
{
  int numOfMilliSec = 1000 * numOfSec;
  time_t startTime = clock();
  while(clock() < startTime + numOfMilliSec);
}

void clear_canvas(void)
{ 
  printf("\033[H\033[J");
}

void draw_ball(void)
{
  for(int row = 0; row < WIDTH; row++)
  {
    for(int col = 0; col < HEIGHT; col++)
    {
      int x = col - (HEIGHT / 2);
      int y = (WIDTH / 2) - row;
      int sum = (x*x) + (y*y);

      if((RADIUS * RADIUS - 4 < sum) && (sum < RADIUS * RADIUS + 4))
      {
        int xpos = ball_center.x + x;
        int ypos = ball_center.y + y;
        if (0 < xpos && xpos < WIDTH && 0 < ypos && ypos < HEIGHT) {
          board[xpos][ypos] = FILL;
        }
      }
    }
  }
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
  draw_ball();
}

void draw_canvas(void)
{
  for (int i = 0; i < WIDTH; i++)
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
  if (ball_center.x >= WIDTH || ball_center.x <= 0)
  {
    ball_speed.x *= -1;
  }

  if (ball_center.y >= HEIGHT || ball_center.y <= 0)
  {
    ball_speed.y *= -1;
  }
  ball_center.x += ball_speed.x;
  ball_center.y += ball_speed.y;
}

void run(void)
{
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
