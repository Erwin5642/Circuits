//
// Created by jvgam on 28/10/2024.
//

#ifndef COMPONENTLOGIC_H
#define COMPONENTLOGIC_H

#include <vector>

using namespace std;

class ComponentLogic {
private:
    vector<bool> inputValues;
    bool outputValue;
    int inputSize;
public:
    ComponentLogic();
    explicit ComponentLogic(int input);
    virtual ~ComponentLogic() = default;
    int getInputSize() const;
    void setInputValue(unsigned index, bool value);
    void setInputValues(vector<bool> values);
    virtual void evaluate() const = 0;
};

#endif //COMPONENTLOGIC_H