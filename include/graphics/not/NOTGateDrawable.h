#ifndef NOTGATEDRAWABLE_H
#define NOTGATEDRAWABLE_H

#define NOTGATESIZE 15.0f

#include "../ComponentDrawable.h"

class NOTGateDrawable : public ComponentDrawable {
public:
    NOTGateDrawable(sf::Vector2f pos, int inSize);

    void update() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    NOTGateDrawable *selfAllocate(sf::Vector2f pos, int inSize) override;
};

#endif //NOTGATEDRAWABLE_H
