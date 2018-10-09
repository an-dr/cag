//
// Created by Andrey Gramakov on 09/10/2018.
//

#include "../inc/file.h"

File::File(string path)
{
    this->file_path = path;
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