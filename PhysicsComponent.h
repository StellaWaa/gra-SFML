#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include <iostream>
class PhysicsComponent
{
public:
	PhysicsComponent();
	void update_obj_pos(sf::RectangleShape& Obj, sf::Vector2f ObjSpeed);
private:
	const float Gravity;
	sf::Clock PhysClock;
};

