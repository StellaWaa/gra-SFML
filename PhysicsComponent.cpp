#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(std::vector<Platform*> InPlatforms)
	:Gravity(0.1),PhysClock(),Platforms(InPlatforms)
{
}

void PhysicsComponent::update_obj_pos(sf::RectangleShape& Obj, sf::Vector2f* ObjSpeed)
{
	sf::Time ElapsedTime = PhysClock.restart();
	sf::Vector2f ObjCurPos = Obj.getGlobalBounds().getPosition();
	

	int y_change = (Gravity * pow(ElapsedTime.asMilliseconds(), 2)) / 2;
	
	int barrier = 300;
	sf::FloatRect ObjBounds = Obj.getGlobalBounds();
	sf::Vector2f MoveVec{ (*ObjSpeed * float(ElapsedTime.asMilliseconds() / 10)) };
	MoveVec.y += y_change;

	// xxxxxxxxxxxxxxxxx
	Obj.move(sf::Vector2f(MoveVec.x, 0));
	for (Platform* CurPlatform : Platforms) {
		sf::RectangleShape CurPlatHitbox = CurPlatform->get_hitbox();
		sf::FloatRect CurPlatBounds = CurPlatHitbox.getGlobalBounds();
		ObjBounds = Obj.getGlobalBounds();
		if (ObjBounds.intersects(CurPlatBounds)) {
			if (MoveVec.x > 0) {
				Obj.setPosition(sf::Vector2f(CurPlatBounds.getPosition().x - Obj.getSize().x,ObjBounds.getPosition().y));
			}
			else if (MoveVec.x < 0) {
				Obj.setPosition(sf::Vector2f(CurPlatBounds.getPosition().x + CurPlatBounds.getSize().x, ObjBounds.getPosition().y));
			}
			//Obj.setPosition(sf::Vector2f(ObjBounds.getPosition().x, CurPlatBounds.getPosition().y - Obj.getSize().y));
		}
	}

	// yyyyyyyyyyyyyyy
	Obj.move(sf::Vector2f(0, MoveVec.y));
	for (Platform* CurPlatform : Platforms) {
		sf::RectangleShape CurPlatHitbox = CurPlatform->get_hitbox();
		sf::FloatRect CurPlatBounds = CurPlatHitbox.getGlobalBounds();
		ObjBounds = Obj.getGlobalBounds();
		if (ObjBounds.intersects(CurPlatBounds)) {
			Obj.setPosition(sf::Vector2f(ObjBounds.getPosition().x, CurPlatBounds.getPosition().y - Obj.getSize().y));
		}
	}
}
