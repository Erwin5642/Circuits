//
// Created by jvgam on 28/10/2024.
//

#ifndef COMPONENTLOGIC_H
#define COMPONENTLOGIC_H

#include <vector>
#include <string>

using namespace std;

class ComponentLogic {
protected:
    vector<bool> inputValues;
    vector<pair<int, int>> inputConnectedTo;
    pair<int, int> outputConnectedTo;
    bool outputValue;
    int inputSize;
public:
    ComponentLogic();
    explicit ComponentLogic(int input);
    virtual ~ComponentLogic() = default;
    int getInputSize() const;
    void setInputValue(unsigned index, bool value);
    void setInputValues(vector<bool> values);
    void setOutput(bool value);
    virtual bool evaluate() = 0;
    void connectInputTo(const pair<int, int> &value, int index);
    pair<int, int> getConnectedInputTo(int index) const;
    void connectOutputTo(const pair<int, int> &value);
    pair<int, int> getConnectedOutputTo() const;
};

#endif //COMPONENTLOGIC_H