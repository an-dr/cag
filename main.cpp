//
// Created by Andrey Gramakov on 09/10/2018.
//

#include <iostream>
#include <string>

//#include "test_LoopContainer.h"
#include "test_cagmath.h"

using namespace std;

int main()
{

#ifdef TEST_LOOPCOUNTER_H
    test_LoopContainer();
#endif

#ifdef TEST_CAGMATH_H
    test_cagmath();
#endif

    return 0;
}