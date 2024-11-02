#include "SFML/Window.hpp"
#include "../include/graphics/DrawableManager.h"
#include "../include/UIManager.h"
#include "../include/logic/LogicManager.h"

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Circuits");
    DrawableManager drawable_manager;
    LogicManager logic_manager;
    UIManager ui_manager(window, drawable_manager, logic_manager);

    while (window.isOpen()) {
        window.clear();
        ui_manager.processEvent();
        drawable_manager.updateDrawables();
        drawable_manager.draw(window);
        window.display();
    }

    return 0;
}
