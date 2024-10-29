//
// Created by jvgam on 28/10/2024.
//

#include "ComponentLogic.h"

ComponentLogic::ComponentLogic() {
    for(int i = 0; i<2; i++)  {
        inputValues.push_back(false);
    }
    outputValue = false;
    inputSize = 2;
}
ComponentLogic::ComponentLogic(const int input) {
    inputSize = input;
    for(int i = 0; i<input; i++)  {
        inputValues.push_back(false);
    }
    outputValue = false;
}
int ComponentLogic::getInputSize() const {
    return static_cast<int>(inputValues.size());
}
void ComponentLogic::setInputValue(const unsigned index, const bool value) {
    inputValues[index] = value;
}
void ComponentLogic::setInputValues(vector<bool> values) {
    for(int i = 0; i<inputSize; i++) {
        inputValues[i] = values[i];
    }
}
void ComponentLogic::setOutput(const bool value) {
    outputValue = value;
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