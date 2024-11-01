//
// Created by jvgam on 28/10/2024.
//

#ifndef COMPONENTDRAWABLE_H
#define COMPONENTDRAWABLE_H

#include <SFML\Graphics.hpp>
#include "ORGateDrawable.h"
#include "ANDGateDrawable.h"
#include "NOTGateDrawable.h"
#include <vector>
#include <string>
using namespace std;

class ComponentDrawable : public sf::Drawable{
protected:
    sf::Shape* m_shape;
    string name;
    float width;
    float height;
    int inputSize;
    sf::Vector2f position;
    vector<sf::Vector2f> inputPositions;
    sf::Vector2f outputPosition;
public:
    ComponentDrawable();
    ComponentDrawable(float x, float y, float w, float h, int inSize);
    ~ComponentDrawable() override;
    void setX(float x);
    void setY(float y);
    float getX() const;
    float getY() const;
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition() const;
    void setInputSize(int inSize);
    int getInputSize() const;
    void setWidth(float w);
    void setHeight(float h);
    float getWidth() const;
    float getHeight() const;
    void setName(const string &n);
    string getName() const;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;
    virtual ComponentDrawable *selfAllocate() const = 0;
    virtual ComponentDrawable *selfAllocate(float x, float y, float w, float h, int inSize) const = 0;
};

#endif //COMPONENTDRAWABLE_H
