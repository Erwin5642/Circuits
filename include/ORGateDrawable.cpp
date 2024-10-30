//
// Created by jvgam on 29/10/2024.
//

#include "ORGateDrawable.h"

ORGateDrawable::ORGateDrawable() {
    name = "OR";
    m_shape = new sf::RectangleShape(sf::Vector2f(width, height));
    m_shape->setPosition(position);
    m_shape->setFillColor(sf::Color::Green);
}

ORGateDrawable::ORGateDrawable(const float x, const float y, const float w, const float h, const int inSize) : ComponentDrawable(x, y, w, h, inSize){
    name = "OR";
    position = sf::Vector2f(x, y);
    m_shape = new sf::RectangleShape(sf::Vector2f(width, height));
    m_shape->setPosition(position);
    m_shape->setFillColor(sf::Color::Green);
}

ORGateDrawable::~ORGateDrawable() {
    if(m_shape != nullptr) {
        delete m_shape;
        m_shape = nullptr;
    }
}

void ORGateDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*m_shape, states);
    // draw text
}

ORGateDrawable *ORGateDrawable::selfAllocate() const {
    return new ORGateDrawable;
}

ORGateDrawable *ORGateDrawable::selfAllocate(const float x, const float y, const float w, const float h, const int inSize) const {
    return new ORGateDrawable(x, y, w, h, inSize);
}