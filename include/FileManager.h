#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "logic/LogicManager.h"
#include <string>

class FileManager {
    string toLowerCase(const std::string &str);
public:
    void loadComponents(const std::string &filename, LogicManager &logicManager);
    void saveComponents(const std::string &filename, LogicManager &logicManager);
};

#endif // FILEMANAGER_H