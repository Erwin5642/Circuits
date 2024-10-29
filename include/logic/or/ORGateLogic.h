//
// Created by Arthur on 29/10/2024.
//

#ifndef ORGATELOGIC_H
#define ORGATELOGIC_H

#include "../ComponentLogic.h"

class ORGateLogic final : public ComponentLogic {
public:
    bool evaluate() const override;
};

#endif //ORGATELOGIC_H
