#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Drawable.h"
class Platform : public Drawable
{
public:
	Platform(sf::Vector2f in_pos, sf::Vector2f in_size);
	sf::RectangleShape get_hitbox() const;
	void set_position(sf::Vector2f);
	void move(sf::Vector2f);
private:
	sf::RectangleShape Hitbox;
};

