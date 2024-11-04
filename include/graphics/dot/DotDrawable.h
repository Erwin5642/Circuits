#ifndef DOT_H
#define DOT_H

#define DOT_SIZE 13

#include "SFML\Graphics.hpp"

class DotDrawable : public sf::Drawable {
private:
    sf::CircleShape dot;
    sf::Vector2f position;
    bool isIO;
    bool isOn;

public:
    DotDrawable();

    DotDrawable(sf::Vector2f pos, bool isIO);

    DotDrawable(const DotDrawable &otherDot);

    void setPosition(sf::Vector2f pos);

    sf::Vector2f getPosition() const;

    void changeOnOff();

    void changeOnOff(bool onOff);

    sf::FloatRect getGlobalBounds() const;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //DOT_H
