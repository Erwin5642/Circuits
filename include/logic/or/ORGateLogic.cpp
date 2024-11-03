//
// Created by Arthur on 29/10/2024.
//

#include "ORGateLogic.h"

bool ORGateLogic::evaluate() {
    for(int i=0; i<inputSize; i++) {
        if(inputValues[i] == true) {
            outputValue = true;
            return true;
        }
    }
    outputValue = false;
    return false;
}
string ORGateLogic::getType() {
    return "OR";
}
