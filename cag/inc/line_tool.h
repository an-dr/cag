//
// Created by Andrey Gramakov on 10/12/2018.
//

#ifndef CAG_LINE_TOOL_H
#define CAG_LINE_TOOL_H

#include <string.h>
#include <list>
#include <map>

using namespace std;

// trim from left
inline void ltrim(string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
}

// trim from right
inline void rtrim(string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
}

// trim from left & right
inline void trim(string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    s.erase(s.find_last_not_of(t) + 1);
}

class line_tool
{
public:
    static void split_line(string& in, string delim, pair<string,string>& out, unsigned long long int line_start=0);
    static void get_lines(string& in, list<string>& out);
private:

};

#endif //CAG_LINE_TOOL_H
