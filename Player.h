#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "PhysicsComponent.h"
class Player
{
public:
	Player(sf::Vector2f start_pos);
	void update();
	sf::RectangleShape get_hitbox() const;
private:
	void handle_player_input();
	sf::RectangleShape Hitbox;
	sf::Vector2f Speed;
	PhysicsComponent PlayerPhys;
};

