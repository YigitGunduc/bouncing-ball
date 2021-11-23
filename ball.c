#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 8
#define HEIGHT 16
#define RADIUS 3



void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
      write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

char board[WIDTH][HEIGHT];

typedef struct {
  int x;
  int y;
} pos;

pos ball_center = {.x = 2, .y = 2};
pos ball_speed = {.x = 2, .y = 2};

void update_canvas(void)
{
  for (int i = 0; i < WIDTH; i++)
  {
    for (int j = 0; j < HEIGHT; j++)
    {
      board[i][j] = '.';
    }
  }
  board[ball_center.x][ball_center.y] = 'x';
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
  if (ball_center.x >= WIDTH)
  {
    ball_speed.x *= -1;
  }

  if (ball_center.y >= HEIGHT)
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
  //draw_canvas();
  printf("\n");
  printf("x: %i, y: %i", ball_center.x, ball_center.y);
  step();
  sleep(1);
  }
}


int main(void)
{
  
  run();
  // printf("x : %i\n", ball_center.x);


  return 0;
}
