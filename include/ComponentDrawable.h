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
    sf::Vector2f position;
    vector<sf::Shape*> outputShape;
    vector<sf::Shape*> inputShape;
public:
    ComponentDrawable();
    ComponentDrawable(int x, int y, int w, int h);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
    void setX(int x);
    void setY(float y);
    int getInputSize() const;
    int getOutputSize() const;
    float getX() const;
    float getY() const;
    void setPos(sf::Vector2f pos);
    sf::Vector2f getPos() const;
    void setWidth(float w);
    void setHeight(float h);
    float getWidth() const;
    float getHeight() const;
    string getName() const;
    void setName(string name);
    void setLightInput(int index, bool onOff);
    void setLightOutput(int index, bool onOff);
};

#endif //COMPONENTDRAWABLE_H
