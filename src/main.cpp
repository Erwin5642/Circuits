//
// Created by jvgam on 29/10/2024.
//

#include "SFML/Window.hpp"
#include "../include/graphics/DrawableManager.h"
#include "../include/graphics/and/ANDGateDrawable.h"
#include "../include/graphics/not/NOTGateDrawable.h"
#include "../include/graphics/or/ORGateDrawable.h"
using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Drawables Manager Test");
    DrawableManager drawableManager;
    ANDGateDrawable ANDGate(sf::Vector2f(0, 0), 2);
    ORGateDrawable ORGate(sf::Vector2f(0, 0), 2);
    NOTGateDrawable NOTGate(sf::Vector2f(0, 0), 2);

    while (window.isOpen()) {
        window.clear();
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::A:
                            drawableManager.addDrawable(&ANDGate, AND_SPAWN, 2);
                        break;
                        case sf::Keyboard::O:
                            drawableManager.addDrawable(&ORGate, OR_SPAWN, 2);
                        break;
                        case sf::Keyboard::N:
                            drawableManager.addDrawable(&NOTGate, NOT_SPAWN, 1);
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
