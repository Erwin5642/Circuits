#include "LogicManager.h"
#include <iostream>
#include "and/ANDGateLogic.h"
#include "not/NOTGateLogic.h"
#include "or/ORGateLogic.h"
#include "wire/WIRELogic.h"

LogicManager::LogicManager() {
    components.clear();
    for(bool& i : entrada)
        i = false;
    for(auto & i : mat)
        for(bool & j : i)
            j = false;
    for(bool & i : saida)
        i = false;
}
LogicManager::~LogicManager() {
    components.clear();
}
void LogicManager::insertComponent(ComponentLogic *component) {
    components.push_back(component);
}
void LogicManager::deleteComponent(const int index) {
    components.erase(components.begin() + index);
}
void LogicManager::deleteAllComponents() {
    components.clear();
}
ComponentLogic& LogicManager::getComponent(const int index) const {
    return *components[index];
}
int LogicManager::getSize() const {
    return static_cast<int>(components.size());
}
void LogicManager::setInput(const int index, const bool input) const {
    components[index]->setInputValue(index, input);
}
void LogicManager::setInput(const int index, const pair<int, int> &par) const {
    if(par.first == 'e') {
        components[index]->setInputValue(index, pair<int, int>(-1, par.second));
    }
    if (par.second == 's') {
        components[index]->setInputValue(index, pair<int, int>(9, par.second));
    }
}
void LogicManager::setInput(const int index, const pair<char, int> &par) const {
    components[index]->setInputValue(index, par);
}
void LogicManager::setInputs(const unsigned index, const vector<bool>& inputs) const {
    components[index]->setInputValues(inputs);
}
void LogicManager::setOutput(const int index, const bool output) const {
    components[index]->setOutput(output);
}
void LogicManager::setOutput(const int index, const pair<int, int> &par) const {
    components[index]->setOutput(par);
}
void LogicManager::setEntrada(const int index) {
    entrada[index] = !entrada[index];
}
bool LogicManager::getEntrada(const int index) const {
    return entrada[index];
}
bool LogicManager::getSaida(const int index) const {
    return saida[index];
}
void LogicManager::update() {
    for(int i=0; i<components.size(); i++) {
        for(int j=0; j<components[i]->getUsedInputs(); j++) {
            components[i]->setInputValue(j, pair<int, int>(components[i]->getConnectedInputTo(j).first, components[i]->getConnectedInputTo(j).second));
        }
        components[i]->evaluate();
        if(components[i]->getConnectedOutputTo().first == 9) {
            saida[components[i]->getConnectedOutputTo().second] = components[i]->getOutput();
        }
        else {
            mat[components[i]->getConnectedOutputTo().first][components[i]->getConnectedOutputTo().second] = components[i]->getOutput();
        }
    }
}

void LogicManager::connectComponents(int outputIndex, int inputIndex, int inputPosition) const {
    if (outputIndex >= 0 && outputIndex < getSize() && inputIndex >= 0 && inputIndex < getSize()) {
        // Conectar a saída do componente de índice outputIndex à entrada do componente de índice inputIndex
        components[inputIndex]->connectInputTo(pair<int, int>(outputIndex, 0), inputPosition);
        // Conectar a saída do componente
        components[outputIndex]->connectOutputTo(pair<int, int>(inputIndex, inputPosition));
    }
}

void LogicManager::listComponents() const {
    std::cout << "Lista de Componentes:" << endl;
    for (size_t i = 0; i < components.size(); i++) {
        std::cout << "Componente " << i << ": ";
        if (components[i]->getType() == "AND") {
            std::cout << "AND Gate";
        } else if (components[i]->getType() == "OR") {
            std::cout << "OR Gate";
        } else if (components[i]->getType() == "NOT") {
            std::cout << "NOT Gate";
        } else if (components[i]->getType() == "WIRE") {
            std::cout << "WIRE";
        }
        std::cout << std::endl;
    }
}