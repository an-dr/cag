#include <utility>

//
// Created by Andrey Gramakov on 09/10/2018.
//

#include "../inc/file.h"

File::File(string path)
{
    this->file_path = move(path);
}

bool File::Open(ios::openmode mode)
{
    this->file.open(this->file_path, mode);
    return this->file.is_open();
}

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

string File::Read()
{
    if(this->Open(ios::in))
    {
        string r;
        string line;
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

bool File::Write(string to_file)
{
    if(this->Open(ios::out))
    {
        this->file << to_file << endl;
        this->Close();
    }
}

const char* file_exc_nofile::what() const throw()
{
    return "File is not exists";
}