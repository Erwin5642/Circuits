#include "UIManager.h"
#include "graphics/DrawableManager.h"
#include "graphics/and/ANDGateDrawable.h"
#include "graphics/or/ORGateDrawable.h"
#include "graphics/not/NOTGateDrawable.h"
#include "graphics/wire/WireDrawable.h"
#include "logic/and/ANDGateLogic.h"
#include "logic/not/NOTGateLogic.h"
#include "logic/or/ORGateLogic.h"
#include "logic/wire/WIRELogic.h"

bool UIManager::isInsideBoundaries(sf::Vector2f pos, sf::FloatRect bounds) const {
    return bounds.contains(pos);
}

int UIManager::findComponentIntersecting(sf::Vector2f mousePos) {
    int i, n = drawableManagerRef.getNumDrawables();
    for (i = 0; i < n; i++) {
        sf::FloatRect bounds = drawableManagerRef.getBoundariesComponent(i);
        if (isInsideBoundaries(mousePos, bounds)) {
            return i;
        }
    }
    return -1;
}

sf::Vector2i UIManager::findGridPointIntersection(sf::Vector2f mousePos) {
    int i;
    for (i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            sf::FloatRect bounds = drawableManagerRef.getBoundariesGrid(i, j, 2);
            if (isInsideBoundaries(mousePos, bounds)) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int UIManager::findInputPointIntersection(sf::Vector2f mousePos) {
    int i;
    for (i = 0; i < GRID_SIZE; i++) {
        sf::FloatRect bounds = drawableManagerRef.getBoundariesGrid(i, 0, 1);
        if (isInsideBoundaries(mousePos, bounds)) {
            return i;
        }
    }
    return -1;
}

int UIManager::findOutputPointIntersection(sf::Vector2f mousePos) {
    int i;
    for (i = 0; i < GRID_SIZE; i++) {
        sf::FloatRect bounds = drawableManagerRef.getBoundariesGrid(i, 0, 3);
        if (isInsideBoundaries(mousePos, bounds)) {
            return i;
        }
    }
    return -1;
}

sf::Vector2f UIManager::findGridSlotIntersection(sf::Vector2f mousePos) const {
    int i, j;
    for (i = 0; i < GRID_SIZE - 1; i++) {
        for (int j = 0; j < GRID_SIZE - 1; j++) {
            sf::Vector2f pos1 = drawableManagerRef.getPointPosition(i, j, 2);
            sf::Vector2f pos2 = drawableManagerRef.getPointPosition(i + 1, j + 1, 2);
            sf::FloatRect bounds(pos1, sf::Vector2f(pos2.x - pos1.x, pos2.y - pos1.y));
            if (isInsideBoundaries(mousePos, bounds)) {
                return {(pos1.x + pos2.x) / 2, (pos1.y + pos2.y) / 2};
            }
        }
    }
    return {-1, -1};
}


void UIManager::connectGridPoint(sf::Vector2i posGrid, sf::Vector2f mousePos) {
    WireDrawable tempD({0, 0}, {0, 0});
    int i;
    if (isConnectingWire) {
        drawableManagerRef.connectGatesOut(wireConnectingDraw,
                                           drawableManagerRef.getPointReference(posGrid.x, posGrid.y, 2));
        if (isConnectingFromDot) {
            i = logicManagerRef.getSize() - 1;
            logicManagerRef.getComponent(i).setOutput(pair<int, int>(posGrid.x, posGrid.y));
            logicManagerRef.getComponent(i).setInputValue(0, dotConnectingFrom);
        } else {
            logicManagerRef.getComponent(wireConnectingLogic).setOutput(pair<int, int>(posGrid.x, posGrid.y));
        }
        isConnectingWire = false;
    } else {
        drawableManagerRef.addWire(&tempD, drawableManagerRef.getPointPosition(posGrid.x, posGrid.y, 2), mousePos);
        logicManagerRef.insertComponent(new WIRELogic);
        wireConnectingDraw = drawableManagerRef.getNumDrawables() - 1;
        drawableManagerRef.connectGatesIn(wireConnectingDraw,
                                          drawableManagerRef.getPointReference(posGrid.x, posGrid.y, 2));
        isConnectingWire = true;
        isConnectingFromDot = true;
        dotConnectingFrom = pair<int, int>(posGrid.x, posGrid.y);
    }
}

void UIManager::connectInputPoint(unsigned int i, sf::Vector2f mousePos) {
    WireDrawable tempD({0, 0}, {0, 0});
    if (!isConnectingWire) {
        drawableManagerRef.addWire(&tempD, drawableManagerRef.getPointPosition(i, 0, 1), mousePos);
        logicManagerRef.insertComponent(new WIRELogic);
        wireConnectingDraw = drawableManagerRef.getNumDrawables() - 1;
        drawableManagerRef.connectGatesIn(wireConnectingDraw, drawableManagerRef.getPointReference(i, 0, 1));
        isConnectingWire = true;
        isConnectingFromDot = true;
        dotConnectingFrom = pair<int, int>('e', i);
    }
}

void UIManager::connectOutputPoint(unsigned int i, sf::Vector2f mousePos) {
    WireDrawable tempD({0, 0}, {0, 0});
    int j;
    if (isConnectingWire) {
        drawableManagerRef.connectGatesOut(wireConnectingDraw,
                                           drawableManagerRef.getPointReference(i, 0, 3));
        if (isConnectingFromDot) {
            j = logicManagerRef.getSize() - 1;
            logicManagerRef.getComponent(j).setOutput(pair<int, int>('s', i));
            logicManagerRef.getComponent(j).setInputValue(0, dotConnectingFrom);
        } else {
            logicManagerRef.getComponent(wireConnectingLogic).setOutput(pair<int, int>('s', i));
        }
        isConnectingWire = false;
    }
}

void UIManager::connectComponent(unsigned int i, sf::Vector2f mousePos) {
    WireDrawable tempD({0, 0}, {0, 0});

    if (!isConnectingWire) {
        if (!drawableManagerRef.getOutputUsed(i)) {
            drawableManagerRef.addWire(&tempD, drawableManagerRef.getOutputPosition(i), mousePos);
            logicManagerRef.insertComponent(new WIRELogic);
            wireConnectingLogic = i;
            wireConnectingDraw = drawableManagerRef.getNumDrawables() - 1;
            drawableManagerRef.connectGatesIn(
                wireConnectingDraw, drawableManagerRef.getComponentReference(i));
            drawableManagerRef.connectGatesOut(i, drawableManagerRef.getComponentReference(wireConnectingDraw));
            isConnectingWire = true;
            dotConnectingFrom = pair<int, int>(-2, -2);
            isConnectingFromDot = false;
        }
    } else {
        if (drawableManagerRef.getUsedInputsSize(i) != drawableManagerRef.getInputSize(i)) {
            isConnectingWire = false;
            drawableManagerRef.connectGatesOut(wireConnectingDraw, drawableManagerRef.getComponentReference(i));
            drawableManagerRef.connectGatesIn(i, drawableManagerRef.getComponentReference(wireConnectingDraw));
            logicManagerRef.getComponent(i).setInputValue(logicManagerRef.getComponent(i).getUsedInputs(),
                                                          dotConnectingFrom);
            wireConnectingDraw = -1;
        }
    }
}

UIManager::UIManager(sf::RenderWindow &window, DrawableManager &drawableManager, LogicManager &logicManager,
                     FileManager &fileManager) : drawableManagerRef(drawableManager),
                                                 logicManagerRef(logicManager),
                                                 fileManagerRef(fileManager),
                                                 windowRef(window) {
    isConnectingWire = false;
    inMoveMode = true;
    isHoldingComponent = false;
    componentSelected = -1;
    wireConnectingDraw = -1;
    isConnectingFromDot = false;
    wireConnectingLogic = -1;
    dotConnectingFrom = pair<int, int>(-2, -2);
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
                        handleMouseClick(sf::Mouse::getPosition(windowRef), sf::Mouse::Button::Left);
                        break;
                    case sf::Mouse::Right:
                        handleMouseClick(sf::Mouse::getPosition(windowRef), sf::Mouse::Button::Right);
                        break;
                    default:
                        break;
                }
            case sf::Event::MouseMoved:
                handleMouseMove(sf::Mouse::getPosition(windowRef));
            default:
                break;
        }
    }
}

void UIManager::handleKeyPress(const sf::Keyboard::Key key) {
    ORGateDrawable tempORD({0, 0}, 2);
    NOTGateDrawable tempNOTD({0, 0}, 1);
    ANDGateDrawable tempANDD({0, 0}, 2);
    XORGateDrawable tempXORD({0, 0}, 2);

    switch (key) {
        case sf::Keyboard::Escape:
            drawableManagerRef.removeAllDrawables();
            logicManagerRef.deleteAllComponents();
            break;
        case sf::Keyboard::I:
            drawableManagerRef.addDrawable(&tempANDD, AND_SPAWN, 2);
            logicManagerRef.insertComponent(new ANDGateLogic);
            break;
        case sf::Keyboard::O:
            drawableManagerRef.addDrawable(&tempORD, OR_SPAWN, 2);
            logicManagerRef.insertComponent(new ORGateLogic);
            break;
        case sf::Keyboard::P:
            drawableManagerRef.addDrawable(&tempNOTD, NOT_SPAWN, 1);
            logicManagerRef.insertComponent(new NOTGateLogic);
            break;
        case sf::Keyboard::U:
            drawableManagerRef.addDrawable(&tempXORD, XOR_SPAWN, 2);
            logicManagerRef.insertComponent(new XORGateLogic);
            break;
        case sf::Keyboard::W:
            inMoveMode = false;
            break;
        case sf::Keyboard::Q:
            inMoveMode = true;
            break;
        case sf::Keyboard::A:
            fileManagerRef.loadComponents(logicManagerRef);
            break;
        case sf::Keyboard::S:
            fileManagerRef.saveComponents(logicManagerRef);
            break;
        default:
            break;
    }
}

void UIManager::handleMouseClick(sf::Vector2i mousePosition, sf::Mouse::Button button) {
    int i, j, n = drawableManagerRef.getNumDrawables();
    sf::Vector2f mousePositionF = sf::Vector2f(mousePosition.x, mousePosition.y);
    sf::Vector2i posGrid;
    sf::Vector2f posGridSlot;
    ComponentDrawable *aux = nullptr;
    if (button == sf::Mouse::Button::Right) {
        i = findInputPointIntersection(mousePositionF);
        if (i != -1) {
            drawableManagerRef.changePointOnOff(i, 1);
            logicManagerRef.setEntrada(i);
        }
    } else if (button == sf::Mouse::Button::Left) {
        if (inMoveMode) {
            if (componentSelected == -1) {
                if ((i = findComponentIntersecting(mousePositionF)) != -1) {
                    componentSelected = i;
                }
            } else {
                if ((posGridSlot = findGridSlotIntersection(mousePositionF)) != sf::Vector2f(-1, -1)) {
                    drawableManagerRef.setCenterPosition(componentSelected, posGridSlot);
                    for (i = 0; i < drawableManagerRef.getInputSize(componentSelected); i++) {
                        if ((aux = drawableManagerRef.getInputsWires(componentSelected, i)) != nullptr) {
                            aux->setOutputPosition(drawableManagerRef.getInputPosition(componentSelected, i));
                        }
                    }
                    if ((aux = drawableManagerRef.getOutputsWire(componentSelected)) != nullptr) {
                        aux->setInputPosition(0, drawableManagerRef.getOutputPosition(componentSelected));
                    }
                }
                componentSelected = -1;
            }
        } else {
            if ((i = findInputPointIntersection(mousePositionF)) != -1) {
                connectInputPoint(i, mousePositionF);
            } else if ((i = findOutputPointIntersection(mousePositionF)) != -1) {
                connectOutputPoint(i, mousePositionF);
            } else if ((i = findComponentIntersecting(mousePositionF)) != -1) {
                connectComponent(i, mousePositionF);
            } else if ((posGrid = findGridPointIntersection(mousePositionF)) != sf::Vector2i{-1, -1}) {
                connectGridPoint(posGrid, mousePositionF);
            }
        }
    }
}

void UIManager::handleMouseMove(sf::Vector2i mousePosition) {
    int i;
    sf::Vector2f mousePositionF = sf::Vector2f(mousePosition.x, mousePosition.y);
    ComponentDrawable *aux = nullptr;

    if (inMoveMode) {
        if (componentSelected != -1) {
            drawableManagerRef.setCenterPosition(componentSelected, mousePositionF);
            for (i = 0; i < drawableManagerRef.getInputSize(componentSelected); i++) {
                if ((aux = drawableManagerRef.getInputsWires(componentSelected, i)) != nullptr) {
                    aux->setOutputPosition(drawableManagerRef.getInputPosition(componentSelected, i));
                }
            }
            if ((aux = drawableManagerRef.getOutputsWire(componentSelected)) != nullptr) {
                aux->setInputPosition(0, drawableManagerRef.getOutputPosition(componentSelected));
            }
        }
    } else {
        if (isConnectingWire) {
            if (wireConnectingDraw != -1) {
                drawableManagerRef.setOutputPosition(wireConnectingDraw, mousePositionF);
            }
        }
    }
}
