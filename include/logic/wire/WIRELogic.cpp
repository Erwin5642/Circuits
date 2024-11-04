#include "WIRELogic.h"

bool WIRELogic::evaluate() {
    outputValue = inputValues[0];
    return inputValues[0];
}

string WIRELogic::getType() {
    return "WIRE";
}
