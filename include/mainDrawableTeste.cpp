//
// Created by jvgam on 29/10/2024.
//

#include "ANDGateDrawable.h"
#include "DrawableManager.h"

int main(void){
    sf::RenderWindow window(sf::VideoMode(800,800), "Drawables Manager Teste" );
    DrawableManager drawableManager;

    sf::Event event;



    drawableManager.addDrawable(new ANDGateDrawable);

    drawableManager.draw(window);

    window.display();

    return 0;
}