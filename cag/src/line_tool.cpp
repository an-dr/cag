//
// Created by Andrey Gramakov on 10/12/2018.
//

#include "../inc/line_tool.h"

///
/// \param in
/// \param delim
/// \param out
/// \param line_start
bool line_tool::split_line(string& in, string delim, pair<string, string>& out, unsigned long long int line_start)
{
    uint64_t pA_start, pA_end;
    uint64_t pB_start;

    string pA, pB;
    pA_start = line_start;
    pA_end = in.find(delim, pA_start);
    if (pA_end==string::npos)
        return false;
    pB_start = pA_end+delim.length();
    pA = in.substr(pA_start, pA_end-pA_start);
    pB = in.substr(pB_start);
    trim(pA);
    trim(pB);
    out.first = pA;
    out.second = pB;
    return true;

}

///
/// \param in
/// \param out
void line_tool::get_lines(string& in, list<string>& out)
{
    string line;
    uint64_t l_start_cur = 0;
    uint64_t l_search_cur = in.find('\n', l_start_cur);
    while (l_search_cur!=string::npos)
    {
        line = in.substr(l_start_cur, l_search_cur-l_start_cur);
        out.push_back(line);
        l_start_cur = l_search_cur+1;
        l_search_cur = in.find('\n', l_start_cur);
    }
}

void line_tool::search_all(const string& str_in, const string& to_find, set<uint64_t>& result_pos)
{
    uint64_t l_cur = 0;
    while(l_cur != string::npos)
    {
        l_cur = str_in.find(to_find, l_cur);
        if(l_cur != string::npos)
        {
            result_pos.insert(l_cur);
            l_cur += to_find.length();
        }
    }
}

void line_tool::find_and_replace(string& source, string const& find, string const& replace)
{
    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}
