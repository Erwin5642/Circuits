#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "logic/LogicManager.h"
#include <string>
#include "logic/and/ANDGateLogic.h"
#include "logic/not/NOTGateLogic.h"
#include "logic/or/ORGateLogic.h"
#include "logic/wire/WIRELogic.h"
#include "logic/xor/XORGateLogic.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class FileManager {
    string toLowerCase(const std::string &str);

public:
    void loadComponents(LogicManager &logicManager);

    void saveComponents(LogicManager &logicManager);
};

#endif // FILEMANAGER_H
