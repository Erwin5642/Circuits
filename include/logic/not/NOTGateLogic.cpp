#include "NOTGateLogic.h"

bool NOTGateLogic::evaluate() {
    if (inputValues[0] == true) {
        outputValue = false;
        return false;
    }
    outputValue = true;
    return true;
}

string NOTGateLogic::getType() {
    return "NOT";
}
