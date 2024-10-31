//
// Created by jvgam on 29/10/2024.
//

#ifndef NOTGATEDRAWABLE_H
#define NOTGATEDRAWABLE_H

#include "ComponentDrawable.h"

class NOTGateDrawable : public ComponentDrawable {
public:
    NOTGateDrawable();

    NOTGateDrawable(float x, float y, float w, float h, int inSize);

    ~NOTGateDrawable() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    NOTGateDrawable *selfAllocate() const override;

    NOTGateDrawable *selfAllocate(float x, float y, float w, float h, int inSize) const override;
};

#endif //NOTGATEDRAWABLE_H
