//
// Created by Arthur on 29/10/2024.
//

#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H

#include "ComponentLogic.h"
#include <vector>

using namespace std;

class LogicManager {
private:
    std::vector<ComponentLogic*> components;
public:
    LogicManager();
    ~LogicManager();
    void insertComponent(ComponentLogic* component);
    void deleteComponent(int index);
};

#endif //LOGICMANAGER_H