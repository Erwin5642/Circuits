//
// Created by jvgam on 29/10/2024.
//

#include "NOTGateDrawable.h"

NOTGateDrawable::NOTGateDrawable() {
    name = "NOT";
    m_shape = new sf::RectangleShape(sf::Vector2f(width, height));
}

void NOTGateDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*m_shape, states);
    //draw name
}

NOTGateDrawable::~NOTGateDrawable() {
    if(m_shape != nullptr) {
        delete m_shape;
        m_shape = nullptr;
    }
}