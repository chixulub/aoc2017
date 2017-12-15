#include <iostream>

using namespace std;

char ignore;

int countGarbage()
{
  int count = 0;
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
        return count;
      default:
        ++count;
        break;
    }
  }

  return count;
}

int main(int, char**)
{
  char symbol;

  int count = 0;

  while (cin >> symbol)
  {
    switch (symbol)
    {
      case '<':
        count += countGarbage();
        break;
      default:
        break;
    }
  }

  cout << count << endl;

  return 0;
}
