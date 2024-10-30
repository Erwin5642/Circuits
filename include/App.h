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
    void insertObj() {
        l_Manager.insertComponent(new NOTGateLogic());
        cout << l_Manager.getSize() << endl;
        l_Manager.getComponent(0).setInputValue(0, pair<char, int>('e', 0));
        l_Manager.getComponent(0).setOutput(pair<char, int>('s', 0));
        l_Manager.getComponent(0).evaluate();
        l_Manager.setSaidas();
        cout << "Entrada 0: " << l_Manager.getEntrada(0) << endl;
        cout << "Saida 0: " << l_Manager.getSaida(0) << endl;

        l_Manager.setEntrada(0);
        l_Manager.getComponent(0).evaluate();
        l_Manager.setSaidas();
        cout << "Entrada 0: " << l_Manager.getEntrada(0) << endl;
        cout << "Saida 0: " << l_Manager.getSaida(0) << endl;

    }
};

#endif //APP_H