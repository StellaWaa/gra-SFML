#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<cmath>
#include<random>
#include<iostream>
#include<vector>
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
int main() {

	const int WindowWidth = 800;
	const int WindowHeight = 600;
	sf::RenderWindow GameWindow(sf::VideoMode(WindowWidth, WindowHeight), "Game Window :D");
    GameWindow.setFramerateLimit(60);
    Platform* Platform_1= new Platform{ sf::Vector2f(200, 500),sf::Vector2f(1000,100) };
    Platform* Platform_2 = new Platform{ sf::Vector2f(500, 400),sf::Vector2f(200,100) };
    Platform* Platform_3 = new Platform{ sf::Vector2f(300, 200),sf::Vector2f(200,100) };
    std::vector<Platform*> Platforms{Platform_1, Platform_2, Platform_3};
    Enemy* Enemy_1 = new Enemy{ sf::Vector2f(250, 400),sf::Vector2f(30,100) };
    std::vector<Enemy*> Enemies{ Enemy_1};
    Player MainPlayer{ sf::Vector2f(300, 300), Platforms, Enemies};
    std::vector<Entity*> Entities {Platform_1,Platform_2, Platform_3, Enemy_1, &MainPlayer};


    while (GameWindow.isOpen())
    {
        sf::Event event;
        while (GameWindow.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                GameWindow.close();
            else {

            }
        }
        GameWindow.clear(sf::Color(100,100,100));
        MainPlayer.update();

        //camera
        for (auto item : Entities) {
            item->move(sf::Vector2f(MainPlayer.get_MoveVec().x,0), true);
        }
        //drawing entities
        for (auto item : Entities) {
            item->draw(GameWindow);
        }


        int HeartsNum = MainPlayer.get_hearts();
        if (HeartsNum > 0) {
            sf::RectangleShape Heart(sf::Vector2f(20,20));
            Heart.setFillColor(sf::Color::Red);
            for (int i = 0; i < HeartsNum; i++){
                Heart.setPosition(10 + i*30, 20);
                GameWindow.draw(Heart);
            }
        }
        GameWindow.display();

    }
    delete Platform_1;
    delete Platform_2;


    return 0;
}