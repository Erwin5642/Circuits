//
// Created by jvgam on 28/10/2024.
//

#ifndef APP_H
#define APP_H

#include <iostream>

#include "logic/LogicManager.h"
#include "logic/and/ANDGateLogic.h"
#include "logic/not/NOTGateLogic.h"
//#include "DrawableManager.h"
//#include "FileManager.h"
//#include "UIManager.h"

class App {
    LogicManager l_Manager;
    //DrawableManager d_Manager;
    //FileManager f_Manager;
    //UIManager u_Manager;
public:
    void run();
    void insertObj();
};

#endif //APP_H