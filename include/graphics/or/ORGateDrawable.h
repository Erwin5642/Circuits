//
// Created by jvgam on 29/10/2024.
//

#ifndef ORGATEDRAWABLE_H
#define ORGATEDRAWABLE_H

#include "../ComponentDrawable.h"

class ORGateDrawable : public ComponentDrawable {
public:
    ORGateDrawable();
    ORGateDrawable(float x, float y, float w, float h, int inSize);
    ~ORGateDrawable() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    ORGateDrawable *selfAllocate() const override;
    ORGateDrawable *selfAllocate(float x, float y, float w, float h, int inSize) const override;
};



#endif //ORGATEDRAWABLE_H
