//
// Created by Andrey Gramakov on 09/10/2018.
//

#include "path.h"

/// @brief default constructor
Path::Path()
        :path_str("") { }

/// @brief A copy constructor
/// \param other
Path::Path(const Path& other)
{
    this->path_str = other.path_str;
}

/// @brief Constructor
/// \param path_str
Path::Path(const string& path_str)
        :path_str(path_str)
{
    pathstr_analysis();
    pathstr_synthesis();
}

Path& Path::operator=(const Path& other)
{
    this->assign(other.path_str);
    return *this;
}


Path& Path::operator=(const string& other)
{
    this->assign(other);
    return *this;
}

void Path::assign(const string & new_val) {
    path_str = new_val;
    pathstr_analysis();
    pathstr_synthesis();
}

/// @brief Disasemles raw_string to a vector
/// \return
bool Path::pathstr_analysis()
{
    path_str.find_and_replace("\\\\", "\\");
    path_str.find_and_replace("\\", "/");
    path_str.rtrim("/");
    path_str.search_all("/");
    uint64_t cur_start = 0;
    string path_part;
    for (auto f_it : path_str.get_searched_pos())
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
    path_str.erase();
    for (const auto& path_part: path_container)
    {
        path_str += path_part+"/";
    }
    path_str.rtrim("/");
    path_container.clear();
    return true;
}

Strext Path::get_string() const
{
    return path_str;
}

ostream& operator<<(ostream& out, const Path& p)
{
    return (out << p.path_str);
}
