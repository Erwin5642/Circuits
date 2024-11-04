#ifndef APP_H
#define APP_H

#include "graphics/DrawableManager.h"
#include "logic/LogicManager.h"
#include "UIManager.h"
#include "FileManager.h"
#include <iostream>

class App {
    DrawableManager drawableManager;
    LogicManager logicManager;
    FileManager fileManager;

public:
    App();

    ~App();

    void run();
};

#endif //APP_H
