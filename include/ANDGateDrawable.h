//
// Created by jvgam on 28/10/2024.
//

#ifndef ANDGATEDRAWABLE_H
#define ANDGATEDRAWABLE_H

#include "ComponentDrawable.h"

class ANDGateDrawable : public ComponentDrawable{
    ANDGateDrawable();
    ANDGateDrawable(int x, int y, int width, int height);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //ANDGATEDRAWABLE_H
