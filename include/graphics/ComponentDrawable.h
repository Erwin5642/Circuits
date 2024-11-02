#ifndef COMPONENTDRAWABLE_H
#define COMPONENTDRAWABLE_H

#include <SFML\Graphics.hpp>
#include <vector>
#include <string>
using namespace std;

class ComponentDrawable : public sf::Drawable{
protected:
    sf::VertexArray m_shape;
    sf::Vector2f m_center_position;
    string name;
    int inputSize;
    int usedInputs;
    bool isOutputUsed;
    vector<sf::Vector2f> inputPositions;
    sf::Vector2f outputPosition;
    sf::Vector2i positionInGrid;
    vector<ComponentDrawable*> wiresInput;
    ComponentDrawable *wireOutput;

public:
    ComponentDrawable(sf::Vector2f pos, int inSize);
    ~ComponentDrawable() override;
    virtual void update() = 0;
    void setGridPosition(sf::Vector2i pos);
    sf::Vector2i getGridPosition() const;
    void setCenterPosition(sf::Vector2f pos);
    sf::Vector2f getCenterPosition() const;
    void setInputSize(int inSize);
    int getInputSize() const;
    void setUsedInputSize(int usedSize);
    void setOutputUsed();
    bool getOutputUsed() const;
    int getUsedInputsSize() const;
    void setInputPosition(unsigned int index, sf::Vector2f pos);
    void setOutputPosition(sf::Vector2f pos);
    sf::Vector2f getInputPosition(unsigned int index) const;
    sf::Vector2f getOutputPosition() const;
    sf::FloatRect getBounds() const;
    void setName(const string &n);
    string getName() const;
    virtual void connectGateOut(ComponentDrawable *outWire);
    virtual void connectGateIn(ComponentDrawable *inWire);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;
    virtual ComponentDrawable *selfAllocate(sf::Vector2f pos, int inSize) = 0;
};

#endif //COMPONENTDRAWABLE_H
