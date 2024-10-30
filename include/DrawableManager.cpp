//
// Created by jvgam on 28/10/2024.
//

#define MATRIX_INIT_X 100
#define MATRIX_INIT_Y 200
#define INPUT_POINTS_Y 100
#define OUTPUT_POINTS_Y 800

#include "DrawableManager.h"

DrawableManager::DrawableManager(): contactPoints{}, inputPoints{}, outputPoints{} {
    int i = 0, j = 0;
    numDrawables = 0;
    for (i = 0; i < 8; i++) {
        inputPoints[i] = DotDrawable(MATRIX_INIT_X + i * 20, INPUT_POINTS_Y);
        outputPoints[i] = DotDrawable(MATRIX_INIT_X + i * 20, OUTPUT_POINTS_Y);
        for (j = 0; j < 8; j++) {
            contactPoints[i][j] = DotDrawable(MATRIX_INIT_X + i * 20, MATRIX_INIT_Y + j * 20);
        }
    }
}

DrawableManager::~DrawableManager() {
    removeAllDrawables();
}

void DrawableManager::addDrawable(const ComponentDrawable *component) {
    drawables.push_back(component->selfAllocate());
}

void DrawableManager::addDrawable(const ComponentDrawable *component, const float x, const float y, const float w, const float h, const int inSize) {
    drawables.push_back(component->selfAllocate(x, y, w, h, inSize));
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
