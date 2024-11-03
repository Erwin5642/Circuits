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
    int componentSelected;
    bool isConnectingWire;
    int wireConnecting;
    bool isInsideBoundaries(sf::Vector2f pos, sf::FloatRect bounds) const;
    int findComponentIntersecting(sf::Vector2f mousePos);
    sf::Vector2i findGridPointIntersection(sf::Vector2f mousePos) const;
    int findInputPointIntersection(sf::Vector2f mousePos) const;
    int findOutputPointIntersection(sf::Vector2f mousePos) const;
    sf::Vector2f findGridSlotIntersection(sf::Vector2f mousePos) const;
    void connectGridPoint(sf::Vector2i posGrid, sf::Vector2f mousePos);
    void connectInputPoint(unsigned int i, sf::Vector2f mousePos);
    void connectOutputPoint(unsigned int i, sf::Vector2f mousePos);
    void connectComponent(unsigned int i, sf::Vector2f mousePos);

public:
    UIManager(sf::RenderWindow &window, DrawableManager &drawableManager, LogicManager &logicManager);

    void processEvent();

    void handleMouseClick(sf::Vector2i mousePosition, sf::Mouse::Button button);

    void handleMouseMove(sf::Vector2i mousePosition);

    void handleKeyPress(sf::Keyboard::Key key);
};

#endif //UIMANAGER_H
