#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Land/Landscape.h"
#include <iostream>
#include <sstream>
#include "Stack.h"
#include <string>

using namespace sf;

int main()
{

    Font font;                      //шрифт
    font.loadFromFile("/Users/danilmorozov/Desktop/labsgit/TowerDefence/CyrilicOld.TTF");
    Text text("", font, 20);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);


    Landscape land (20, 20);

    //nt Landscape::pushEnemy(int x, int y, int hitPoints, int maxHP, float speed, int gold, float time)

    land.pushEnemy(0, 0, 150, 20, 0.06, 150, 2000);
    land.pushEnemy(0, 0, 150, 20, 0.06, 150, 2500);
    land.pushEnemy(0, 0, 200, 20, 0.06, 150, 5000);
    land.pushEnemy(0, 0, 250, 20, 0.06, 150, 6000);
    land.pushEnemy(0, 0, 100, 20, 0.09, 200, 7000);
    land.pushEnemy(0, 0, 300, 20, 0.06, 150, 8000);
    land.pushEnemy(0, 0, 300, 20, 0.06, 150, 8100);
    land.pushEnemy(0, 0, 300, 20, 0.06, 150, 8200);
    land.pushEnemy(0, 0, 300, 20, 0.06, 150, 8300);
    land.pushEnemy(0, 0, 300, 20, 0.06, 150, 8400);
    land.pushEnemy(0, 0, 300, 20, 0.06, 150, 8500);
    land.pushEnemy(0, 0, 1000, 100, 0.03, 500, 20000);

    RenderWindow window(VideoMode(1000, 1000), "Tower Defence");

    std::string str;

    Clock clock;
    float tiktime = 0;

    while (window.isOpen())
    {
        Event event;

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        tiktime += time;
        const int mtictime = 30;

        sf::Vector2i mousePoint = sf::Mouse::getPosition(window);

 //       std::cout << "mouse: (" << mousePoint.x / 50<< ", " << mousePoint.y / 50 << ")" << std::endl;

  //      std::cout << tiktime << std::endl;

        if (tiktime > mtictime) {
            land.updateEnemies(tiktime);
            land.fire(tiktime);
            tiktime = 0;
        }
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == Mouse::Left) {
                    std::cout << "mouse: (" << mousePoint.x / 50<< ", " << mousePoint.y / 50 << ")" << std::endl;
                    land.addTower(mousePoint.x / 50,  mousePoint.y / 50, 1, land.getRoad());
                }
                if (event.key.code == Mouse::Right) {
                    land.addTower(mousePoint.x / 50,  mousePoint.y / 50, 2, land.getRoad());
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                land.addTower(mousePoint.x / 50,  mousePoint.y / 50, 3, land.getRoad());
            }
        }


        window.clear(Color(34, 130, 45));
      //  window.clear(Color(10, 20, 100));
        int gold = land.getGold();
        std::stringstream out;
        out << gold;
        str = "Amount of GOLD: " + out.str();
        text.setString(str);
        text.setPosition(750, 0);
        window.draw(text);



        land.drawForest(&window);
        land.drawCastle(&window, &text);
        land.drawLair(&window);

        land.drawRoad(&window);
        land.drawTowers(&window);


        text.setFillColor(Color::Black);
        window.draw(text);
     //   std::cout << "!!!" << std::endl;
        land.drawEnemies(&window, &text);


        window.display();
    }

    return 0;
}

