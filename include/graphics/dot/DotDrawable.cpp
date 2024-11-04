#include "DotDrawable.h"

DotDrawable::DotDrawable() {
    dot.setPosition(0, 0);
    isIO = false;
    isOn = false;
}

DotDrawable::DotDrawable(const sf::Vector2f pos, const bool isIO) {
    dot = sf::CircleShape(DOT_SIZE);
    dot.setPosition(pos);
    position = pos;
    this->isIO = isIO;
    if (isIO) {
        dot.setFillColor(sf::Color::Red);
    } else {
        dot.setFillColor(sf::Color::Yellow);
    }
    isOn = false;
}

DotDrawable::DotDrawable(const DotDrawable &otherDot) {
    dot = otherDot.dot;
    dot.setPosition(otherDot.position);
    isIO = otherDot.isIO;
    isOn = otherDot.isOn;
    if (isIO) {
        dot.setFillColor(sf::Color::Red);
    } else {
        dot.setFillColor(sf::Color::Yellow);
    }
}

void DotDrawable::setPosition(sf::Vector2f pos) {
    position = pos;
}

sf::Vector2f DotDrawable::getPosition() const {
    return position + sf::Vector2f(dot.getRadius(), dot.getRadius());
}

void DotDrawable::changeOnOff() {
    if (isOn) {
        dot.setFillColor(sf::Color::Red);
        isOn = false;
    } else {
        dot.setFillColor(sf::Color::Green);
        isOn = true;
    }
}

void DotDrawable::changeOnOff(const bool onOff) {
    if (onOff) {
        dot.setFillColor(sf::Color::Green);
        isOn = true;
    } else {
        dot.setFillColor(sf::Color::Red);
        isOn = false;
    }
}

sf::FloatRect DotDrawable::getGlobalBounds() const {
    return dot.getGlobalBounds();
}

void DotDrawable::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(dot, states);
}
