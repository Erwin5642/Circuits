//
// Created by jvgam on 29/10/2024.
//

#include "DotDrawable.h"

DotDrawable::DotDrawable(float x, float y){
    dot = sf::CircleShape(15);
}

void DotDrawable::setX(float x) {
    position.x = x;
}

void DotDrawable::setY(float y) {
    position.y = y;
}

float DotDrawable::getX() const {
    return position.x;
}

float DotDrawable::getY() const {
    return  position.y;
}

void DotDrawable::setPosition(sf::Vector2f pos) {
    position = pos;
}

sf::Vector2f DotDrawable::getPosition() const {
    return position;
}

void DotDrawable::setOnOff(bool onOff) {
    if(onOff) {
        dot.setFillColor(sf::Color::Green);
    }
    else {
        dot.setFillColor(sf::Color::Red);
    }
}

void draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(dot, states);
}



