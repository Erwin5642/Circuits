//
// Created by Arthur on 29/10/2024.
//

#include "NOTGateLogic.h"

bool NOTGateLogic::evaluate() {
    if(inputValues[0] == true) {
        outputValue = false;
        return false;
    }
    outputValue = true;
    return true;
}
