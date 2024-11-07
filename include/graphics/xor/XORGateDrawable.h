#ifndef XORGATEDRAWABLE_H
#define XORGATEDRAWABLE_H

#define XORGATESIZE 15.0f

#include "../ComponentDrawable.h"

class XORGateDrawable final : public ComponentDrawable {
public:
    XORGateDrawable(sf::Vector2f pos, int inSize);

    void update() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    XORGateDrawable *selfAllocate(sf::Vector2f pos, int inSize) override;
};



#endif //XORGATEDRAWABLE_H
