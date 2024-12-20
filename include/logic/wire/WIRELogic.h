//
// Created by Arthur on 29/10/2024.
//

#ifndef WIRELOGIC_H
#define WIRELOGIC_H

#include "../ComponentLogic.h"

class WIRELogic final :  public ComponentLogic {
public:
    WIRELogic() : ComponentLogic(1) {};
    bool evaluate() override;
    string getType() override;
};

#endif //WIRELOGIC_H