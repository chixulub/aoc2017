#include <iostream>

using namespace std;

struct Generator
{
	uint64_t m = 2147483647;
	uint64_t k;
	uint64_t value;
	uint64_t d;
	Generator(uint64_t factor, uint64_t seed, uint64_t divisibleBy)
	: k(factor)
	, value(seed)
	, d(divisibleBy)
	{
	}

	uint64_t operator () ()
	{
		do
		{
			value = (value*k)%m;
		}
		while (value % d);
		return value;
	}
};

int main(int, char**)
{
	Generator A(16807, 783, 4);
	Generator B(48271, 325, 8);
	
	int count = 0;
	for (int i = 0; i < 5000000; ++i)
	{
		count += ((A()&0xffff) == (B()&0xffff));
	}

	cout << count << endl;
	return 0;
}
