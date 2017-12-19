#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <set>

using namespace std;

set<int> visited;
map<int, list<int>> connections;

void visitFrom(int n)
{
  if (visited.count(n) == 0)
  {
    visited.insert(n);

    for (int child : connections[n])
    {
      visitFrom(child);
    }
  }
}

int main(int, char**)
{
  string line;
  string slask;


  while (getline(cin, line))
  {
    stringstream ss(line);

    int parent, child;
    ss >> parent >> slask;

    while (ss >> child)
    {
      connections[parent].push_back(child);
    }
  }

  visitFrom(0);

  cout << visited.size() << endl;

  return 0;
}
