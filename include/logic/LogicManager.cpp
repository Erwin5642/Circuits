#include "LogicManager.h"
#include <iostream>

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
        for(int j=0; j<components[i]->getInputSize(); j++) {
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
// void LogicManager::update() {
//     for (int i = 0; i < components.size(); i++) {
//         for (int j = 0; j < components[i]->getInputSize(); j++) {
//             auto connectedPos = components[i]->getConnectedInputTo(j);
//             int connectedComponentIndex = connectedPos.first;
//             int connectedOutputIndex = connectedPos.second;
//
//             if (connectedComponentIndex == -1) {
//                 components[i]->setInputValue(j, entrada[connectedOutputIndex]);
//             }
//             else if (connectedComponentIndex == 9) {
//                 components[i]->setInputValue(j, saida[connectedOutputIndex]);
//             }
//             else if (connectedComponentIndex >= 0 && connectedComponentIndex < components.size()) {
//                 bool connectedOutputValue = components[connectedComponentIndex]->getOutput();
//                 components[i]->setInputValue(j, connectedOutputValue);
//             }
//         }
//
//         components[i]->evaluate();
//
//         auto outputConnection = components[i]->getConnectedOutputTo();
//         if (outputConnection.first == 9) {
//             saida[outputConnection.second] = components[i]->getOutput();
//         } else {
//             mat[outputConnection.first][outputConnection.second] = components[i]->getOutput();
//         }
//     }
// }

void LogicManager::printaEntrada() const {
    for(int i=0; i<8; i++) {
        cout << entrada[i] << ' ';
    }
    cout << endl;
}
void LogicManager::printaMat() const {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
void LogicManager::printaSaida() const {
    for(int i=0; i<8; i++) {
        cout << saida[i] << ' ';
    }
    cout << endl;
}
void LogicManager::printa() const {
    LogicManager::printaEntrada();
    cout << endl;
    LogicManager::printaMat();
    cout << endl;
    LogicManager::printaSaida();
    cout << endl;
}
void LogicManager::connectComponents(int outputIndex, int inputIndex, int inputPosition) const {
    if (outputIndex >= 0 && outputIndex < getSize() && inputIndex >= 0 && inputIndex < getSize()) {
        // Conectar a saída do componente de índice outputIndex à entrada do componente de índice inputIndex
        components[inputIndex]->connectInputTo(pair<int, int>(outputIndex, 0), inputPosition);
        // Conectar a saída do componente
        components[outputIndex]->connectOutputTo(pair<int, int>(inputIndex, inputPosition));
    }
}