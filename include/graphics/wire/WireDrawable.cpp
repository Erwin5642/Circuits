//
// Created by jvgam on 31/10/2024.
//

#include "WireDrawable.h"

WireDrawable::WireDrawable(const sf::Vector2f posIn, const sf::Vector2f posOut) : ComponentDrawable(
sf::Vector2f((posIn.x + posIn.x) / 2.0f, (posIn.y + posOut.y) / 2.0f), 1) {
    name = "Wire";
    m_shape = sf::VertexArray(sf::Lines, 2);
    outputPosition = posOut;
    inputPositions.push_back(posIn);
    dotIn = nullptr;
    dotOut = nullptr;
    m_shape[0].position = posIn;
    m_shape[1].position = posOut;
    usedInputs = 1;
}

WireDrawable::~WireDrawable() {
    m_shape.clear();
    dotIn = nullptr;
    dotOut = nullptr;
}

void WireDrawable::connectGateIn(ComponentDrawable *inWire) {
    inputPositions[0] = inWire->getOutputPosition();
    usedInputs = 1;
}

void WireDrawable::connectGateOut(ComponentDrawable *outWire) {
    const int s = outWire->getUsedInputsSize();
    outputPosition = outWire->getInputPosition(s);
    outWire->setUsedInputSize(s + 1);
}

void WireDrawable::connectGateIn(DotDrawable *inDot) {
    dotIn = inDot;
    usedInputs = 1;
    inputPositions[0] = inDot->getPosition();
}

void WireDrawable::connectGateOut(DotDrawable *outDot) {
    dotOut = outDot;
    outputPosition = outDot->getPosition();
}

void WireDrawable::update() {
    m_shape[1] = outputPosition;
}


void WireDrawable::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_shape, states);
}

WireDrawable *WireDrawable::selfAllocate(const sf::Vector2f posIn, const sf::Vector2f posOut) {
    return new WireDrawable(posIn, posOut);
}

WireDrawable *WireDrawable::selfAllocate(sf::Vector2f pos, int inSize) {
    return new WireDrawable(pos + sf::Vector2f(0, 10), pos - sf::Vector2f(0, 10));
}
