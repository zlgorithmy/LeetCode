#include "include.h"
#include <iostream>

#include "config.h"

#ifdef USE_MYMATH
#include "Utility/utility.h"
#endif

using namespace std;

int main(int argc, char const *argv[])
{
#ifdef HAVE_MAX
	cout << "have max..." << endl;
#else
	cout << "have no max..." << endl;
#endif
	if (argc < 3)
	{
		cout << argv[0] << " version:" << LEETCODE_VERSION_MAJOR << "."
			 << LEETCODE_VERSION_MINOR << endl;
		return 0;
	}

	auto a = atoi(argv[1]);
	auto b = atoi(argv[2]);

	Solution1 s;
	vector<int> v = {1,2,7};
	auto re = s.twoSum(v,3);
	for(auto i:re)
	{
		cout<<i<<endl;
	}
	cout << "max(" << a << ", " << b << ") is " << mmax(a, b) << "." << endl;
	return 0;
}
