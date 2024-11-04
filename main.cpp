#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<cmath>
#include<random>
#include<iostream>
#include "Player.h"
int main() {
	const int WindowWidth = 800;
	const int WindowHeight = 600;
	sf::RenderWindow GameWindow(sf::VideoMode(WindowWidth, WindowHeight), "Game Window :D");
    GameWindow.setFramerateLimit(60);
    Player MainPlayer{ sf::Vector2f(300, 300) };
    sf::RectangleShape Testrect{ sf::Vector2f(20,20) };


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
        GameWindow.clear(sf::Color());
        MainPlayer.update();
        GameWindow.draw(MainPlayer.get_hitbox());
        GameWindow.display();

    }
    


    return 0;
}