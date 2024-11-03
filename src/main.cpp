#include "../include/App.h"
//#include "../include/graphics/DrawableManager.h"
//#include "../include/graphics/and/ANDGateDrawable.h"
//#include "../include/graphics/not/NOTGateDrawable.h"
//#include "../include/graphics/or/ORGateDrawable.h"
#include "../include/logic/LogicManager.h"
#include "../include/logic/and/ANDGateLogic.h"
#include "../include/logic/or/ORGateLogic.h"
#include "../include/logic/wire/WIRELogic.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
    // sf::RenderWindow window(sf::VideoMode(800, 800), "Drawables Manager Test");
    // // DrawableManager d_Manager;
    // // ANDGateDrawable ANDGate;
    // // ORGateDrawable ORGate;
    // // NOTGateDrawable NOTGate;
    //
    // sf::Font font;
    // if (!font.loadFromFile("C:/Windows/Fonts/comic.ttf")) {
    //     std::cerr << "Erro ao carregar a fonte!" << std::endl;
    //     return -1;
    // }
    //
    // sf::Text text;
    // text.setFont(font);
    // text.setString("Hello, SFML!");
    // text.setCharacterSize(24);
    // text.setFillColor(sf::Color::White);
    //
    // sf::CircleShape bolinha(10);
    // bolinha.setFillColor(sf::Color::Green);
    // sf::Vector2i mousePosition;
    //
    // while (window.isOpen()) {
    //     sf::Event event{};
    //     while (window.pollEvent(event)) {
    //         switch (event.type) {
    //             case sf::Event::Closed:
    //                 window.close();
    //             break;
    //             case sf::Event::KeyPressed:
    //                 switch (event.key.code) {
    //                     case sf::Keyboard::A:
    //                         mousePosition = sf::Mouse::getPosition(window);
    //                         bolinha.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
    //                         window.draw(bolinha);
    //                         //drawableManager.addDrawable(ANDGate, 429, 429, 15, 10, 2);
    //                     break;
    //                     case sf::Keyboard::S:
    //                         //window.clear(sf::Color::Black);
    //                     break;
    //                     case sf::Keyboard::O:
    //                         //drawableManager.addDrawable(&ORGate, 53, 120, 15, 10, 2);
    //                     break;
    //                     case sf::Keyboard::N:
    //                         //drawableManager.addDrawable(&NOTGate, 530, 225, 15, 10, 2);
    //                     break;
    //                     case sf::Keyboard::Escape:
    //                         //drawableManager.removeAllDrawables();
    //                     break;
    //                     default:
    //                         break;
    //                 }
    //             default:
    //                 break;
    //         }
    //         //drawableManager.draw(window);
    //         window.display();
    //     }
    // }
    // LogicManager logicManager;
    // ORGateLogic orGateLogic;
    // ANDGateLogic andGateLogic;
    // NOTGateLogic notGateLogic;
    // WIRELogic wireLogic;

    App app;
    app.leArq();
    app.printa();
    cout << "Quantidade de componentes: " << app.getSize() << endl;
    app.listComps();
    app.gravaArq();
    return 0;
}
