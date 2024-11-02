#include "NOTGateDrawable.h"

NOTGateDrawable::NOTGateDrawable(const sf::Vector2f pos, const int inSize) : ComponentDrawable(pos, inSize) {
    int i;
    name = "NOT";
    m_shape = sf::VertexArray(sf::Triangles, 6);
    m_center_position = pos;
    m_shape[0].position = m_center_position + sf::Vector2f(0, -NOTGATESIZE);
    m_shape[1].position = m_center_position + sf::Vector2f(-NOTGATESIZE, NOTGATESIZE);
    m_shape[2].position = m_center_position + sf::Vector2f(NOTGATESIZE, NOTGATESIZE);
    m_shape[3].position = m_center_position + sf::Vector2f(0, -NOTGATESIZE);
    m_shape[4].position = m_center_position + sf::Vector2f(-NOTGATESIZE, NOTGATESIZE);
    m_shape[5].position = m_center_position + sf::Vector2f(NOTGATESIZE, NOTGATESIZE);
    m_shape[0].color = sf::Color::Red;
    m_shape[1].color = sf::Color::Red;
    m_shape[2].color = sf::Color::Red;
    m_shape[3].color = sf::Color::Red;
    m_shape[4].color = sf::Color::Red;
    m_shape[5].color = sf::Color::Red;

    for(i = 0; i < inSize; i++) {
        inputPositions.push_back(m_center_position + sf::Vector2f((2 * NOTGATESIZE)/(inSize + 1.0f) *  (i + 1.0f) - NOTGATESIZE, NOTGATESIZE));
    }
    outputPosition = m_center_position + sf::Vector2f(0.0f, -NOTGATESIZE);
}

void NOTGateDrawable::update() {
    int i;
    m_shape[0].position = m_center_position + sf::Vector2f(0, -NOTGATESIZE);
    m_shape[1].position = m_center_position + sf::Vector2f(-NOTGATESIZE, NOTGATESIZE);
    m_shape[2].position = m_center_position + sf::Vector2f(NOTGATESIZE, NOTGATESIZE);
    m_shape[3].position = m_center_position + sf::Vector2f(0, -NOTGATESIZE);
    m_shape[4].position = m_center_position + sf::Vector2f(-NOTGATESIZE, NOTGATESIZE);
    m_shape[5].position = m_center_position + sf::Vector2f(NOTGATESIZE, NOTGATESIZE);

    for(i = 0; i < inputSize; i++) {
        inputPositions[i] = (m_center_position + sf::Vector2f((2 * NOTGATESIZE)/(inputSize + 1.0f) *  (i + 1.0f) - NOTGATESIZE, NOTGATESIZE));
    }
    outputPosition = m_center_position + sf::Vector2f(0.0f, -NOTGATESIZE);
}

void NOTGateDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_shape, states);
    //draw name
}

NOTGateDrawable *NOTGateDrawable::selfAllocate(const sf::Vector2f pos, const int inSize) {
    return new NOTGateDrawable(pos, inSize);
}
