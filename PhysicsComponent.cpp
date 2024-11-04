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
	if (curr_pos.y >= 500) {
		Obj.setPosition(sf::Vector2f(curr_pos.x, 500));
	}
	Obj.move((ObjSpeed * float(ElapsedTime.asMilliseconds() / 10)));
	

	std::cout << ElapsedTime.asMilliseconds() << '\n';
}
