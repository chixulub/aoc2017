#include <iostream>
#include <map>
#include <cmath>

using namespace std;

struct Step
{
  int x, y, z;
};

int main(int, char**)
{
  map<string,Step> directions = {
    {"n",  { 0, 1,-1}},
    {"s",  { 0,-1, 1}},
    {"ne", { 1, 0,-1}},
    {"sw", {-1, 0, 1}},
    {"nw", {-1, 1, 0}},
    {"se", { 1,-1, 0}}
  };

  string dir;
  int x = 0, y = 0, z = 0;
  int distance = 0;
  while (cin >> dir)
  {
    auto s = directions[dir];
    x += s.x;
    y += s.y;
    z += s.z;
    distance = max(distance, (abs(x)+abs(y)+abs(z))/2);
  }

  cout << distance << endl;

  return 0;
}
