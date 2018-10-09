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
    bool Create();
    bool Write(string to_file);
private:
    string file_path;
    fstream file;
    bool Open(ios::openmode mode);
    bool Close();

};

#endif //CAG_FILE_H
