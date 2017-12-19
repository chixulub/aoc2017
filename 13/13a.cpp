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

  int severity = 0;
  for (int t = 0; t < 100; ++t)
  {
    int r = ranges[t];
    if (r == 0) continue;

    int n = (r-1)*2;
    if (t%n == 0)
    {
      cout << "Caught at " << t << endl;
      severity += t * r;
    }
  }

  cout << "Severity = " << severity << endl;

  return 0;
}
