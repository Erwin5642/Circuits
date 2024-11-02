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
    bool inMoveMode;
    bool isHoldingComponent;
    unsigned int componentHold;
    bool connectingWire;
    unsigned int wireConnecting;
    bool isInsideBoundaries(sf::Vector2f pos, sf::FloatRect bounds) const;
    void checkConnectionGrid(sf::Vector2f mousePos,void(*callback)(sf::Vector2f, sf::Vector2f));
    void checkConnectionComponent(sf::Vector2f mousePos ,void(*callback)(sf::Vector2f, sf::Vector2f));
    void checkBoundariesForConnection(sf::Vector2f pos, sf::FloatRect bounds, void(*callback)(sf::Vector2f, sf::Vector2f));
    void enteringConnection(sf::Vector2f posIn, sf::Vector2f posOut);
    void exitingConnection(sf::Vector2f posIn, sf::Vector2f posOut);

public:
    UIManager(sf::RenderWindow &window, DrawableManager &drawableManager, LogicManager &logicManager);

    void processEvent();

    void handleMouseClick(sf::Vector2i mousePosition, sf::Mouse::Button button);

    void handleMouseMove(sf::Vector2i mousePosition);

    void handleKeyPress(sf::Keyboard::Key key);
};

#endif //UIMANAGER_H
