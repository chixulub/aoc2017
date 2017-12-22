#include <iostream>

using namespace std;

struct Generator
{
	uint64_t m = 2147483647;
	uint64_t k;
	uint64_t value;

	Generator(uint64_t factor, uint64_t seed)
	: k(factor)
	, value(seed)
	{
	}

	uint64_t operator () ()
	{
		return value = (value*k)%m;
	}
};

int main(int, char**)
{
	Generator A(16807, 783);
	Generator B(48271, 325);
	
	int count = 0;
	for (int i = 0; i < 40000000; ++i)
	{
		count += ((A()&0xffff) == (B()&0xffff));
	}

	cout << count << endl;
	return 0;
}
