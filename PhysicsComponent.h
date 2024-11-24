#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include <iostream>
#include "Platform.h"
class PhysicsComponent
{
public:
	PhysicsComponent();
	void update_obj_pos(sf::RectangleShape& Obj, sf::Vector2f ObjSpeed);
private:
	const float Gravity;
	sf::Clock PhysClock;
};

