#include "ComponentDrawable.h"

ComponentDrawable::ComponentDrawable(const sf::Vector2f pos, const int inSize) {
    int i;
    m_center_position = pos;
    inputSize = inSize;
    for (i = 0; i < inSize; i++) {
        wiresInput.push_back(nullptr);
    }
    wireOutput = nullptr;
    usedInputs = 0;
    isOutputUsed = false;
}

ComponentDrawable::~ComponentDrawable() {
    int i = 0;
    m_center_position = sf::Vector2f(0, 0);
    for (i = 0; i < inputSize; i++) {
        wiresInput[i] = nullptr;
    }
    wireOutput = nullptr;
    inputSize = 0;
    usedInputs = 0;
}

void ComponentDrawable::setCenterPosition(sf::Vector2f pos) {
    m_center_position = pos;
}

sf::Vector2f ComponentDrawable::getCenterPosition() const {
    return m_center_position;
}

void ComponentDrawable::setInputSize(const int inSize) {
    inputSize = inSize;
}

int ComponentDrawable::getInputSize() const {
    return inputSize;
}

void ComponentDrawable::setOutputUsed() {
    isOutputUsed = true;
}

bool ComponentDrawable::getOutputUsed() const {
    return isOutputUsed;
}

void ComponentDrawable::setUsedInputSize(const int usedSize) {
    usedInputs = usedSize;
}

int ComponentDrawable::getUsedInputsSize() const {
    return usedInputs;
}

void ComponentDrawable::setInputPosition(unsigned int index, sf::Vector2f pos) {
    inputPositions[index] = pos;
}

void ComponentDrawable::setOutputPosition(sf::Vector2f pos) {
    outputPosition = pos;
}

sf::Vector2f ComponentDrawable::getInputPosition(const unsigned int index) const {
    return inputPositions[index];
}

sf::Vector2f ComponentDrawable::getOutputPosition() const {
    return outputPosition;
}

sf::FloatRect ComponentDrawable::getBounds() const {
    return m_shape.getBounds();
}

void ComponentDrawable::setName(const string &n) {
    name = n;
}

string ComponentDrawable::getName() const {
    return name;
}

void ComponentDrawable::connectGateOut(ComponentDrawable *outWire) {
    wireOutput = outWire;
    isOutputUsed = true;
}

void ComponentDrawable::connectGateIn(ComponentDrawable *inWire) {
    wiresInput[usedInputs-1] = inWire;
}

void ComponentDrawable::connectGateIn(const DotDrawable *inDot) {

}

void ComponentDrawable::connectGateOut(const DotDrawable *outDot) {

}

ComponentDrawable *ComponentDrawable::getWireInput(unsigned int i) const {
    return wiresInput[i];
}

ComponentDrawable *ComponentDrawable::getWireOutput() const {
    return wireOutput;
}
