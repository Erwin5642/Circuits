//
// Created by jvgam on 28/10/2024.
//

#include "ComponentDrawable.h"

ComponentDrawable::ComponentDrawable(){
    m_shape = nullptr;
    position = sf::Vector2f(400, 400);
    height = 30;
    width = 30;
    inputSize = 2;
}

ComponentDrawable::ComponentDrawable(const float x, const float y, const float w, const float h, const int inSize){
    m_shape = nullptr;
    position = sf::Vector2f(x, y);
    height = h;
    width = w;
    inputSize = inSize;
}

ComponentDrawable::~ComponentDrawable() {
    inputSize = 0;
    position = sf::Vector2f(0, 0);
    width = 0;
    height = 0;
}


void ComponentDrawable::setX(const float x){
    position.x = x;
    m_shape->setPosition(sf::Vector2f(x, position.y));
}

void ComponentDrawable::setY(const float y){
    position.y = y;
    m_shape->setPosition(sf::Vector2f(position.x, y));
}

float ComponentDrawable::getX() const {
    return position.x;
}

float ComponentDrawable::getY() const {
    return position.y;
}

void ComponentDrawable::setPosition(const sf::Vector2f pos) {
    position = pos;
    m_shape->setPosition(position);
}

sf::Vector2f ComponentDrawable::getPosition() const {
    return position;
}

void ComponentDrawable::setInputSize(const int inSize) {
    inputSize = inSize;
}

int ComponentDrawable::getInputSize() const {
    return inputSize;
}

void ComponentDrawable::setWidth(const float w){
    width = w;
    m_shape->scale(sf::Vector2f(w/width, 1));
}

void ComponentDrawable::setHeight(const float h){
    height = h;
    m_shape->scale(sf::Vector2f(1, h/height));
}

float ComponentDrawable::getWidth() const {
    return width;
}

float ComponentDrawable::getHeight() const {
    return height;
}

void ComponentDrawable::setName(const string &n){
    name = n;
}

string ComponentDrawable::getName() const {
    return name;
}
