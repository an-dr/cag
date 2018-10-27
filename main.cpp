//
// Created by Andrey Gramakov on 09/10/2018.
//

#include <iostream>
#include "line_tool.h"
#include "path.h"
#include "Strext.h"

using namespace std;

int main()
{

    string s1 = "D:\\asdas\\config.ini";
    string s2 = "A:\\asdas\\config.ini";
    Path p1(s1);
    Path p2;
    p2 = s2;

//    a.Write("1234\n321\nqwerty");
//    Strext a("123412312");
//    a.find_and_replace("23", "__");
    cout << p1.get_string() << endl;
    cout << p2.get_string() << endl;
    return 0;
}