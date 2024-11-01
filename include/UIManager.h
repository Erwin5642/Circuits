//
// Created by jvgam on 28/10/2024.
//

#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "graphics/DrawableManager.h"
#include "logic/LogicManager.h"

class UIManager {
    DrawableManager &drawableManagerRef;
    LogicManager &logicManagerRef;
    sf::RenderWindow &windowRef;

public:
    UIManager(sf::RenderWindow &window, DrawableManager &drawableManager, LogicManager &logicManager);

    void processEvent();

    void handleMouseClick(sf::Vector2i mousePosition);

    void handleMouseMove(sf::Vector2i mousePosition);

    void handleMouseRelease(sf::Vector2i mousePosition);

    void handleKeyPress(sf::Keyboard::Key key);
};

#endif //UIMANAGER_H
