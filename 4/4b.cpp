#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int main(int, char**)
{
	int valid = 0;

	string line;

	while (getline(cin, line))
	{
		set<string> words;
		stringstream ss(line);
		cout << line << endl;

		string word;
		while (ss >> word)
		{
			sort(word.begin(), word.end());

			if (words.count(word))
			{
				--valid;
				break;
			}

			words.insert(word);
		}

		++valid;
	}

	cout << valid << endl;
	return 0;
}
