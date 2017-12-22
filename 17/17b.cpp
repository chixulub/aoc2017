#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;
};

Node* insert(Node* current, int value)
{
	Node* node = new Node();

	node->next = current->next;
	current->next = node;
	node->value = value;

	return node;
}

int main(int, char**)
{
	Node* current = new Node();
	current->value = 0;
	current->next = current;
	
	int step = 354;

	for (int i = 1; i <= 50000000; ++i)
	{
		for (int k = 0; k < step; ++k)
		{
			current = current->next;
		}

		if (current->value == 0)
		{
			cout << "-> " << i << endl;
		}

		current = insert(current, i);
	}

	while (current->value != 0)
	{
		current = current->next;
	}

	cout << current->next->value << endl;

	return 0;
}
