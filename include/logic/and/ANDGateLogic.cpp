//
// Created by murak on 28/10/2024.
//

#include "ANDGateLogic.h"

bool ANDGateLogic::evaluate() const override {
    for(int i=0; i<inputSize; i++)
        if(inputValues[i] == false)
            return false;
    return true;
}