//
// Created by jvgam on 31/10/2024.
//

#ifndef WIREDRAWABLE_H
#define WIREDRAWABLE_H

#include "../ComponentDrawable.h"
#include "../dot/DotDrawable.h"

class WireDrawable : public ComponentDrawable{
    DotDrawable *dotOut;
    DotDrawable *dotIn;

    public:
    WireDrawable(sf::Vector2f posIn, sf::Vector2f posOut);
    ~WireDrawable() override;
    void connectGateIn(ComponentDrawable *inWire) override;
    void connectGateOut(ComponentDrawable *outWire) override;
    void connectGateIn(DotDrawable *inDot);
    void connectGateOut(DotDrawable *outDot);
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    WireDrawable *selfAllocate(sf::Vector2f posIn, sf::Vector2f posOut);
    WireDrawable *selfAllocate(sf::Vector2f pos, int inSize) override;
};



#endif //WIREDRAWABLE_H
