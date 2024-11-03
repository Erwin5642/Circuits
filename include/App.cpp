//
// Created by jvgam on 28/10/2024.
//

#include "App.h"

#include <iostream>

#include "logic/or/ORGateLogic.h"
#include "logic/wire/WIRELogic.h"
App::App()
{
    f_Manager = new FileManager();
}

App::~App() {
    delete f_Manager;
}

void App::run() {
    DrawableManager drawableManager;
    LogicManager logicManager;
    sf::RenderWindow window(sf::VideoMode(800, 800 ), "Circuits");
    UIManager uiManager(window, drawableManager, logicManager);

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
    if(c_name == "AND")
        l_Manager.insertComponent(new ANDGateLogic);
    if(c_name == "OR")
        l_Manager.insertComponent(new ORGateLogic);
    if(c_name == "NOT")
        l_Manager.insertComponent(new NOTGateLogic);
    if(c_name == "WIRE")
        l_Manager.insertComponent(new WIRELogic);

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
void App::printa() {
    l_Manager.printa();
}
void App::listComps() {
    l_Manager.listComponents();
}
int App::getSize() {
    return l_Manager.getSize();
}