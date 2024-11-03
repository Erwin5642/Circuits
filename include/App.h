//
// Created by jvgam on 28/10/2024.
//

#ifndef APP_H
#define APP_H

#include "graphics/DrawableManager.h"
#include "logic/LogicManager.h"
#include "UIManager.h"
#include <iostream>
#include "logic/LogicManager.h"
#include "logic/and/ANDGateLogic.h"
#include "logic/not/NOTGateLogic.h"

class App {

    void insert(const string& c_name);
    void getIndex();
    void remove(int index);
    void insertObj();

public:
    App();
    ~App();
    void run();
};

#endif //APP_H
