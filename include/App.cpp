//
// Created by jvgam on 28/10/2024.
//

#include "App.h"

#include <iostream>

#include "logic/or/ORGateLogic.h"
#include "logic/wire/WIRELogic.h"
App::App() {
    f_Manager = new FileManager();
}
App::~App() {
    delete f_Manager;
}

void App::run() {
    cout << "Hello World!" << endl;
}
void App::insert(const string& c_name) {
    if(c_name == "AND")
        l_Manager.insertComponent(new ANDGateLogic);
    if(c_name == "OR")
        l_Manager.insertComponent(new ORGateLogic);
    if(c_name == "NOT")
        l_Manager.insertComponent(new NOTGateLogic);
    if(c_name == "WIRE")
        l_Manager.insertComponent(new WIRELogic);

}
void App::insertObj() {
    l_Manager.printa();
    //      //      //      //      //      NOT
    l_Manager.insertComponent(new NOTGateLogic());
    cout << l_Manager.getSize() << endl;
    //l_Manager.setEntrada(0);
    l_Manager.getComponent(0).setInputValue(0, pair<char, int>('e', 0));
    l_Manager.getComponent(0).setOutput(pair<int, int>(0, 0));
    l_Manager.update();
    cout << "Coord IN NOT: " << l_Manager.getComponent(0).getConnectedInputTo(0).first << ' ' << l_Manager.getComponent(0).getConnectedInputTo(0).second << endl;
    cout << "Coord OUT NOT: " << l_Manager.getComponent(0).getConnectedOutputTo().first << ' ' << l_Manager.getComponent(0).getConnectedOutputTo().second << endl;
    cout << "Entrada 0: " << l_Manager.getEntrada(0) << endl;
    cout << "Saida 0: " << l_Manager.getSaida(0) << endl;
    //l_Manager.setEntrada(0);
    l_Manager.update();
    cout << "Coord IN NOT: " << l_Manager.getComponent(0).getConnectedInputTo(0).first << ' ' << l_Manager.getComponent(0).getConnectedInputTo(0).second << endl;
    cout << "Coord OUT NOT: " << l_Manager.getComponent(0).getConnectedOutputTo().first << ' ' << l_Manager.getComponent(0).getConnectedOutputTo().second << endl;
    cout << "Entrada 0: " << l_Manager.getEntrada(0) << endl;
    cout << "Saida 0: " << l_Manager.getSaida(0) << endl;
    l_Manager.printa();
    //      //      //      //      //      WIRE
    l_Manager.insertComponent(new WIRELogic());
    l_Manager.getComponent(0).setInputValue(0, pair<int, int>(0, 0));
    l_Manager.getComponent(0).setOutput(pair<char, int>('s', 0));
    l_Manager.update();
    cout << "Entrada 0: " << l_Manager.getEntrada(0) << endl;
    cout << "Saida 0: " << l_Manager.getSaida(0) << endl;
    //l_Manager.setEntrada(0);
    l_Manager.update();
    cout << "Entrada 0: " << l_Manager.getEntrada(0) << endl;
    cout << "Saida 0: " << l_Manager.getSaida(0) << endl;
    l_Manager.printa();
         //      //      //      //      AND
    l_Manager.insertComponent(new ANDGateLogic());
    l_Manager.getComponent(0).setInputValue(0, pair<char, int>('e', 0));
    l_Manager.getComponent(0).setInputValue(1, pair<char, int>('e', 1));
    l_Manager.getComponent(0).setOutput(pair<char, int>('s', 0));
    l_Manager.setEntrada(0);
    l_Manager.update();
    cout << "Entrada 0: " << l_Manager.getEntrada(0) << endl;
    cout << "Entrada 1: " << l_Manager.getEntrada(1) << endl;
    cout << "Saida 0: " << l_Manager.getSaida(0) << endl;
    l_Manager.setEntrada(1);
    l_Manager.update();
    cout << "Entrada 0: " << l_Manager.getEntrada(0) << endl;
    cout << "Entrada 1: " << l_Manager.getEntrada(1) << endl;
    cout << "Saida 0: " << l_Manager.getSaida(0) << endl;
    l_Manager.printa();
         //      //      //      //      OR
    l_Manager.insertComponent(new ORGateLogic());
    l_Manager.getComponent(0).setInputValue(0, pair<char, int>('e', 0));
    l_Manager.getComponent(0).setInputValue(1, pair<char, int>('e', 1));
    l_Manager.getComponent(0).setOutput(pair<char, int>('s', 0));
    l_Manager.setEntrada(0);
    //l_Manager.setEntrada(1);
    l_Manager.update();
    cout << "Entrada 0: " << l_Manager.getEntrada(0) << endl;
    cout << "Entrada 1: " << l_Manager.getEntrada(1) << endl;
    cout << "Saida 0: " << l_Manager.getSaida(0) << endl;
    l_Manager.setEntrada(0);
    l_Manager.setEntrada(1);
    l_Manager.update();
    cout << "Entrada 0: " << l_Manager.getEntrada(0) << endl;
    cout << "Entrada 1: " << l_Manager.getEntrada(1) << endl;
    cout << "Saida 0: " << l_Manager.getSaida(0) << endl;
    l_Manager.printa();
}
void App::leArq() {
    if (!f_Manager) {
        std::cerr << "Erro: FileManager não inicializado." << std::endl;
        return;
    }
    std::string arq_name;
    std::cout << "Digite o nome do arquivo: ";
    std::cin >> arq_name;
    f_Manager->loadComponents(arq_name, l_Manager);
}
void App::gravaArq() {
    if (!f_Manager) {
        std::cerr << "Erro: FileManager não inicializado." << std::endl;
        return;
    }
    std::string arq_name;
    std::cout << "Digite o nome do arquivo: ";
    std::cin >> arq_name;
    f_Manager->saveComponents(arq_name, l_Manager);
}
void App::printa() {
    l_Manager.printa();
}
void App::listComps() {
    l_Manager.listComponents();
}
int App::getSize() {
    return l_Manager.getSize();
}
