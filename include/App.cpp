//
// Created by jvgam on 28/10/2024.
//

#include "App.h"

#include <iostream>

#include "logic/or/ORGateLogic.h"
#include "logic/wire/WIRELogic.h"
App::App() : uiManager(window, drawableManager, logicManager) {}

App::~App() = default;

void App::run() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Circuits");
    
    while (window.isOpen()) {
        window.clear();
        uiManager.processEvent();
        drawableManager.updateDrawables();
        logicManager.update();
        drawableManager.draw(window);
        window.display();
    }
}

void App::insert(const string& c_name) {
    switch(c_name) {
        case "AND":
            logicManager.insertComponent(new ANDGateLogic);
            break;
        case "OR":
            logicManager.insertComponent(new ORGateLogic);
            break;
        case "NOT":
            logicManager.insertComponent(new NOTGateLogic);
            break;
        case "WIRE":
            logicManager.insertComponent(new WIRELogic);
            break;
        default:
            break;
    }
}
void App::insertObj() {
    logicManager.printa();
    //      //      //      //      //      NOT
    logicManager.insertComponent(new NOTGateLogic());
    cout << logicManager.getSize() << endl;
    //logicManager.setEntrada(0);
    logicManager.getComponent(0).setInputValue(0, pair<char, int>('e', 0));
    logicManager.getComponent(0).setOutput(pair<int, int>(0, 0));
    logicManager.update();
    cout << "Coord IN NOT: " << logicManager.getComponent(0).getConnectedInputTo(0).first << ' ' << logicManager.getComponent(0).getConnectedInputTo(0).second << endl;
    cout << "Coord OUT NOT: " << logicManager.getComponent(0).getConnectedOutputTo().first << ' ' << logicManager.getComponent(0).getConnectedOutputTo().second << endl;
    cout << "Entrada 0: " << logicManager.getEntrada(0) << endl;
    cout << "Saida 0: " << logicManager.getSaida(0) << endl;
    //logicManager.setEntrada(0);
    logicManager.update();
    cout << "Coord IN NOT: " << logicManager.getComponent(0).getConnectedInputTo(0).first << ' ' << logicManager.getComponent(0).getConnectedInputTo(0).second << endl;
    cout << "Coord OUT NOT: " << logicManager.getComponent(0).getConnectedOutputTo().first << ' ' << logicManager.getComponent(0).getConnectedOutputTo().second << endl;
    cout << "Entrada 0: " << logicManager.getEntrada(0) << endl;
    cout << "Saida 0: " << logicManager.getSaida(0) << endl;
    logicManager.printa();
    //      //      //      //      //      WIRE
    logicManager.insertComponent(new WIRELogic());
    logicManager.getComponent(0).setInputValue(0, pair<int, int>(0, 0));
    logicManager.getComponent(0).setOutput(pair<char, int>('s', 0));
    logicManager.update();
    cout << "Entrada 0: " << logicManager.getEntrada(0) << endl;
    cout << "Saida 0: " << logicManager.getSaida(0) << endl;
    //logicManager.setEntrada(0);
    logicManager.update();
    cout << "Entrada 0: " << logicManager.getEntrada(0) << endl;
    cout << "Saida 0: " << logicManager.getSaida(0) << endl;
    logicManager.printa();
         //      //      //      //      AND
    logicManager.insertComponent(new ANDGateLogic());
    logicManager.getComponent(0).setInputValue(0, pair<char, int>('e', 0));
    logicManager.getComponent(0).setInputValue(1, pair<char, int>('e', 1));
    logicManager.getComponent(0).setOutput(pair<char, int>('s', 0));
    logicManager.setEntrada(0);
    logicManager.update();
    cout << "Entrada 0: " << logicManager.getEntrada(0) << endl;
    cout << "Entrada 1: " << logicManager.getEntrada(1) << endl;
    cout << "Saida 0: " << logicManager.getSaida(0) << endl;
    logicManager.setEntrada(1);
    logicManager.update();
    cout << "Entrada 0: " << logicManager.getEntrada(0) << endl;
    cout << "Entrada 1: " << logicManager.getEntrada(1) << endl;
    cout << "Saida 0: " << logicManager.getSaida(0) << endl;
    logicManager.printa();
         //      //      //      //      OR
    logicManager.insertComponent(new ORGateLogic());
    logicManager.getComponent(0).setInputValue(0, pair<char, int>('e', 0));
    logicManager.getComponent(0).setInputValue(1, pair<char, int>('e', 1));
    logicManager.getComponent(0).setOutput(pair<char, int>('s', 0));
    logicManager.setEntrada(0);
    //logicManager.setEntrada(1);
    logicManager.update();
    cout << "Entrada 0: " << logicManager.getEntrada(0) << endl;
    cout << "Entrada 1: " << logicManager.getEntrada(1) << endl;
    cout << "Saida 0: " << logicManager.getSaida(0) << endl;
    logicManager.setEntrada(0);
    logicManager.setEntrada(1);
    logicManager.update();
    cout << "Entrada 0: " << logicManager.getEntrada(0) << endl;
    cout << "Entrada 1: " << logicManager.getEntrada(1) << endl;
    cout << "Saida 0: " << logicManager.getSaida(0) << endl;
    logicManager.printa();
}
