//
// Created by Andrey Gramakov on 09/10/2018.
//

#ifndef CAG_PATH_H
#define CAG_PATH_H
#include <ostream>
#include <set>
#include <vector>
#include <string>
#include "line_tool.h"

class Path
{
private:
    string raw_path;
    string synt_path;
    vector<string> path_container;
    bool pathstr_analysis(string path_str);
    bool pathstr_synthesis(vector<string> path_list);


public:
    Path(); // empty constructor
    explicit Path(const string& path_str); // init constructor
    Path(const Path& other); // copy constructor
    const Path& operator=(const Path& other);
    void get_string(string& to_write);
};

ostream& operator<<(ostream& out, const Path& p);

#endif //CAG_PATH_H
