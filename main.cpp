//
// Created by Andrey Gramakov on 09/10/2018.
//

#include <iostream>
#include <string>
#include "line_tool.h"
#include "path.h"
#include "Strext.h"
#include "LoopContainer.h"


using namespace std;

int main()
{

    LoopContainer<string> lc(5);
    lc.add("1");
    lc.add("2");
    lc.add("3");
    lc.add("4");
    lc.add("5");
    lc.shift_r(2);

    lc.print();


    cout << endl;

    lc.shift_l(1);
    lc.print();
    return 0;
}