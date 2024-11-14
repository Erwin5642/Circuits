#include "FileManager.h"

std::string FileManager::toLowerCase(const std::string &str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

void FileManager::loadComponents(LogicManager &logicManager) {
    std::string filename;
    cout << "Digite o nome do arquivo a ser carregado:";
    cin >> filename;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "wire") {
            std::string input, output;
            iss >> input >> output;

            auto *wire = new WIRELogic();
            if (input[0] == 'e') {
                int inputIndex = std::stoi(input.substr(1, 1));
                wire->connectInputTo(pair<int, int>(-1, inputIndex), 0); // Entrada 'e'
            } else {
                int in1 = std::stoi(input.substr(0, 1));
                int in2 = std::stoi(input.substr(1, 1));
                wire->connectInputTo(pair<int, int>(in1, in2), 0); // Conexão direta
            }

            if (output[0] == 's') {
                int outputIndex = std::stoi(output.substr(1, 1));
                wire->connectOutputTo(pair<int, int>(9, outputIndex)); // Saída 's'
            } else {
                int out1 = std::stoi(output.substr(0, 1));
                int out2 = std::stoi(output.substr(1, 1));
                wire->connectOutputTo(pair<int, int>(out1, out2)); // Conexão direta
            }
            logicManager.insertComponent(wire);
        } else if (type == "not") {
            std::string input, output;
            iss >> input >> output;

            auto *notGate = new NOTGateLogic();
            if (input[0] == 'e') {
                int inputIndex = std::stoi(input.substr(1, 1));
                notGate->connectInputTo(pair<int, int>(-1, inputIndex), 0); // Entrada 'e'
            } else {
                int in1 = std::stoi(input.substr(0, 1));
                int in2 = std::stoi(input.substr(1, 1));
                notGate->connectInputTo(pair<int, int>(in1, in2), 0); // Conexão direta
            }

            if (output[0] == 's') {
                int outputIndex = std::stoi(output.substr(1, 1));
                notGate->connectOutputTo(pair<int, int>(9, outputIndex)); // Saída 's'
            } else {
                int out1 = std::stoi(output.substr(0, 1));
                int out2 = std::stoi(output.substr(1, 1));
                notGate->connectOutputTo(pair<int, int>(out1, out2)); // Conexão direta
            }
            logicManager.insertComponent(notGate);
        } else if (type == "and" || type == "or" || "xor") {
            string input1, input2;
            std::string output;
            iss >> input1 >> input2 >> output;

            ComponentLogic *gate = nullptr;
            if (type == "and") {
                gate = new ANDGateLogic();
            } else if (type == "or") {
                gate = new ORGateLogic();
            }
            else if (type == "xor") {
                gate = new XORGateLogic();
            }

            // Configuração das entradas
            if (input1[0] == 'e') {
                int inputIndex = std::stoi(input1.substr(1, 1));
                gate->connectInputTo(pair<int, int>(-1, inputIndex), 0); // Entrada 'e'
            } else {
                int in1 = std::stoi(input1.substr(0, 1));
                int in2 = std::stoi(input1.substr(1, 1));
                gate->connectInputTo(pair<int, int>(in1, in2), 0); // Conexão direta
            }

            if (input2[0] == 'e') {
                int outputIndex = std::stoi(input2.substr(1, 1));
                gate->connectInputTo(pair<int, int>(-1, outputIndex), 1); // Entrada 'e'
            } else {
                int in1 = std::stoi(input2.substr(0, 1));
                int in2 = std::stoi(input2.substr(1, 1));
                gate->connectInputTo(pair<int, int>(in1, in2), 1); // Conexão direta
            }

            // Configuração da saída
            if (output[0] == 's') {
                int outputIndex = std::stoi(output.substr(1, 1));
                gate->connectOutputTo(pair<int, int>(9, outputIndex)); // Saída 's'
            } else {
                int out1 = std::stoi(output.substr(0, 1));
                int out2 = std::stoi(output.substr(1, 1));
                gate->connectOutputTo(pair<int, int>(out1, out2)); // Conexão direta
            }
            logicManager.insertComponent(gate);
        } else {
            std::cerr << "Tipo desconhecido: " << type << std::endl;
        }
    }
    file.close();
}

void FileManager::saveComponents(LogicManager &logicManager) {
    std::string filename;
    cout << "Digite o nome do arquivo a ser salvo:";
    cin >> filename;
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return;
    }
    for (int i = 0; i < logicManager.getSize(); i++) {
        if (logicManager.getComponent(i).getType() == "WIRE" && logicManager.getComponent(i).getConnectedInputTo(0) ==
            pair<int, int>(-2, -2)) {
            continue;
        } else {
            string line, aux;
            line += toLowerCase(logicManager.getComponent(i).getType());
            for (int j = 0; j < logicManager.getComponent(i).getInputSize(); j++) {
                string aux2;
                aux2 += ' ';
                pair<int, int> pos2 = logicManager.getComponent(i).getConnectedInputTo(j);
                if (pos2.first == -1) {
                    aux2 += 'e';
                } else {
                    aux2 += to_string(pos2.first);
                }
                aux2 += to_string(pos2.second);
                line += aux2;
            }
            pair<int, int> pos = logicManager.getComponent(i).getConnectedOutputTo();
            aux += ' ';
            if (pos.first == 9) {
                aux += 's';
            } else {
                aux += to_string(pos.first);
            }
            aux += to_string(pos.second);
            line += aux;
            cout << line << endl;
            file << line << endl;
        }
    }
    file.close();
}
