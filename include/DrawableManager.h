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
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};



#endif //DRAWABLEMANAGER_H
