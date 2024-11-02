//
// Created by jvgam on 29/ORGATESIZE/2024.
//

#include "ORGateDrawable.h"

ORGateDrawable::ORGateDrawable(const sf::Vector2f pos, const int inSize) : ComponentDrawable(pos, inSize){
    int i = 0;
    name = "OR";
    m_shape = sf::VertexArray(sf::Triangles, 6);
    m_center_position = pos;
    m_shape[0].position = m_center_position + sf::Vector2f(-ORGATESIZE, -ORGATESIZE);
    m_shape[1].position = m_center_position + sf::Vector2f(ORGATESIZE, -ORGATESIZE);
    m_shape[2].position = m_center_position + sf::Vector2f(-ORGATESIZE, ORGATESIZE);
    m_shape[3].position = m_center_position + sf::Vector2f(ORGATESIZE, -ORGATESIZE);
    m_shape[4].position = m_center_position + sf::Vector2f(-ORGATESIZE, ORGATESIZE);
    m_shape[5].position = m_center_position + sf::Vector2f(ORGATESIZE, ORGATESIZE);
    m_shape[0].color = sf::Color::Blue;
    m_shape[1].color = sf::Color::Blue;
    m_shape[2].color = sf::Color::Blue;
    m_shape[3].color = sf::Color::Blue;
    m_shape[4].color = sf::Color::Blue;
    m_shape[5].color = sf::Color::Blue;
    for(i = 0; i < inSize; i++) {
        inputPositions.push_back(m_center_position + sf::Vector2f((2 * ORGATESIZE)/(inSize + 1.0f) *  (i + 1.0f) - ORGATESIZE, ORGATESIZE));
    }
    outputPosition = m_center_position + sf::Vector2f(0.0f, -ORGATESIZE);
}

void ORGateDrawable::update() {
    int i;
    m_shape[0].position = m_center_position + sf::Vector2f(-ORGATESIZE, -ORGATESIZE);
    m_shape[1].position = m_center_position + sf::Vector2f(ORGATESIZE, -ORGATESIZE);
    m_shape[2].position = m_center_position + sf::Vector2f(-ORGATESIZE, ORGATESIZE);
    m_shape[3].position = m_center_position + sf::Vector2f(ORGATESIZE, -ORGATESIZE);
    m_shape[4].position = m_center_position + sf::Vector2f(-ORGATESIZE, ORGATESIZE);
    m_shape[5].position = m_center_position + sf::Vector2f(ORGATESIZE, ORGATESIZE);

    for(i = 0; i < inputSize; i++) {
        inputPositions[i] = m_center_position + sf::Vector2f((2 * ORGATESIZE)/(inputSize + 1.0f) *  (i + 1.0f) - ORGATESIZE, ORGATESIZE);
    }
    outputPosition = m_center_position + sf::Vector2f(0.0f, -ORGATESIZE);
}

void ORGateDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_shape, states);
    // draw text
}

ORGateDrawable *ORGateDrawable::selfAllocate(const sf::Vector2f pos, const int inSize) {
    return new ORGateDrawable(pos, inSize);
}