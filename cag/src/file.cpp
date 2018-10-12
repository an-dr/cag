#include <utility>

#include <utility>

//
// Created by Andrey Gramakov on 09/10/2018.
//

#include "../inc/file.h"

/// \brief Constructor
/// \param path
File::File(string path):
file_path(std::move(path))
{

}

/// \brief Opens file with specific mode
/// \param mode
/// \return bool result
bool File::Open(ios::openmode mode)
{
    this->file.open(this->file_path, mode); // open a file
    return this->file.is_open(); // return a result
}

/// \breaf Closes a file
/// \return bool result
bool File::Close()
{
    if (this->file.is_open())
    {
        this->file.close();
        return true;
    }
    else
    {
        return false;
    }
}

/// \breaf Read a file and returns a string
/// \return readed string
string File::Read()
{
    if(this->Open(ios::in))
    {
        string r; ///< result of reading
        string line; ///< readed line
        while(this->file)
        {
            getline(this->file, line);
            r = r + line + "\n";
        }
        this->Close();
        return r;
    }
    else
        throw file_exc_nofile();
}

///
/// \param to_file this string will written to a file instead of old content
/// \return
bool File::Write(string to_file)
{
    if(this->Open(ios::out))
    {
        this->file << to_file << endl;
        this->Close();
    }
}

/// \breaf an exception for a non-existing file
/// \return
const char* file_exc_nofile::what() const throw()
{
    return "File is not exists";
}