#include "ComponentLogic.h"

ComponentLogic::ComponentLogic() {
    for(int i = 0; i<2; i++)  {
        inputValues.push_back(false);
    }
    outputValue = false;
    inputSize = 2;
    for(int i = 0; i<2; i++)  {
        inputConnectedTo.emplace_back(0, 0);
    }
    outputConnectedTo = pair<int, int>(0, 0);
}
ComponentLogic::ComponentLogic(const int input) {
    inputSize = input;
    for(int i = 0; i<input; i++)  {
        inputValues.push_back(false);
    }
    outputValue = false;
    for(int i = 0; i<input; i++)  {
        inputConnectedTo.emplace_back(0, 0);
    }
    outputConnectedTo = pair<int, int>(0, 0);
}
int ComponentLogic::getInputSize() const {
    return static_cast<int>(inputValues.size());
}
void ComponentLogic::setInputValue(const unsigned index, const bool value) {
    inputValues[index] = value;
}
void ComponentLogic::setInputValue(const unsigned index, const pair<int, int> &par) {
    inputConnectedTo[index] = par;
}
void ComponentLogic::setInputValue(const unsigned index, const pair<char, int> &par) {
    if(par.first == 'e')
        inputConnectedTo[index] = pair<int, int>(-1, par.second);
}
void ComponentLogic::setInputValues(vector<bool> values) {
    for(int i = 0; i<inputSize; i++) {
        inputValues[i] = values[i];
    }
}
void ComponentLogic::setOutput(const bool value) {
    outputValue = value;
}
void ComponentLogic::setOutput(const pair<int, int> &par) {
    outputConnectedTo = par;
}
void ComponentLogic::setOutput(const pair<char, int> &par) {
    if(par.first == 's')
        outputConnectedTo = pair<int, int>(9, par.second);;
}
bool ComponentLogic::getOutput() const {
    return outputValue;
}

void ComponentLogic::connectInputTo(const pair<int, int> &value, const int index) {
    inputConnectedTo[index] = value;
}
pair<int, int> ComponentLogic::getConnectedInputTo(int index) const {
    return inputConnectedTo[index];
}
void ComponentLogic::connectOutputTo(const pair<int, int> &value) {
    outputConnectedTo = value;
}
pair<int, int> ComponentLogic::getConnectedOutputTo() const {
    return outputConnectedTo;
}
void ComponentLogic::connectOutputTo(const pair<char, int> &value) {
    if(value.first == 's')
        outputConnectedTo = pair<int, int>(9, value.second);
}