#include "UIManager.h"
#include "graphics/DrawableManager.h"
#include "graphics/and/ANDGateDrawable.h"
#include "graphics/or/ORGateDrawable.h"
#include "graphics/not/NOTGateDrawable.h"
#include "graphics/wire/WireDrawable.h"

bool UIManager::isInsideBoundaries(sf::Vector2f pos, sf::FloatRect bounds) const {
    return bounds.contains(pos);
}

void UIManager::checkConnectionGrid(sf::Vector2f mousePos,void (*callback)(sf::Vector2f, sf::Vector2f)) {
    int i, j;
    for(i = 0; i < GRID_SIZE; i++) {
        if(isInsideBoundaries(mousePos, drawableManagerRef.getBoundariesGrid(i, 0, 1))) {
            sf::Vector2f posPoint = drawableManagerRef.getPointPosition(i, 0, 1);
            callback(posPoint, mousePos);
            return;
        }
        if(isInsideBoundaries(mousePos, drawableManagerRef.getBoundariesGrid(i, 0, 3))) {
            sf::Vector2f posPoint = drawableManagerRef.getPointPosition(i, 0, 3);
            callback(posPoint, mousePos);
            return;
        }
        for(j = 0; j < GRID_SIZE; j++) {
            if(isInsideBoundaries(mousePos, drawableManagerRef.getBoundariesGrid(i, j, 2))) {
                sf::Vector2f posPoint = drawableManagerRef.getPointPosition(i, j, 2);
                callback(posPoint, mousePos);
                return;
            }
        }
    }
}

void UIManager::checkConnectionComponent(sf::Vector2f mousePos) {
    int i, n = drawableManagerRef.getNumDrawables(), k;
    for(i = 0; i < n; i++) {
        if(isInsideBoundaries(mousePos, drawableManagerRef.getBoundariesComponent(i))) {
            if(connectingWire) {
                k = drawableManagerRef.getUsedInputsSize(i);
                if(k < drawableManagerRef.getInputSize(i)) {
                    sf::Vector2f componentPos = drawableManagerRef.getInputPosition(i, k);
                    drawableManagerRef.setUsedInputSize(i, k + 1);
                    exitingConnection();
                }
                return;
            }
                if(!drawableManagerRef.getOutputUsed(i)) {
                    drawableManagerRef.setUsedOutputUsed(i);
                    sf::Vector2f componentPos = drawableManagerRef.getOutputPosition(i);
                    enteringConnection();
                }
                return;
            }
        }
    }
}

void UIManager::enteringConnection(sf::Vector2f posIn, sf::Vector2f posOut) {
    WireDrawable temp{{0, 0}, {0, 0}};
    drawableManagerRef.addWire(&temp, posIn, posOut);
    connectingWire = true;
}

void UIManager::exitingConnection(sf::Vector2f posIn, sf::Vector2f posOut) {
    drawableManagerRef.setOutputPosition(wireConnecting, posOut);
    connectingWire = false;
}

UIManager::UIManager(sf::RenderWindow &window, DrawableManager &drawableManager,
                     LogicManager &logicManager): drawableManagerRef(drawableManager),
                                                  logicManagerRef(logicManager),
                                                  windowRef(window), inMoveMode(true) {
}

void UIManager::processEvent() {
    sf::Event event{};
    while (windowRef.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                windowRef.close();
                break;
            case sf::Event::KeyPressed:
                handleKeyPress(event.key.code);
            case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button) {
                    case sf::Mouse::Left:
                        handleMouseClick(sf::Mouse::getPosition(), sf::Mouse::Button::Left);
                        break;
                    case sf::Mouse::Right:
                        handleMouseClick(sf::Mouse::getPosition(), sf::Mouse::Button::Right);
                        break;
                    default:
                        break;
                }
            case sf::Event::MouseMoved:
                handleMouseMove(sf::Mouse::getPosition());
            default:
                break;
        }
    }
}

void UIManager::handleKeyPress(const sf::Keyboard::Key key) {
    ANDGateDrawable tempAND({0, 0}, 2);
    NOTGateDrawable tempNOT({0, 0}, 2);
    ORGateDrawable tempOR({0, 0}, 2);
    switch (key) {
        case sf::Keyboard::Escape:
            drawableManagerRef.removeAllDrawables();
            break;
        case sf::Keyboard::Numpad1:
            drawableManagerRef.addDrawable(&tempAND, AND_SPAWN, 2);
            break;
        case sf::Keyboard::Numpad2:
            drawableManagerRef.addDrawable(&tempOR, OR_SPAWN, 2);
            break;
        case sf::Keyboard::Numpad3:
            drawableManagerRef.addDrawable(&tempNOT, NOT_SPAWN, 2);
        case sf::Keyboard::M:
            inMoveMode = true;
        default:
            break;
    }
}

void UIManager::handleMouseClick(sf::Vector2i mousePosition, sf::Mouse::Button button) {
    int i, j, n = drawableManagerRef.getNumDrawables();
    sf::Vector2f mousePositionF = sf::Vector2f(mousePosition.x, mousePosition.y);
    if (button == sf::Mouse::Button::Right) {
        for (i = 0; i < GRID_SIZE; i++) {
            bounds = drawableManagerRef.getBoundariesGrid(i, 0, 1);
            if (isInsideBoundaries(mousePositionF, bounds)) {
                drawableManagerRef.changePointOnOff(i, 1);
            }
        }
    } else if (button == sf::Mouse::Button::Left) {
        if (inMoveMode) {
            for (i = 0; i < n; i++) {
                bounds = drawableManagerRef.getBoundariesComponent(i);
                if (isInsideBoundaries(mousePositionF, bounds)) {
                    isHoldingComponent = true;
                    componentHold = i;
                }
            }
        } else {
            if (connectingWire) {
            } else {
            }
        }
    }
}

void UIManager::handleMouseMove(sf::Vector2i mousePosition) {
}
