#ifndef ANDGATEDRAWABLE_H
#define ANDGATEDRAWABLE_H

#define ANDGATESIZE 15.0f

#include "../ComponentDrawable.h"

class ANDGateDrawable : public ComponentDrawable {
public:
    ANDGateDrawable(sf::Vector2f pos, int inSize);

    void update() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    ANDGateDrawable *selfAllocate(sf::Vector2f pos, int inSize) override;
};

#endif //ANDGATEDRAWABLE_H
