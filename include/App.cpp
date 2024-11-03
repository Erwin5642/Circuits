#include "App.h"

App::App() {
    fileManager = new FileManager();
}

App::~App() {
    delete fileManager;
}

void App::run() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Circuits");
    UIManager uiManager(window, drawableManager, logicManager);

    while (window.isOpen()) {
        window.clear();
        uiManager.processEvent();
        drawableManager.updateDrawables();
        logicManager.update();
        drawableManager.draw(window);
        window.display();
    }
}

void App::insert(const string &c_name) {
    if (c_name == "AND")
        logicManager.insertComponent(new ANDGateLogic);
    if (c_name == "OR")
        logicManager.insertComponent(new ORGateLogic);
    if (c_name == "NOT")
        logicManager.insertComponent(new NOTGateLogic);
    if (c_name == "WIRE")
        logicManager.insertComponent(new WIRELogic);
}

void App::leArq() {
    if (!fileManager) {
        std::cerr << "Erro: FileManager não inicializado." << std::endl;
        return;
    }
    std::string arq_name;
    std::cout << "Digite o nome do arquivo: ";
    std::cin >> arq_name;
    fileManager->loadComponents(arq_name, logicManager);
}

void App::gravaArq() {
    if (!fileManager) {
        std::cerr << "Erro: FileManager não inicializado." << std::endl;
        return;
    }
    std::string arq_name;
    std::cout << "Digite o nome do arquivo: ";
    std::cin >> arq_name;
    fileManager->saveComponents(arq_name, logicManager);
}

void App::listComps() {
    logicManager.listComponents();
}

int App::getSize() {
    return logicManager.getSize();
}
