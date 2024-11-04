#ifndef ORGATEDRAWABLE_H
#define ORGATEDRAWABLE_H

#define ORGATESIZE 15.0f

#include "../ComponentDrawable.h"

class ORGateDrawable : public ComponentDrawable {
public:
    ORGateDrawable(sf::Vector2f pos, int inSize);

    void update() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    ORGateDrawable *selfAllocate(sf::Vector2f pos, int inSize) override;
};


#endif //ORGATEDRAWABLE_H
