#include <iostream>
#include <set>

using namespace std;
struct State {
  char mem[16];

  char& operator [] (int n)
  {
    return mem[n];
  }
  
  char const& operator [] (int n) const
  {
    return mem[n];
  }
};

bool operator < (State const& a, State const& b)
{
  for (int i = 0; i < 16; ++i)
  {
    if (a[i] < b[i]) return true;
    if (b[i] < a[i]) return false;
  }
  return false;
}

int maxBucketIndex(State const& state)
{
  int bestI = 0;
  int best = state[0];

  for (int i = 1; i < 16; ++i)
  {
    if (state[i] > best)
    {
      bestI = i;
      best = state[i];
    }
  }

  return bestI;
}

int main(int, char**)
{
  std::set<State> states;
  State state;
  for (int i = 0; i < 16; ++i)
  {
    int n;
    cin >> n;
    state[i] = (char)n;
  }
  
  states.insert(state);

  int count = 0;
  while(true)
  {
    ++count;
    int i = maxBucketIndex(state);

    int n = state[i];
    state[i] = 0;

    while(n > 0)
    {
      i = (i+1)%16;
      ++state[i];
      --n;
    }

    if (states.count(state))
    {
      break;
    }

    states.insert(state);
  }

  std::cout << count << std::endl;

  return 0;
}
