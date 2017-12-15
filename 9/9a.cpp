#include <iostream>

using namespace std;

char ignore;

void skipGarbage()
{
  char symbol;

  for(;;)
  {
    cin >> symbol;

    switch (symbol)
    {
      case '!':
        cin >> ignore;
        break;
      case '>':
        return;
      default:
        break;
    }
  }

  return;
}

int main(int, char**)
{
  char symbol;

  int current = 0;
  int total = 0;

  while (cin >> symbol)
  {
    switch (symbol)
    {
      case '<':
        skipGarbage();
        break;

      case '{':
        ++current;
        break;

      case '}':
        total += current;
        --current;

      default:
        break;
    }
  }

  cout << total << endl;

  return 0;
}
