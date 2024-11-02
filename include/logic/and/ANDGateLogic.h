//
// Created by murak on 28/10/2024.
//

#ifndef ANDGATELOGIC_H
#define ANDGATELOGIC_H

#include "../ComponentLogic.h"

class ANDGateLogic final : public ComponentLogic {
public:
    bool evaluate() override;
    string getType() override;
};

#endif //ANDGATELOGIC_H