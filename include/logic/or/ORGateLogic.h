#ifndef ORGATELOGIC_H
#define ORGATELOGIC_H

#include "../ComponentLogic.h"

class ORGateLogic final : public ComponentLogic {
public:
    bool evaluate() override;
    string getType() override;
};

#endif //ORGATELOGIC_H