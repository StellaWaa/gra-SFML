#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent()
	:Gravity(0.1),PhysClock()
{
}

void PhysicsComponent::update_obj_pos(sf::RectangleShape& Obj, sf::Vector2f ObjSpeed)
{
	sf::Time ElapsedTime = PhysClock.restart();
	sf::Vector2f curr_pos = Obj.getPosition();
	int y_change = (Gravity * pow(ElapsedTime.asMilliseconds(), 2)) / 2;
	Obj.move(sf::Vector2f(0, y_change));
	int barrier = 300;
	if (curr_pos.y >= barrier) {
		Obj.setPosition(sf::Vector2f(curr_pos.x, barrier));
	}
	Obj.move((ObjSpeed * float(ElapsedTime.asMilliseconds() / 10)));
	

	//std::cout << ElapsedTime.asMilliseconds() << '\n';
}
