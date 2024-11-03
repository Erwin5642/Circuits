#ifndef APP_H
#define APP_H

#include "graphics/DrawableManager.h"
#include "logic/LogicManager.h"
#include "UIManager.h"
#include <iostream>

class App {

    void insert(const string& c_name);
    void getIndex();
    void remove(int index);
    void insertObj();
    void leArq();
    void gravaArq();
    void printa();
    void listComps();
    int getSize();

public:
    App();
    ~App();

    void run();
};

#endif //APP_H