//
// Created by jvgam on 29/10/2024.
//

#include "ORGateDrawable.h"

ORGateDrawable::ORGateDrawable() {
    name = "OR";
    m_shape = new sf::RectangleShape(sf::Vector2f(width, height));
    m_shape->setFillColor(sf::Color::Green);
}

void ORGateDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*m_shape, states);
    // draw text
}

ORGateDrawable::~ORGateDrawable() {
    if(m_shape != nullptr) {
        delete m_shape;
        m_shape = nullptr;
    }
}