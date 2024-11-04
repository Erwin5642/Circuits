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
    wiresInput[0] = inWire;
    usedInputs = 1;
}

void WireDrawable::connectGateOut(ComponentDrawable *outWire) {
    const int s = outWire->getUsedInputsSize();
    outputPosition = outWire->getInputPosition(s);
    wireOutput = outWire;
    isOutputUsed = true;
    outWire->setUsedInputSize(s + 1);
}

void WireDrawable::connectGateIn(const DotDrawable *inDot) {
    inputPositions[0] = inDot->getPosition();
    usedInputs = 1;
    dotIn = inDot;
}

void WireDrawable::connectGateOut(const DotDrawable *outDot) {
    outputPosition = outDot->getPosition();
    isOutputUsed = true;
    dotOut = outDot;
}

void WireDrawable::update() {
    m_shape[0].position = inputPositions[0];
    m_shape[1].position = outputPosition;
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
