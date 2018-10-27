//
// Created by Andrey Gramakov on 27-Oct-18.
//

#ifndef CAG_STREXT_H
#define CAG_STREXT_H

#include <stdint.h>
#include <string>
#include <iostream>
#include <set>
using namespace std;

class strext: public string
{
private:
    set<uint64_t> searched_pos; ///< Vector for dearch results

public:
    strext();
    explicit strext(string in);
    void find_and_replace(string const& find, string const& replace);
    void ltrim(const char* t);
    void rtrim(const char* t);
    void trim(const char* t);
    void search_all(const string& to_find);
    const set<uint64_t> & get_searched_pos();

};

#endif //CAG_STREXT_H
