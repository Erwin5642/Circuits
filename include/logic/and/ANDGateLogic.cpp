#include "ANDGateLogic.h"

bool ANDGateLogic::evaluate() {
    for (int i = 0; i < inputSize; i++) {
        if (inputValues[i] == false) {
            outputValue = false;
            return false;
        }
    }
    outputValue = true;
    return true;
}

string ANDGateLogic::getType() {
    return "AND";
}
