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
    string input;
    string output;
    input = R"(C:\windows\system32\\drivers/123)";
    Path p(input);
    p.get_string(output);
    return 0;
}