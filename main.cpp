//
// Created by Andrey Gramakov on 09/10/2018.
//

#include <iostream>
#include "cag/cag.h"

using namespace std;

int main()
{

//    string path = "config.ini";
//    File a(path);
//    a.Write("1234\n321\nqwerty");
    string input = "abc :: 10 ";
    pair<string, string> pr;
    line_tool::split_line(input, "::",pr);
    return 0;
}