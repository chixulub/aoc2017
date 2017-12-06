#include <iostream>
#include <cmath>

int dim = 100;
int N = 361527;
int* board = nullptr;

#define mem(x,y) board[((y)+dim/2)*dim + ((x)+dim/2)]

int gather(int x, int y)
{
  return 
    mem(x-1,y-1) + 
    mem(x-1,y)   + 
    mem(x-1,y+1) + 
    mem(x,  y-1) + 
    mem(x,  y)   + 
    mem(x,  y+1) + 
    mem(x+1,y-1) + 
    mem(x+1,y)   + 
    mem(x+1,y+1);
}

int main(int, char**)
{
  board = new int[100*100];

  int x = 1, y = 0;

  mem(0,0) = 1;

  int dir[4] = {1,-1,-1,1};
  int orientation = 0;
  int i = 0;
  int val = 1;

  while (val < N)
  {
    mem(x,y) = val = gather(x,y);

    if (std::abs(x) == std::abs(y))
    {
      ++i;
      if (i == 4)
      {
        i = 0;
        ++x;
        --y;
      }
        
      orientation = 1-orientation;
    }

    x += orientation     * dir[i];
    y += (1-orientation) * dir[i];
  }

  std::cout << val << std::endl;
  return 0;
}
