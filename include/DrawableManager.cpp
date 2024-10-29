//
// Created by jvgam on 28/10/2024.
//

#include "DrawableManager.h"

DrawableManager::DrawableManager(const int nDrawables){
      int i = 0;
      numDrawables = nDrawables;
      for(i = 0; i < numDrawables; i++){
            drawables.push_back(nullptr);
      }
}

DrawableManager::~DrawableManager(){
      removeAllDrawables();
}

void DrawableManager::addDrawable(ComponentDrawable* drawable){
      drawables.push_back(drawable);
}

void DrawableManager::removeDrawable(const unsigned int index){
      delete drawables[index];
      drawables.erase(drawables.begin() + index);
}

void DrawableManager::removeAllDrawables() {
      int i = 0;
      for(i = 0; i < numDrawables; i++){
            delete drawables[i];
      }
      numDrawables = 0;
      drawables.clear();
}

void DrawableManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
      int i = 0;
      for(i = 0; i < numDrawables; i++){
            drawables[i]->draw(target, states);
      }
}