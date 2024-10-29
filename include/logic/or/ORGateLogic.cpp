//
// Created by Arthur on 29/10/2024.
//

#include "ORGateLogic.h"

bool ORGateLogic::evaluate() const {
    for(int i=0; i<inputSize; i++)
        if(inputValues[i] == true)
            return true;
    return false;
}