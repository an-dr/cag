//
// Created by Andrey Gramakov on 09/10/2018.
//

#include "../inc/path.h"

Path::Path()
        :raw_path(""), synt_path("") { }

Path::Path(const string& path_str)
        :raw_path(path_str)
{
    pathstr_analysis(raw_path);
}

bool Path::pathstr_analysis(string path_str)
{
    set<uint64_t> find_positions;
    line_tool::find_and_replace(path_str, "\\\\", "\\");
    line_tool::search_all(path_str, "\\", find_positions);
    line_tool::search_all(path_str, "/", find_positions);
    uint64_t cur_start = 0;
    string path_part;
    for(auto f_it : find_positions)
    {
        path_part = path_str.substr(cur_start, (f_it - cur_start));
        path_container.push_back(path_part);
        cur_start = f_it + 1;
    }
    path_part = path_str.substr(cur_start); //the last part
    path_container.push_back(path_part);
}

bool Path::pathstr_synthesis(vector<string> path_list)
{
    synt_path.erase();
    for(auto path_part: path_list)
    {
        synt_path += path_part + "/";
    }
    return true;
}

void Path::get_string(string& to_write)
{
    if(pathstr_synthesis(path_container))
    {
        to_write = synt_path;
    }

}
