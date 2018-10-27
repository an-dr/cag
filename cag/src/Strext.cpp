//
// Created by Andrey Gramakov on 27-Oct-18.
//

#include <Strext.h>

#include "Strext.h"

Strext::Strext()
{
    cout << "epmty" << endl;
}

Strext::Strext(string in)
        :string(std::move(in))
{
}

void Strext::find_and_replace(string const& find, string const& replace)
{
    for (string::size_type i = 0; (i = this->find(find, i))!=string::npos;)
    {
        this->replace(i, find.length(), replace);
        i += replace.length();
    }
}

void Strext::ltrim(const char* t = " \t\n\r\f\v")
{
    this->erase(0, this->find_first_not_of(t));
}

// trim from right
void Strext::rtrim(const char* t = " \t\n\r\f\v")
{
    this->erase(this->find_last_not_of(t)+1);
}

// trim from left & right
void Strext::trim(const char* t = " \t\n\r\f\v")
{
    this->erase(0, this->find_first_not_of(t));
    this->erase(this->find_last_not_of(t)+1);
}

void Strext::search_all(const string& to_find)
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

set<uint64_t>& Strext::get_searched_pos()
{
    return searched_pos;
}
