//
// Created by jvgam on 28/10/2024.
//

#include "UIManager.h"

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
                handleMouseClick(sf::Mouse::getPosition());
            case sf::Event::MouseMoved:
                handleMouseMove(sf::Mouse::getPosition());
            case sf::Event::MouseButtonReleased:
                handleMouseRelease(sf::Mouse::getPosition());
            default:
                break;
        }
    }
}

void UIManager::handleKeyPress(const sf::Keyboard::Key key) {
    ANDGateDrawable tempAND;
    NOTGateDrawable tempNOT;
    ORGateDrawable tempOR;
    switch (key) {
        case sf::Keyboard::Escape:
            drawableManagerRef.removeAllDrawables();
            break;
        case sf::Keyboard::Numpad1:
            drawableManagerRef.addDrawable(&tempAND, 429, 429, 15, 10, 2);
            break;
        case sf::Keyboard::Numpad2:
            drawableManagerRef.addDrawable(&tempOR, 429, 429, 15, 10, 2);
            break;
        case sf::Keyboard::Numpad3:
            drawableManagerRef.addDrawable(&tempNOT, 429, 429, 15, 10, 2);
        default:
            break;
    }
}

void UIManager::handleMouseClick(sf::Vector2i mousePosition) {
    int i;
    for (i = 0; i < drawableManagerRef.getNumDrawables(); i++) {
        // Compare boundaries of drawables with mouse
    }
}
