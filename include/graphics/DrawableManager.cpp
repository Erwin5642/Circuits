//
// Created by jvgam on 28/10/2024.
//

#define MATRIX_INIT_X 100
#define MATRIX_INIT_Y 200
#define INPUT_POINTS_Y 100
#define OUTPUT_POINTS_Y 700

#include "DrawableManager.h"

DrawableManager::DrawableManager() {
    int i = 0, j = 0;
    numDrawables = 0;
    for (i = 0; i < 8; i++) {
        inputPoints[i] = DotDrawable(MATRIX_INIT_X + i * 50, INPUT_POINTS_Y);
        outputPoints[i] = DotDrawable(MATRIX_INIT_X + i * 50, OUTPUT_POINTS_Y);
        for (j = 0; j < 8; j++) {
            contactPoints[i][j] = DotDrawable(MATRIX_INIT_X + i * 50, MATRIX_INIT_Y + j * 50);
        }
    }
}

DrawableManager::~DrawableManager() {
    removeAllDrawables();
}

int DrawableManager::getNumDrawables() const {
    return numDrawables;
}

void DrawableManager::addDrawable(const ComponentDrawable *component) {
    drawables.push_back(component->selfAllocate());
    numDrawables++;
}

void DrawableManager::addDrawable(const ComponentDrawable *component, const float x, const float y, const float w, const float h, const int inSize) {
    drawables.push_back(component->selfAllocate(x, y, w, h, inSize));
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

void DrawableManager::updatePosition(const unsigned int index, const sf::Vector2f position) const {
    drawables[index]->setPosition(position);
}

sf::Vector2f DrawableManager::getPosition(const unsigned int index) const {
    return drawables[index]->getPosition();
}

void DrawableManager::updateValueInOut(const bool inOut, const unsigned int index, const bool onOff) {
    if(inOut) {
        inputPoints[index].setOnOff(onOff);
    }
    else {
        outputPoints[index].setOnOff(onOff);
    }
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
