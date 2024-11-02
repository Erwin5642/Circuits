
#ifndef DRAWABLEMANAGER_H
#define DRAWABLEMANAGER_H

#define GRID_SIZE 8
#define MATRIX_INIT_X 200
#define MATRIX_INIT_Y 200
#define INPUT_POINTS_Y 100
#define OUTPUT_POINTS_Y 700
#define AND_SPAWN {100, 100}
#define OR_SPAWN {100, 200}
#define NOT_SPAWN {100, 300}


#include "ComponentDrawable.h"
#include "Dot/DotDrawable.h"
#include "wire/WireDrawable.h"

class DrawableManager {
    vector<ComponentDrawable *> drawables;
    DotDrawable contactPoints[GRID_SIZE][GRID_SIZE];
    DotDrawable inputPoints[GRID_SIZE];
    DotDrawable outputPoints[GRID_SIZE];
    int numDrawables;

public:
    DrawableManager();

    ~DrawableManager();

    int getNumDrawables() const;

    void addDrawable(ComponentDrawable *component, sf::Vector2f pos, int inSize);

    void addWire(WireDrawable *wire, sf::Vector2f posIn, sf::Vector2f posOut);

    void removeDrawable(unsigned int index);

    void removeAllDrawables();

    void updateDrawables() const;

    void setGridPosition(unsigned int index, sf::Vector2i position) const;

    sf::Vector2i getGridPosition(unsigned int index) const;

    void setCenterPosition(unsigned int index, sf::Vector2f position) const;

    sf::Vector2f getCenterPosition(unsigned int index) const;

    void setInputPosition(unsigned int index, unsigned int inputIndex, sf::Vector2f position) const;

    sf::Vector2f getInputPosition(unsigned int index, unsigned int inputIndex) const;

    int getInputSize(unsigned int index) const;

    void setOutputPosition(unsigned int index, sf::Vector2f position) const;

    sf::Vector2f getOutputPosition(unsigned int index) const;

    void setUsedInputSize(unsigned int index, int usedSize);

    int getUsedInputsSize(unsigned int index) const;

    void setUsedOutputUsed(unsigned int index);

    bool getOutputUsed(unsigned int index) const;

    sf::FloatRect getBoundariesComponent(unsigned int index) const;

    sf::FloatRect getBoundariesGrid(unsigned int i, unsigned j, unsigned int area) const;

    void changePointOnOff(unsigned int index, unsigned int area);

    sf::Vector2f getPointPosition(unsigned int i, unsigned j, int area) const;

    void connectGatesOut(unsigned int i, ComponentDrawable *outWire);

    void connectGatesIn(unsigned int i, ComponentDrawable *inWire);

    void draw(sf::RenderWindow&  window) const;
};


#endif //DRAWABLEMANAGER_H
