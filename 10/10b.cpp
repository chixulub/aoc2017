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

  string lenstr = "102,255,99,252,200,24,219,57,103,2,226,254,1,0,69,216";
  vector<int> lengths;
  for (char c : lenstr)
  {
    lengths.push_back((int)c);
  }
  lengths.push_back(17);
  lengths.push_back(31);
  lengths.push_back(73);
  lengths.push_back(47);
  lengths.push_back(23);

  int current = 0;
  int skip = 0;

  int values[N];
  for (int i = 0; i < N; ++i)
  {
    values[i] = i;
  }

  for ( int round = 0; round < 64; ++round)
  {
    for (int length : lengths)
    {
      dostuff(values, N, current, length);
      current = (current+length+skip)%N;
      ++skip;
    }
  }

  int dense[16] = {0};

  for (int batch = 0; batch < 16; ++batch)
  {
    for (int bin = 0; bin < 16; ++bin)
    {
      dense[batch] ^= values[batch*16 + bin];
    }
  }

  for (int i = 0; i < 16; ++i)
  {
    printf("%.2x", dense[i]);
  }

  cout << endl;

  return 0;
}
