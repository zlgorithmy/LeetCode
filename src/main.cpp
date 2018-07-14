#include <iostream>

#include "../build/Config.h"

#ifdef USE_MYMATH
#include "MathFunctions/math.h"
#endif

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "main test."
         << "version:" << LEETCODE_VERSION_MAJOR << "." << LEETCODE_VERSION_MINOR
         << endl;
    cout << "max(2,6)" << max(2, 6) << endl;
    auto d = max(2, 6);
    return 0;
}
