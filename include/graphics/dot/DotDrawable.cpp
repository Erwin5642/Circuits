#include "DotDrawable.h"

DotDrawable::DotDrawable() {
    dot.setPosition(0, 0);
    isIO = false;
    isOn = false;
}

DotDrawable::DotDrawable(const sf::Vector2f pos, const bool isIO){
    dot = sf::CircleShape(15);
    dot.setPosition(pos);
    position = pos;
    this->isIO = isIO;
    if(isIO) {
        dot.setFillColor(sf::Color::Red);
    }
    else {
        dot.setFillColor(sf::Color::White);
    }
}

DotDrawable::DotDrawable(const DotDrawable &otherDot) {
    dot = otherDot.dot;
    dot.setPosition(otherDot.position);
    isIO = otherDot.isIO;
    if(isIO) {
        dot.setFillColor(sf::Color::Red);
    }
    else {
        dot.setFillColor(sf::Color::White);
    }
}

void DotDrawable::setPosition(sf::Vector2f pos) {
    position = pos;
}

sf::Vector2f DotDrawable::getPosition() const {
    return position;
}

void DotDrawable::changeOnOff() {
    if(isOn) {
        dot.setFillColor(sf::Color::Red);
        isOn = false;
    }
    else {
        dot.setFillColor(sf::Color::Green);
        isOn = true;
    }
}

sf::FloatRect DotDrawable::getGlobalBounds() const {
    return dot.getGlobalBounds();
}

void DotDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(dot, states);
}


