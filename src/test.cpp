#include "include.h"
#include <iostream>

using namespace std;

void testCmake()
{
#ifdef HAVE_MAX
    cout << "have max..." << endl;
#else
    cout << "have no max..." << endl;
#endif
}

void test1()
{
    Solution1 s;
    vector<int> v = {1, 2, 7};
    auto re = s.twoSum(v, 3);
    for (auto i : re)
    {
        cout << i << endl;
    }
}