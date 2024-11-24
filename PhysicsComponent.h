#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include "Platform.h"
class PhysicsComponent
{
public:
	PhysicsComponent(std::vector<Platform*> InPlatforms);
	void update_obj_pos(sf::RectangleShape& Obj, sf::Vector2f* ObjSpeed);
private:
	std::vector<Platform*> Platforms;
	const float Gravity;
	sf::Clock PhysClock;
};

