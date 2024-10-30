//
// Created by jvgam on 29/10/2024.
//

#include "ANDGateDrawable.h"
#include "DrawableManager.h"
#include "SFML/Window.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode(800,800), "Drawables Manager Teste" );
    DrawableManager drawableManager;

    while(window.isOpen()) {
        sf::Event event{};
        while(window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Enter) {
                        drawableManager.addDrawable(new ANDGateDrawable);
                    }
                default:
                    break;
            }

        }
    }


    drawableManager.addDrawable(new ANDGateDrawable);

    drawableManager.draw(window);

    window.display();

    return 0;
}