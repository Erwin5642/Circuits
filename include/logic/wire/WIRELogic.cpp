//
// Created by Arthur on 29/10/2024.
//

#include "WIRELogic.h"

bool WIRELogic::evaluate() {
    outputValue = inputValues[0];
    return inputValues[0];
}
string WIRELogic::getType() {
    return "WIRE";
}
