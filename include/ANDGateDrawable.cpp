//
// Created by jvgam on 28/10/2024.
//

#include "ANDGateDrawable.h"

ANDGateDrawable::ANDGateDrawable() {
    name = "AND";
    m_shape = new sf::RectangleShape(sf::Vector2f(width, height));
    m_shape->setFillColor(sf::Color::Blue);
}

ANDGateDrawable::ANDGateDrawable(const float x, const float y, const float w, const float h, const int inSize) : ComponentDrawable(x, y, w, h, inSize) {
    name = "AND";
    m_shape = new sf::RectangleShape(sf::Vector2f(width, height));
    m_shape->setFillColor(sf::Color::Blue);
}

void ANDGateDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*m_shape, states);
}

ANDGateDrawable::~ANDGateDrawable() {
    if(m_shape != nullptr) {
        delete m_shape;
        m_shape = nullptr;
    }
}

ANDGateDrawable *ANDGateDrawable::selfAllocate() const {
    return new ANDGateDrawable;
}

ANDGateDrawable *ANDGateDrawable::selfAllocate(const float x, const float y, const float w, const float h, const int inSize) const {
    return new ANDGateDrawable(x,y, w, h, inSize);
}



