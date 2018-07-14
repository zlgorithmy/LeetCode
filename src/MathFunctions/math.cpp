#include <iostream>

using namespace std;
int max(int a, int b)
{
    cout << "max..." << endl;
    auto ret = a > b ? a : b;
    return ret;
}