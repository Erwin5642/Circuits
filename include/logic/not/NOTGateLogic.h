#ifndef NOTGATELOGIC_H
#define NOTGATELOGIC_H

#include "../ComponentLogic.h"

class NOTGateLogic final : public ComponentLogic {
public:
    NOTGateLogic() : ComponentLogic(1) {};
    bool evaluate() override;
    string getType() override;
};

#endif //NOTGATELOGIC_H