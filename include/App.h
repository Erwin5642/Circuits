//
// Created by jvgam on 28/10/2024.
//

#ifndef APP_H
#define APP_H

#include "DrawableManager.h"
#include "LogicManager.h"
#include "FileManager.h"
#include "UIManager.h"

class App {
private:
    DrawableManager drawableManager;
    LogicManager logicManager;
    FileManager fileManager;
    UIManager uiManager;

public:
    App();
    ~App();
    void run();
};



#endif //APP_H
