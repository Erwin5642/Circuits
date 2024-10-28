//
// Created by jvgam on 28/10/2024.
//

#include "ComponentDrawable.h"

ComponentDrawable::ComponentDrawable(){
    position = sf::Vector2f(0, 0);
    height = 20;
    width = 15;
}

ComponentDrawable::ComponentDrawable(int x, int y, int w, int h){
    position = sf::Vector2f(x, y);
    height = h;
    width = w;
}

void ComponentDrawable::setPosition(sf::Vector2f pos) {
    position = pos;
}

void ComponentDrawable::setHeight(int h){
    height = h;
}

void ComponentDrawable::setWidth(int w){
    width = w;
}

void ComponentDrawable::setX(int x){
    position.x = x;
}

void ComponentDrawable::setY(int y){
    position.y = y;
}

void ComponentDrawable::setName(string n){
    name = name;
}

void ComponentDrawable::setLightInput(const int index, const bool onOff) const{
    if(onOff) {
        inputShape[index]->setFillColor(sf::Color::White);
    }
    else {
        inputShape[index]->setFillColor(sf::Color::Black);
    }
}


