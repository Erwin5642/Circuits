#include "DrawableManager.h"

#include "wire/WireDrawable.h"

DrawableManager::DrawableManager(){
    int i = 0, j = 0;
    numDrawables = 0;
    for (i = 0; i < 8; i++) {

        inputPoints[i] = DotDrawable(sf::Vector2f(MATRIX_INIT_X + i * 50, INPUT_POINTS_Y), true);
        outputPoints[i] = DotDrawable(sf::Vector2f(MATRIX_INIT_X + i * 50, OUTPUT_POINTS_Y), true);
        for (j = 0; j < 8; j++) {
            contactPoints[i][j] = DotDrawable(sf::Vector2f(MATRIX_INIT_X + i * 50, MATRIX_INIT_Y + j * 50), false);
        }
    }
}

DrawableManager::~DrawableManager() {
    removeAllDrawables();
}

int DrawableManager::getNumDrawables() const {
    return numDrawables;
}

void DrawableManager::addDrawable(ComponentDrawable *component, sf::Vector2f pos, const int inSize) {
    drawables.push_back(component->selfAllocate(pos, inSize));
    numDrawables++;
}

void DrawableManager::addWire(WireDrawable *wire, sf::Vector2f posIn, sf::Vector2f posOut) {
    drawables.push_back(wire->selfAllocate(posIn, posOut));
    numDrawables++;
}

void DrawableManager::removeDrawable(const unsigned int index) {
    delete drawables[index];
    drawables.erase(drawables.begin() + index);
}

void DrawableManager::removeAllDrawables() {
    int i = 0;
    for (i = 0; i < numDrawables; i++) {
        delete drawables[i];
    }
    numDrawables = 0;
    drawables.clear();
}

void DrawableManager::updateDrawables()const  {
    int i = 0;
    for(i = 0; i < numDrawables; i++) {
        drawables[i]->update();
    }
}

void DrawableManager::setGridPosition(const unsigned int index, const sf::Vector2f position) const {
    drawables[index]->setGridPosition(position);
}

sf::Vector2f DrawableManager::getGridPosition(const unsigned int index) const {
    return drawables[index]->getGridPosition();
}

void DrawableManager::setCenterPosition(unsigned int index, sf::Vector2f position) const {
    if(numDrawables > index) {
        drawables[index]->setCenterPosition(position);
    }
}

sf::Vector2f DrawableManager::getCenterPosition(unsigned int index) const {
    if(numDrawables > index) {
        return drawables[index]->getCenterPosition();
    }
    return  {0, 0};
}

void DrawableManager::setInputPosition(unsigned int index, unsigned int inputIndex, sf::Vector2f position) const {
    drawables[index]->setInputPosition(inputIndex, position);
}

void DrawableManager::setOutputPosition(unsigned int index, sf::Vector2f position) const {
    drawables[index]->setOutputPosition(position);
}

int DrawableManager::getUsedInputsSize(unsigned int index) const {
    return drawables[index]->getUsedInputsSize();
}

void DrawableManager::setUsedInputSize(unsigned int index, int usedSize) const {
    drawables[index]->setUsedInputSize(usedSize);
}

void DrawableManager::setUsedOutputUsed(unsigned int index) const {
    drawables[index]->setOutputUsed();
}

bool DrawableManager::getOutputUsed(unsigned int index) const {
    return drawables[index]->getOutputUsed();
}

sf::Vector2f DrawableManager::getOutputPosition(unsigned int index) const {
    return drawables[index]->getOutputPosition();
}

sf::Vector2f DrawableManager::getInputPosition(unsigned int index, unsigned int inputIndex) const {
    return drawables[index]->getInputPosition(inputIndex);
}

int DrawableManager::getInputSize(unsigned int index) const {
    return drawables[index]->getInputSize();
}


sf::FloatRect DrawableManager::getBoundariesComponent(unsigned int index) const {
    if(numDrawables > index) {
        return drawables[index]->getBounds();
    }
    return {};
}

sf::FloatRect DrawableManager::getBoundariesGrid(unsigned int i, unsigned j, unsigned int area) const {
    switch (area) {
        case 1:
            return  inputPoints[i].getGlobalBounds();
        case 2:
            return contactPoints[i][j].getGlobalBounds();
        case 3:
            return  outputPoints[i].getGlobalBounds();
        default:
            break;;
    }
    return {};
}

void DrawableManager::changePointOnOff(unsigned int index, unsigned int area) {
    if(area == 1) {
        inputPoints[index].changeOnOff();
    }
    else if(area == 2) {
        outputPoints[index].changeOnOff();
    }
}

sf::Vector2f DrawableManager::getPointPosition(unsigned int i, unsigned j, int area) const {
    switch (area) {
        case 1:
            return  inputPoints[i].getPosition();
        case 2:
            return contactPoints[i][j].getPosition();
        case 3:
            return  outputPoints[i].getPosition();
        default:
            break;;
    }
    return {0, 0};
}

void DrawableManager::connectGatesIn(unsigned int i, ComponentDrawable *inWire) const {
    drawables[i]->connectGateIn(inWire);
}

void DrawableManager::connectGatesOut(unsigned int i, ComponentDrawable *outWire) const {
    drawables[i]->connectGateOut(outWire);
}

void DrawableManager::connectGatesIn(unsigned int i, const DotDrawable *dotIn) const {
    drawables[i]->connectGateIn(dotIn);
}

void DrawableManager::connectGatesOut(unsigned int i, const DotDrawable *dotOut) const {
    drawables[i]->connectGateOut(dotOut);
}

ComponentDrawable *DrawableManager::getOutputsWire(unsigned i) const {
    return drawables[i]->getWireOutput();
}

ComponentDrawable *DrawableManager::getInputsWires(unsigned int i, unsigned int inputIndex) const {
    return drawables[i]->getWireInput(inputIndex);
}

const DotDrawable *DrawableManager::getPointReference(unsigned int i, unsigned j, unsigned int area) const {
    switch (area) {
        case 1:
            return  &inputPoints[i];
        case 2:
            return &contactPoints[i][j];
        case 3:
            return  &outputPoints[i];
        default:
            break;;
    }
    return nullptr;
}

ComponentDrawable *DrawableManager::getComponentReference(unsigned int i) const {
    return drawables[i];
}

void DrawableManager::draw(sf::RenderWindow& window) const {
    int i = 0, j = 0;
    for(i = 0; i < 8; i++) {
        window.draw(inputPoints[i]);
        window.draw(outputPoints[i]);
        for(j = 0; j < 8; j++) {
            window.draw(contactPoints[i][j]);
        }
    }
    for (i = 0; i < numDrawables; i++) {
        window.draw(*(drawables[i]));
    }
}
