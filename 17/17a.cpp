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

	for (int i = 1; i < 2018; ++i)
	{
		for (int k = 0; k < step; ++k)
		{
			current = current->next;
		}

		current = insert(current, i);
	}

	cout << current->next->value << endl;

	return 0;
}
