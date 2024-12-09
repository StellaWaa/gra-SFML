#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include "Platform.h"
#include "Enemy.h"
struct Collision {
	bool IsColliding;
	bool IsEnemy;
	Collision(bool InIsColliding, bool InIsEnemy) {
		IsColliding = InIsColliding;
		IsEnemy = InIsEnemy;
	}
};

class PhysicsComponent
{
public:
	PhysicsComponent(std::vector<Platform*> InPlatforms, std::vector<Enemy*> InEnemies);
	Collision update_obj_pos(sf::RectangleShape& Obj, sf::Vector2f* ObjSpeed);
private:
	std::vector<Platform*> Platforms;
	std::vector<Enemy*> Enemies;
	const float Gravity;
	sf::Clock PhysClock;
};

