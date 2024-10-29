//
// Created by Arthur on 29/10/2024.
//

#include "LogicManager.h"

LogicManager::LogicManager() {
    components.clear();
}
LogicManager::~LogicManager() {
    while(!components.empty()) {
        components.pop_back();
    }
}
void LogicManager::insertComponent(ComponentLogic *component) {
    components.push_back(component);
}
void LogicManager::deleteComponent(const int index) {
    components.erase(components.begin() + index);
}