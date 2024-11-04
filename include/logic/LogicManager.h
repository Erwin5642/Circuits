#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H

#include "ComponentLogic.h"
#include <vector>

using namespace std;

class LogicManager {
    std::vector<ComponentLogic *> components;
    bool mat[8][8]{};
    bool entrada[8]{};
    bool saida[8]{};

public:
    LogicManager();

    ~LogicManager();

    void insertComponent(ComponentLogic *component);

    void deleteComponent(int index);

    void deleteAllComponents();

    ComponentLogic &getComponent(int index) const;

    int getSize() const;

    void setInput(int index, bool input) const;

    void setInput(int index, const pair<int, int> &) const;

    void setInput(int index, const pair<char, int> &) const;

    void setInputs(unsigned index, const vector<bool> &inputs) const;

    void setOutput(int index, bool output) const;

    void setOutput(int index, const pair<int, int> &par) const;

    void setEntrada(int index);

    bool getEntrada(int index) const;

    bool getSaida(int index) const;

    bool getPointValue(pair<int, int> &par) const;

    bool getPointValue(pair<int, int> par) const;

    void update();

    void connectComponents(int outputIndex, int inputIndex, int inputPosition) const;

    void listComponents() const;
};

#endif //LOGICMANAGER_H
