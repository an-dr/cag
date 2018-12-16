//
// Created by Andrey Gramakov on 04-Dec-18.
//
#include "test_LoopContainer.h"

void test_LoopContainer()
{
//    File a;
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
}
