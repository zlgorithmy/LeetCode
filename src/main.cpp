#include "include.h"
#include <iostream>

#include "config.h"

#ifdef USE_MYMATH
#include "Utility/utility.h"
#endif

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc < 3)
	{
		cout << argv[0] << " version:" << LEETCODE_VERSION_MAJOR << "."
			 << LEETCODE_VERSION_MINOR << endl;
		return 0;
	}
	auto a = atoi(argv[1]);
	auto b = atoi(argv[2]);
	cout << "max(" << a << ", " << b << ") is " << mmax(a, b) << "." << endl;
	test1();
	return 0;
}
