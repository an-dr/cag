//
// Created by Andrey Gramakov on 10/12/2018.
//

#include "../inc/line_tool.h"

///
/// \param in
/// \param delim
/// \param out
/// \param line_start
void line_tool::split_line(string& in, string delim, pair<string, string>& out, unsigned long long int line_start)
{
    unsigned long long int pA_start , pA_end;
    unsigned long long int pB_start;

    pA_start = line_start;
    pA_end = in.find(delim, pA_start);
    pB_start = pA_end + delim.length();
    string pA =in.substr(pA_start, pA_end-pA_start);
    string pB =in.substr(pB_start);
    trim(pA);
    trim(pB);
    out.first = pA;
    out.second = pB;

}

///
/// \param in
/// \param out
void line_tool::get_lines(string& in, list<string>& out)
{
    string line;
    unsigned long long int l_start_cur = 0;
    unsigned long long int l_search_cur = in.find('\n', l_start_cur);
    unsigned long long int nf = 18446744073709551615U;
    while (l_search_cur!=nf)
    {
        line = in.substr(l_start_cur, l_search_cur-l_start_cur);
        out.push_back(line);
        l_start_cur = l_search_cur+1;
        l_search_cur = in.find('\n', l_start_cur);
    }
}
