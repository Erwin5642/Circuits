//
// Created by jvgam on 28/10/2024.
//

#ifndef DRAWABLEMANAGER_H
#define DRAWABLEMANAGER_H

#include "ComponentDrawable.h"
#include "DotDrawable.h"

class DrawableManager {
    vector<ComponentDrawable*> drawables;
    DotDrawable contactPoints[8][8];
    DotDrawable inputPoints[8];
    DotDrawable outputPoints[8];
    int numDrawables;
    public:
    DrawableManager();
    ~DrawableManager();
    void addDrawable(ComponentDrawable* drawable);
    void removeDrawable(unsigned int index);
    void removeAllDrawables();
    void updatePosition(unsigned int index, sf::Vector2f position) const;
    void updateValueInOut(bool inOut, unsigned int index, bool onOff);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};



#endif //DRAWABLEMANAGER_H
