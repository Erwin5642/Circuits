#include "XORGateDrawable.h"

XORGateDrawable::XORGateDrawable(const sf::Vector2f pos, const int inSize) : ComponentDrawable(pos, inSize) {
    int i = 0;
    name = "XOR";
    m_shape = sf::VertexArray(sf::Triangles, 6);
    m_center_position = pos;
    m_shape[0].position = m_center_position + sf::Vector2f(-XORGATESIZE, -XORGATESIZE);
    m_shape[1].position = m_center_position + sf::Vector2f(XORGATESIZE, -XORGATESIZE);
    m_shape[2].position = m_center_position + sf::Vector2f(-XORGATESIZE, XORGATESIZE);
    m_shape[3].position = m_center_position + sf::Vector2f(XORGATESIZE, -XORGATESIZE);
    m_shape[4].position = m_center_position + sf::Vector2f(-XORGATESIZE, XORGATESIZE);
    m_shape[5].position = m_center_position + sf::Vector2f(XORGATESIZE, XORGATESIZE);
    m_shape[0].color = sf::Color::Magenta;
    m_shape[1].color = sf::Color::Magenta;
    m_shape[2].color = sf::Color::Magenta;
    m_shape[3].color = sf::Color::Magenta;
    m_shape[4].color = sf::Color::Magenta;
    m_shape[5].color = sf::Color::Magenta;
    for (i = 0; i < inSize; i++) {
        inputPositions.push_back(
            m_center_position + sf::Vector2f((2 * XORGATESIZE) / (inSize + 1.0f) * (i + 1.0f) - XORGATESIZE, XORGATESIZE));
    }
    outputPosition = m_center_position + sf::Vector2f(0.0f, -XORGATESIZE);
}

void XORGateDrawable::update() {
    int i;
    m_shape[0].position = m_center_position + sf::Vector2f(-XORGATESIZE, -XORGATESIZE);
    m_shape[1].position = m_center_position + sf::Vector2f(XORGATESIZE, -XORGATESIZE);
    m_shape[2].position = m_center_position + sf::Vector2f(-XORGATESIZE, XORGATESIZE);
    m_shape[3].position = m_center_position + sf::Vector2f(XORGATESIZE, -XORGATESIZE);
    m_shape[4].position = m_center_position + sf::Vector2f(-XORGATESIZE, XORGATESIZE);
    m_shape[5].position = m_center_position + sf::Vector2f(XORGATESIZE, XORGATESIZE);

    for (i = 0; i < inputSize; i++) {
        inputPositions[i] = m_center_position + sf::Vector2f(
                                (2 * XORGATESIZE) / (inputSize + 1.0f) * (i + 1.0f) - XORGATESIZE, XORGATESIZE);
    }
    outputPosition = m_center_position + sf::Vector2f(0.0f, -XORGATESIZE);
}

void XORGateDrawable::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_shape, states);
    // draw text
}

XORGateDrawable *XORGateDrawable::selfAllocate(const sf::Vector2f pos, const int inSize) {
    return new XORGateDrawable(pos, inSize);
}
