//
// Created by jvgam on 28/10/2024.
//

#ifndef DRAWABLEMANAGER_H
#define DRAWABLEMANAGER_H

#include "ComponentDrawable.h"

class DrawableManager {
    vector<ComponentDrawable*> drawables;
    int numDrawables;
    public:
    DrawableManager();
    explicit DrawableManager(int nDrawables);
    ~DrawableManager();
    void addDrawable(ComponentDrawable* drawable);
    void removeDrawable(unsigned int index);
    void removeAllDrawables();
    void updatePosition(unsigned int index, sf::Vector2f position) const;
    void updateInputLights(unsigned int index, unsigned int inputIndex, bool onOff) const;
    void updateOutputLights(unsigned int index, bool onOff) const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};



#endif //DRAWABLEMANAGER_H
