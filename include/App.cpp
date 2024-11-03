//
// Created by jvgam on 28/10/2024.
//

#include "App.h"

#include <iostream>

#include "logic/or/ORGateLogic.h"
#include "logic/wire/WIRELogic.h"
App::App()
{

}

App::~App() = default;

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