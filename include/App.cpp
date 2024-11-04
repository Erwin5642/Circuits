#include "App.h"

App::App() {
}

App::~App() {
}

void App::run() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Circuits");
    UIManager uiManager(window, drawableManager, logicManager, fileManager);
    int i;
    while (window.isOpen()) {
        window.clear();
        uiManager.processEvent();
        if (drawableManager.getNumDrawables() > 0) {
            drawableManager.updateDrawables();
            logicManager.update();
        }
        drawableManager.draw(window);
        for (int i = 0; i < GRID_SIZE; i++) {
            if (logicManager.getSaida(i)) {
                drawableManager.changePointOnOff(i, 3, true);
            } else {
                drawableManager.changePointOnOff(i, 3, false);
            }
        }
        window.display();
    }
}
