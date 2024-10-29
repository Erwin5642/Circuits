//
// Created by Arthur on 29/10/2024.
//

#include "NOTGateLogic.h"

bool NOTGateLogic::evaluate() const {
    if(inputValues[0] == true) {
        return false;
    }
    return true;
}
