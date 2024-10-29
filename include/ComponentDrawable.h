//
// Created by jvgam on 28/10/2024.
//

#ifndef COMPONENTDRAWABLE_H
#define COMPONENTDRAWABLE_H

#include <SFML\Graphics.hpp>
#include <vector>
#include <string>
using namespace std;

class ComponentDrawable : private sf::Drawable{
private:
    sf::Shape* m_shape;
    string name;
    float width;
    float height;
    int inputSize;
    sf::Vector2f position;
    vector<sf::Shape*> inputShape;
    sf::Shape* outputShape;
public:
    ComponentDrawable();
    ComponentDrawable(float x, float y, float w, float h, int inputSize);
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
    void setLightInput(unsigned int index, bool onOff) const;
    void setLightOutput(bool onOff) const;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;
};

#endif //COMPONENTDRAWABLE_H
