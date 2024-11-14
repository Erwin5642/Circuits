#include "XORGateLogic.h"

bool XORGateLogic::evaluate() {
    if((inputValues[0] && !inputValues[1]) || (!inputValues[0] && inputValues[1])) {
        outputValue = true;
        return true;
    }
    outputValue = false;
    return false;
}

string XORGateLogic::getType() {
    return "XOR";
}
