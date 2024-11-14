#ifndef XORGATELOGIC_H
#define XORGATELOGIC_H

#include "../ComponentLogic.h"

class XORGateLogic final : public ComponentLogic {
public:
    bool evaluate() override;

    string getType() override;
};

#endif //XORGATELOGIC_H