#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "logic/LogicManager.h"
#include <fstream>
#include <iostream>

using namespace std;

class FileManager {
    string fileName;
    LogicManager &logicManagerRef;
public:
    FileManager(LogicManager &logic_manager);
    ~FileManager();
    void setFileName(const string& name);
    string getFileName();
    void readFile();
    void writeFile();
};



#endif //FILEMANAGER_H
