//
// Created by jvgam on 29/10/2024.
//

#include "../include/ANDGateDrawable.h"
#include "../include/DrawableManager.h"
#include "../include/NOTGateDrawable.h"
#include "../include/ORGateDrawable.h"
#include "SFML/Window.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Drawables Manager Test");
    DrawableManager drawableManager;
    ANDGateDrawable ANDGate;
    ORGateDrawable ORGate;
    NOTGateDrawable NOTGate;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::A:
                            drawableManager.addDrawable(&ANDGate, 429, 429, 15, 10, 2);
                        break;
                        case sf::Keyboard::O:
                            drawableManager.addDrawable(&ORGate, 53, 120, 15, 10, 2);
                        break;
                        case sf::Keyboard::N:
                            drawableManager.addDrawable(&NOTGate, 530, 225, 15, 10, 2);
                        break;
                        case sf::Keyboard::Escape:
                            drawableManager.removeAllDrawables();
                        break;
                        default:
                            break;
                    }
                default:
                    break;
            }
            drawableManager.draw(window);
            window.display();
        }
    }

    return 0;
}
