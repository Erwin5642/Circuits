//
// Created by jvgam on 28/10/2024.
//

#include "ComponentLogic.h"

ComponentLogic::ComponentLogic() {
    position = sf::Vector2f(0, 0);
}
ComponentLogic::ComponentLogic(const int x, const int y) {
    position = sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
}
void ComponentLogic::setX(const int x) {
    position.x = static_cast<float>(x);
}
void ComponentLogic::setY(const int y) {
    position.y = static_cast<float>(y);
}
int ComponentLogic::getInputSize() const {

}
int ComponentLogic::getOutputSize() const {

}
float ComponentLogic::getX() const {
    return position.x;
}
float ComponentLogic::getY() const {
    return position.y;
}
void ComponentLogic::setPos(sf::Vector2f pos) {
    position = pos;
}
sf::Vector2f ComponentLogic::getPos() const {
    return position;
}
string ComponentLogic::getName() const {
    return name;
}
void ComponentLogic::setName(string name) {
    name = name;
}