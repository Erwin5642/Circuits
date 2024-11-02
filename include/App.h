//
// Created by jvgam on 28/10/2024.
//

#ifndef APP_H
#define APP_H

//#include "graphics/DrawableManager.h"
#include "logic/LogicManager.h"
#include "FileManager.h"
//#include "UIManager.h"
#include <iostream>
#include "logic/LogicManager.h"
#include "logic/and/ANDGateLogic.h"
#include "logic/not/NOTGateLogic.h"

class App {
private:
    //DrawableManager drawableManager;
    //FileManager fileManager;
    //UIManager uiManager;
    LogicManager l_Manager;

public:
    App();
    ~App();
    //DrawableManager d_Manager;
    //FileManager f_Manager;
    //UIManager u_Manager;
public:
    void run();
    void insertObj();
};



#endif //APP_H
