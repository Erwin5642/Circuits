//
// Created by jvgam on 28/10/2024.
//

#ifndef COMPONENTLOGIC_H
#define COMPONENTLOGIC_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;

class ComponentLogic {
private:
    string name;
    sf::Vector2f position;
public:
    ComponentLogic();
    ComponentLogic(int x, int y);
    void setX(int x);
    void setY(int y);
    int getInputSize() const;
    int getOutputSize() const;
    float getX() const;
    float getY() const;
    void setPos(sf::Vector2f pos);
    sf::Vector2f getPos() const;
    string getName() const;
    void setName(string name);
};

#endif //COMPONENTLOGIC_H