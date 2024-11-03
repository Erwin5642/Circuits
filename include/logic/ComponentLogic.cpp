#include "ComponentLogic.h"

ComponentLogic::ComponentLogic() {
    for (int i = 0; i < 2; i++) {
        inputValues.push_back(false);
    }
    outputValue = false;
    inputSize = 2;
    for (int i = 0; i < 2; i++) {
        inputConnectedTo.emplace_back(-2, -2);
    }
    outputConnectedTo = pair<int, int>(-2, -2);
    usedInputs = 0;
    isOutputUsed = false;
}

ComponentLogic::ComponentLogic(const int input) {
    inputSize = input;
    for (int i = 0; i < input; i++) {
        inputValues.push_back(false);
    }
    outputValue = false;
    for (int i = 0; i < input; i++) {
        inputConnectedTo.emplace_back(-2, -2);
    }
    outputConnectedTo = pair<int, int>(-2, -2);
    usedInputs = 0;
    isOutputUsed = false;
}

int ComponentLogic::getInputSize() const {
    return static_cast<int>(inputValues.size());
}

int ComponentLogic::getUsedInputs() const {
    return usedInputs;
}

bool ComponentLogic::getIsOutputUsed() const {
    return isOutputUsed;
}

void ComponentLogic::setInputValue(const unsigned index, const bool value) {
    inputValues[index] = value;
}

void ComponentLogic::setInputValue(const unsigned index, const pair<int, int> &par) {
    if(usedInputs < inputSize) {
        if(par.first == 'e') {
            inputConnectedTo[index] = pair<int, int>(-1, par.second);
            usedInputs++;
        }
        else {
            inputConnectedTo[index] = par;
            usedInputs++;
        }
    }
}

void ComponentLogic::setInputValue(const unsigned index, const pair<char, int> &par) {
    if (par.first == 'e') {
        if(usedInputs < inputSize) {
            inputConnectedTo[index] = pair<int, int>(-1, par.second);
            usedInputs++;
        }
    }
}

void ComponentLogic::setInputValues(vector<bool> values) {
    for (int i = 0; i < inputSize; i++) {
        inputValues[i] = values[i];
    }
}

void ComponentLogic::setOutput(const bool value) {
    outputValue = value;
}

void ComponentLogic::setOutput(const pair<int, int> &par) {
    if(!isOutputUsed) {
        if(par.first == 's') {
            outputConnectedTo = pair<int, int>(9, par.second);
            isOutputUsed = true;
        }
        else {
            outputConnectedTo = par;
            isOutputUsed = true;
        }
    }
}

void ComponentLogic::setOutput(const pair<char, int> &par) {
    if (par.first == 's') {
        if(!isOutputUsed) {
            outputConnectedTo = pair<int, int>(9, par.second);;
            isOutputUsed = true;
        }
    }
}


bool ComponentLogic::getOutput() const {
    return outputValue;
}

void ComponentLogic::connectInputTo(const pair<int, int> &value, const int index) {
    if(usedInputs < inputSize) {
        inputConnectedTo[index] = value;
        usedInputs++;
    }
}

pair<int, int> ComponentLogic::getConnectedInputTo(int index) const {
    return inputConnectedTo[index];
}

void ComponentLogic::connectOutputTo(const pair<int, int> &value) {

        outputConnectedTo = value;
        isOutputUsed = true;
}

pair<int, int> ComponentLogic::getConnectedOutputTo() const {
    return outputConnectedTo;
}

void ComponentLogic::connectOutputTo(const pair<char, int> &value) {
    if (value.first == 's') {
        outputConnectedTo = pair<int, int>(9, value.second);
    }
}