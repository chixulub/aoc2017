#include <iostream>

using namespace std;

int main(int, char**)
{
  int depth, range;
  string trash;

  int ranges[100] = {0};
  while (cin >> depth >> trash >> range)
  {
    ranges[depth] = range;
  }

  int delay = 0;
  bool caught = true;
  for (;caught;++delay)
  {
    caught = false;
    for (int t = 0; t < 100; ++t)
    {
      int r = ranges[t];
      if (r == 0) continue;

      int n = (r-1)*2;
      if ((t+delay)%n == 0)
      {
        caught = true;
        break;
      }
    }

    if (!caught)
      cout << "Delay = " << delay << endl;
  }


  return 0;
}
