//
// Created by jvgam on 28/10/2024.
//

#ifndef ANDGATEDRAWABLE_H
#define ANDGATEDRAWABLE_H

#include "ComponentDrawable.h"

class ANDGateDrawable : public ComponentDrawable{
public:
    ANDGateDrawable();
    ANDGateDrawable(float x, float y, float w, float h, int inSize);
    ~ANDGateDrawable() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    ANDGateDrawable* selfAllocate() const override;
    ANDGateDrawable* selfAllocate(float x, float y, float w, float h, in inSize) const override;
};

#endif //ANDGATEDRAWABLE_H
