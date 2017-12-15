#include <iostream>
#include <sstream>
#include <map>
#include <functional>

using namespace std;

int main(int, char**)
{
  string r0, r1, op, _if, cmp;
  int v0, v1;
  int largest = 0;
  string line;

  map<string,int> reg;

  map<string, function<bool(int,int)>> compare = {
    {">",  [](int a, int b){return a>b; }},
    {"<",  [](int a, int b){return a<b; }},
    {">=", [](int a, int b){return a>=b; }},
    {"<=", [](int a, int b){return a<=b; }},
    {"==", [](int a, int b){return a==b; }},
    {"!=", [](int a, int b){return a!=b; }},
  };

  map<string, function<int(int,int)>> operation = {
    {"inc", [](int a, int b) { return a+b; }},
    {"dec", [](int a, int b) { return a-b; }}
  };

  while (getline(cin, line))
  {
    stringstream ss(line);
    ss >> r0 >> op >> v0 >> _if >> r1 >> cmp >> v1;

    if (compare[cmp](reg[r1], v1))
    {
      reg[r0] = operation[op](reg[r0], v0);
      largest = max(largest, reg[r0]);
    }
  }

  cout << largest << endl;

  return 0;
}
