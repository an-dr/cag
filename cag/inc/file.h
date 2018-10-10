//
// Created by Andrey Gramakov on 09/10/2018.
//

#ifndef CAG_FILE_H
#define CAG_FILE_H

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class File
{
public:
    explicit File(string path = "");
    string Read();
//    bool Create(); todo: add a Create method
    bool Write(string to_file);
private:
    string file_path;
    fstream file;
    bool Open(ios::openmode mode);
    bool Close();

};

class file_exc_nofile: public exception
{
    const char* what() const noexcept override;
};

#endif //CAG_FILE_H
