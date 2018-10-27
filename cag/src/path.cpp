//
// Created by Andrey Gramakov on 09/10/2018.
//

#include "path.h"

/// @brief default constructor
Path::Path()
        :raw_path(""), synt_path("") { }

/// @brief A copy constructor
/// \param other
Path::Path(const Path& other)
{
    this->raw_path = other.raw_path;
    this->synt_path = other.synt_path;
    this->path_container = other.path_container;
}

/// @brief Constructor
/// \param path_str
Path::Path(const string& path_str)
        :raw_path(path_str)
{
    pathstr_analysis();
    pathstr_synthesis();
}

Path& Path::operator=(const Path& other)
{
    this->raw_path = other.raw_path;
    this->synt_path = other.synt_path;
    this->path_container = other.path_container;
    return *this;
}

/// @brief Disasemles raw_string to a vector
/// \return
bool Path::pathstr_analysis()
{
    set<uint64_t> find_positions;
    string path_str = raw_path;
    line_tool::find_and_replace(path_str, "\\\\", "\\");
    line_tool::search_all(path_str, "\\", find_positions);
    line_tool::search_all(path_str, "/", find_positions);
    uint64_t cur_start = 0;
    string path_part;
    for (auto f_it : find_positions)
    {
        path_part = path_str.substr(cur_start, (f_it-cur_start));
        path_container.push_back(path_part);
        cur_start = f_it+1;
    }
    path_part = path_str.substr(cur_start); //the last part
    path_container.push_back(path_part);
}

/// @brief creates string from vector
/// \return
bool Path::pathstr_synthesis()
{
    synt_path.erase();
    for (const auto& path_part: path_container)
    {
        synt_path += path_part+"/";
    }
    return true;
}

string Path::get_string() const
{
    return synt_path;
}

ostream& operator<<(ostream& out, const Path& p)
{
    return (out << p.synt_path);
}
