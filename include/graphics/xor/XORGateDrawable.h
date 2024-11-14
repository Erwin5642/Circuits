#ifndef XORGATEDRAWABLE_H
#define XORGATEDRAWABLE_H

#define XORGATESIZE 15.0f
#define XOR_SPAWN {100, 400}

#include "../ComponentDrawable.h"

class XORGateDrawable : public ComponentDrawable{
  public:
  XORGateDrawable(sf::Vector2f pos, int inSize);

  void update() override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  XORGateDrawable *selfAllocate(sf::Vector2f pos, int inSize) override;

};

#endif //XORGATEDRAWABLE_H
