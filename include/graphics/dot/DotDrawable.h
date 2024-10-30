//
// Created by jvgam on 29/10/2024.
//

#ifndef DOT_H
#define DOT_H

#include "SFML\Graphics.hpp"

class DotDrawable : public sf::Drawable{
private:
    sf::CircleShape dot;
    sf::Vector2f position;
public:
    DotDrawable();
    DotDrawable(float x, float y);
    DotDrawable(const DotDrawable& otherDot);
    void setX(float x);
    void setY(float y);
    float getX() const;
    float getY() const;
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition() const;
    void setOnOff(bool onOff);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



#endif //DOT_H
