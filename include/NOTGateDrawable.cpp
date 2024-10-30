//
// Created by jvgam on 29/10/2024.
//

#include "NOTGateDrawable.h"

NOTGateDrawable::NOTGateDrawable() {
    name = "NOT";
    m_shape = new sf::RectangleShape(sf::Vector2f(width, height));
    m_shape->setFillColor(sf::Color::Red);
}

NOTGateDrawable::NOTGateDrawable(const float x, const float y, const float w, const float h, const int inSize) : ComponentDrawable(x, y, w, h, inSize) {
    name = "NOT";
    m_shape = new sf::RectangleShape(sf::Vector2f(width, height));
    m_shape->setFillColor(sf::Color::Red);
}

NOTGateDrawable::~NOTGateDrawable() {
    if(m_shape != nullptr) {
        delete m_shape;
        m_shape = nullptr;
    }
}

void NOTGateDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*m_shape, states);
    //draw name
}

NOTGateDrawable *NOTGateDrawable::selfAllocate() const {
    return new NOTGateDrawable;
}

NOTGateDrawable *NOTGateDrawable::selfAllocate(const float x, const float y, const float w, const float h, const int inSize) const {
    return new NOTGateDrawable(x, y, w, h, inSize);
}
