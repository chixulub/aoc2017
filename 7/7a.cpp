#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main(int, char**)
{
	set<string> nopes;
	set<string> maybes;

	string line, parent, weight, arrow, child;

	while (getline(cin, line))
	{
		stringstream ss(line);

		ss >> parent >> weight;

		if (ss >> arrow)
		{
			while (ss >> child)
			{
				if (child.back() == ',')
					child.pop_back();

				nopes.insert(child);
				maybes.erase(child);
			}
		}

		if (nopes.count(parent) == 0)
		{
			maybes.insert(parent);
		}
	}

	cout << *maybes.begin() << endl;

	return 0;
}
