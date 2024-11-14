#include "XORGateDrawable.h"

XORGateDrawable::XORGateDrawable(sf::Vector2f pos, int inSize) : ComponentDrawable(pos, inSize){
    int i;
    name = "XOR";
    m_shape = sf::VertexArray(sf::Triangles, 12);
    m_center_position = pos;
    m_shape[0].position = m_center_position + sf::Vector2f(XORGATESIZE/2, XORGATESIZE);
    m_shape[1].position = m_center_position + sf::Vector2f(-XORGATESIZE, 0);
    m_shape[2].position = m_center_position + sf::Vector2f(0, XORGATESIZE);
    m_shape[3].position = m_center_position + sf::Vector2f(0, XORGATESIZE);
    m_shape[4].position = m_center_position + sf::Vector2f(XORGATESIZE, 0);
    m_shape[5].position = m_center_position + sf::Vector2f(0, XORGATESIZE);
    m_shape[0].color = sf::Color::Magenta;
    m_shape[1].color = sf::Color::Magenta;
    m_shape[2].color = sf::Color::Magenta;
    m_shape[3].color = sf::Color::Magenta;
    m_shape[4].color = sf::Color::Magenta;
    m_shape[5].color = sf::Color::Magenta;

    for(i = 0; i < inSize; i++) {
        inputPositions.push_back(m_center_position + sf::Vector2f((2 * XORGATESIZE)/(inSize + 1.0f) *  (i + 1.0f) - XORGATESIZE, XORGATESIZE));
    }
    outputPosition = m_center_position + sf::Vector2f(0.0f, -XORGATESIZE);
}

void XORGateDrawable::update() {
    m_center_position = pos;
    m_shape[0].position = m_center_position + sf::Vector2f(XORGATESIZE/2, XORGATESIZE);
    m_shape[1].position = m_center_position + sf::Vector2f(-XORGATESIZE, 0);
    m_shape[2].position = m_center_position + sf::Vector2f(0, XORGATESIZE);
    m_shape[3].position = m_center_position + sf::Vector2f(0, XORGATESIZE);
    m_shape[4].position = m_center_position + sf::Vector2f(XORGATESIZE, 0);
    m_shape[5].position = m_center_position + sf::Vector2f(0, XORGATESIZE);

    for(i = 0; i < inputSize; i++) {
        inputPositions[0] = (m_center_position + sf::Vector2f((2 * XORGATESIZE)/(inSize + 1.0f) *  (i + 1.0f) - XORGATESIZE, XORGATESIZE));
    }
    outputPosition = m_center_position + sf::Vector2f(0.0f, -XORGATESIZE);
}

void XORGateDrawable::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_shape, states);
}
