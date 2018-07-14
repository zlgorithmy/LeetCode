#include <iostream>

#include "../build/config.h"

#ifdef USE_MYMATH
#include "MathFunctions/math.h"
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

    cout << "max(" << a << ", " << b << ") is " << mmax(a, b) << "." << endl;
    return 0;
}
