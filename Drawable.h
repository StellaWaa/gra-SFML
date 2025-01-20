#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class Entity
{
public:
	virtual void set_position(sf::Vector2f) = 0;
	virtual void move(sf::Vector2f, bool MvdByCamera) = 0;
	virtual void draw(sf::RenderWindow&) const = 0;

};

