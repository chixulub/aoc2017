#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>

int main(int, char**)
{
	std::string line;
	int sum = 0;

	while (getline(std::cin, line))
	{
		std::stringstream ss(line);
		std::vector<int> nums;
		int n;
		while (ss >> n)
		{
			nums.push_back(n);
		}

		bool keepGoing = true;

		for (size_t i = 0; keepGoing && i < nums.size()-1; ++i)
		{
			for (size_t j = i+1; keepGoing && j < nums.size(); ++j)
			{
				int a = nums[i];
				int b = nums[j];

				if (a%b == 0)
				{
					sum += a/b;
					keepGoing = false;

					std::cout << a << "/" << b << " = " << a/b << std::endl;
					break;
				}
				if (b%a == 0)
				{
					sum += b/a;
					std::cout << b << "/" << a << " = " << b/a << std::endl;
					keepGoing = false;
					break;
				}
			}
		}
	}

	std::cout << sum << std::endl;

	return 0;
}
