//
// Created by Andrey Gramakov on 27-Oct-18.
//

#include "Strext.h"

strext::strext()
{
    cout << "epmty" << endl;
}

strext::strext(string in)
        :string(std::move(in))
{
}

void strext::find_and_replace(string const& find, string const& replace)
{
    for (string::size_type i = 0; (i = this->find(find, i))!=string::npos;)
    {
        this->replace(i, find.length(), replace);
        i += replace.length();
    }
}

void strext::ltrim(const char* t = " \t\n\r\f\v")
{
    this->erase(0, this->find_first_not_of(t));
}

// trim from right
void strext::rtrim(const char* t = " \t\n\r\f\v")
{
    this->erase(this->find_last_not_of(t)+1);
}

// trim from left & right
void strext::trim(const char* t = " \t\n\r\f\v")
{
    this->erase(0, this->find_first_not_of(t));
    this->erase(this->find_last_not_of(t)+1);
}

void strext::search_all(const string& to_find)
{
    searched_pos.clear();
    uint64_t l_cur = 0;
    while (l_cur!=string::npos)
    {
        l_cur = this->find(to_find, l_cur);
        if (l_cur!=string::npos)
        {
            searched_pos.insert(l_cur);
            l_cur += to_find.length();
        }
    }
}

const set<uint64_t>& strext::get_searched_pos()
{
    return searched_pos;
}
