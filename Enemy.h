#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class Enemy
{
public:
	Enemy(sf::Vector2f in_pos, sf::Vector2f in_size);
	sf::RectangleShape get_hitbox() const;
private:
	sf::RectangleShape Hitbox;
};

