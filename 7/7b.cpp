#include <iostream>
#include <sstream>
#include <set>
#include <map>

using namespace std;

struct Node
{
	int weight = 0;
	int totalWeight = -1;
	std::set<Node*> children;
};

int calcTotalWeight(Node* node)
{
	int total = node->weight;
	for (Node* child : children)
	{
		total += calculateTotalWeight(child);
	}

	node->totalweight = total;
	return total;
}

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
		else
		{
		}

		if (nopes.count(parent) == 0)
		{
			maybes.insert(parent);
		}
	}

	cout << *maybes.begin() << endl;

	return 0;
}
