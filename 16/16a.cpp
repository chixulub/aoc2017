#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string prog = "abcdefghijklmnop";

void spin(int pos)
{
	prog = prog.substr(prog.length()-pos) + prog.substr(0, prog.length()-pos);
}

void exchange(int p0, int p1)
{
	swap(prog[p0], prog[p1]);
}

void partner(char n0, char n1)
{
	int p0 = prog.find_first_of(n0);
	int p1 = prog.find_first_of(n1);
	exchange(p0, p1);
}

int main(int, char**)
{

	string cmd;
	while (cin >> cmd)
	{
		stringstream ss(cmd);
		char c;
		int pos0, pos1;
		char prog0, prog1;
		ss >> c;

		switch (c)
		{
			case 's': 
				ss >> pos0;
				spin(pos0);
				break;
			
			case 'x':
				ss >> pos0 >> c >> pos1;
				exchange(pos0, pos1);
				break;

			case 'p':
				ss >> prog0 >> c >> prog1;
				partner(prog0, prog1);
				break;

			default:
			cout << "Error: cmd = " << cmd << endl;
			exit(-1);
			break;
		}
	}
		
	cout << prog << endl;

	return 0;
}
