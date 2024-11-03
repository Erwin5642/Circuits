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
    vector<pair<int, int>> inputConnectedTo;
    vector<bool> inputValues;
    pair<int, int> outputConnectedTo;
    bool outputValue;
    int inputSize;
public:
    ComponentLogic();
    explicit ComponentLogic(int input);
    virtual ~ComponentLogic() = default;

    int getInputSize() const;
    void setInputValue(unsigned index, bool value); // NAO USANDO
    void setInputValue(unsigned index, const pair<int, int> &par);
    void setInputValue(unsigned index, const pair<char, int> &par);
    void setInputValues(vector<bool> values);

    void setOutput(bool value); // NAO USANDO
    void setOutput(const pair<int, int> &par);
    void setOutput(const pair<char, int> &par);
    bool getOutput() const;

    virtual bool evaluate() = 0;

    void connectInputTo(const pair<int, int> &value, int index);
    pair<int, int> getConnectedInputTo(int index) const;

    void connectOutputTo(const pair<int, int> &value);
    pair<int, int> getConnectedOutputTo() const;

    void connectOutputTo(const pair<char, int> &value);
    virtual string getType() = 0;
};

#endif //COMPONENTLOGIC_H