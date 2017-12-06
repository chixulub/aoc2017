#include <iostream>
#include <sstream>
#include <cmath>

int main(int, char**)
{
	std::string line;
	int sum = 0;
	while (getline(std::cin, line))
	{
		std::stringstream ss(line);
		int n;
		ss >> n;
		int _min = n;
		int _max = n;

		while (ss >> n)
		{
			_min = std::min(n, _min);
			_max = std::max(n, _max);
		}

		sum += _max - _min;
	}

	std::cout << sum << std::endl;

	return 0;
}
