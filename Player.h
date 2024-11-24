#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "PhysicsComponent.h"
#include "Platform.h"
#include <vector>
class Player
{
public:
	Player(sf::Vector2f start_pos, std::vector<Platform*> InPlatforms);
	~Player();
	void update();
	sf::RectangleShape get_hitbox() const;
	void take_dmg();
private:
	void handle_player_input();
	sf::Vector2f spawn_pos;
	sf::RectangleShape Hitbox;
	sf::Vector2f* Speed;
	PhysicsComponent PlayerPhys;
	sf::Clock DmgTimer;
	int Hearts;
};

