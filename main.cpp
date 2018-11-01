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

    LoopContainer<string> lc(4);
    lc.add("test1");
    lc.add("test2");
    lc.add("test3");
    lc.add("test4");
    lc.add("test5");
    for(auto val: lc)
    {
        cout << val << endl;
    }
//    lc.print();

//    cout << lc.get(2) << endl;
    return 0;
}