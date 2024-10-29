//
// Created by jvgam on 28/10/2024.
//

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "logic/LogicManager.h"

using namespace std;

class FileManager {
    LogicManager logicManager;
    string fileName;
public:
    FileManager();
    ~FileManager();
    void setFileName(const string& name);
    string getFileName();
    void readFile();
    void writeFile();
};



#endif //FILEMANAGER_H
