//
// Created by jvgam on 29/10/2024.
//

#ifndef NOTGATEDRAWABLE_H
#define NOTGATEDRAWABLE_H

#include "ComponentDrawable.h"

class NOTGateDrawable : public ComponentDrawable {
    NOTGateDrawable();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    ~NOTGateDrawable() override;
};

#endif //NOTGATEDRAWABLE_H
