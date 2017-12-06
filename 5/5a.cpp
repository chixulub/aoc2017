#include <iostream>
#include <vector>

using namespace std;


int main(int, char**)
{
	vector<int> prog;
	int i;
	int j = 0;

	while (cin >> i)
	{
		prog.push_back(i);
	}

	i = 0;
	while (0 <= i && i < (int)prog.size())
	{
		++j;
		++prog[i];
		i += prog[i] - 1;
	}

	cout << j << endl;

	return 0;
}
