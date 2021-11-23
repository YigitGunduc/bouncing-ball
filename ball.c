#include <stdio.h>

#define WIDTH 8
#define HEIGHT 8
#define RADIUS 3

char board[WIDTH][HEIGHT];

typedef struct {
  int x;
  int y;
} pos;

pos ball_center = {.x = 2, .y = 2};

void compute_ball_pos(void)
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


int main(void)
{
  puts("start");
  compute_ball_pos();
  
  for (int i = 0; i < WIDTH; i++)
  {
    for (int j = 0; j < HEIGHT; j++)
    {
    printf("%c", board[i][j]);
    }
    printf("\n");
  }
  // printf("x : %i\n", ball_center.x);


  return 0;
}
