//
// Created by jvgam on 28/10/2024.
//

#ifndef ANDGATEDRAWABLE_H
#define ANDGATEDRAWABLE_H

#include "ComponentDrawable.h"

class ANDGateDrawable : public ComponentDrawable{
public:
    ANDGateDrawable();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    ~ANDGateDrawable() override;
};

#endif //ANDGATEDRAWABLE_H
