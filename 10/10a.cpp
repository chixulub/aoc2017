#include <iostream>
#include <algorithm>

using namespace std;

void dostuff(int* array, int n, int start, int length)
{
  int a = start;
  int b = start+length-1;

  while(a<b)
  {
    swap(array[a%n], array[b%n]);
    ++a;
    --b;
  }
}

int main(int, char**)
{
  const int N = 256;

  int lengths[] = {102,255,99,252,200,24,219,57,103,2,226,254,1,0,69,216};
  int current = 0;
  int skip = 0;

  int values[N];
  for (int i = 0; i < N; ++i)
  {
    values[i] = i;
  }

  for (int length : lengths)
  {
    dostuff(values, N, current, length);
    current += length+skip;
    ++skip;
  }

  cout << values[0] * values[1] << endl;

  return 0;
}
