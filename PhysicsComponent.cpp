#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(std::vector<Platform*> InPlatforms, std::vector<Enemy*> InEnemies)
	:Gravity(0.08),PhysClock(),Platforms(InPlatforms),Enemies(InEnemies)
{
}

Collision PhysicsComponent::update_obj_pos(sf::RectangleShape& Obj, sf::Vector2f* ObjSpeed)
{
	sf::Time ElapsedTime = PhysClock.restart();
	sf::Vector2f ObjCurPos = Obj.getGlobalBounds().getPosition();
	

	int y_change = (Gravity * pow(ElapsedTime.asMilliseconds(), 2)) / 2;
	bool IsColliding = false;
	bool IsEnemy = false;
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
			
		}
	}
	for (Enemy* CurEnemy : Enemies) {
		sf::RectangleShape CurEnemyHitbox = CurEnemy->get_hitbox();

		ObjBounds = Obj.getGlobalBounds();
		if (ObjBounds.intersects(CurEnemyHitbox.getGlobalBounds())) {
			IsEnemy = true;
		}
	}

	// yyyyyyyyyyyyyyy
	Obj.move(sf::Vector2f(0, MoveVec.y));
	for (Platform* CurPlatform : Platforms) {
		sf::RectangleShape CurPlatHitbox = CurPlatform->get_hitbox();
		sf::FloatRect CurPlatBounds = CurPlatHitbox.getGlobalBounds();
		ObjBounds = Obj.getGlobalBounds();
		if (ObjBounds.intersects(CurPlatBounds)) {
			if (MoveVec.y > 0) {
				Obj.setPosition(
					sf::Vector2f(
						ObjBounds.getPosition().x,
					CurPlatBounds.getPosition().y - Obj.getSize().y
					)
				);
				IsColliding = true;
				ObjSpeed->y = 0;
			}
			else if (MoveVec.y < 0) {
				Obj.setPosition(
					sf::Vector2f(
						ObjBounds.getPosition().x,
						CurPlatBounds.getPosition().y + CurPlatBounds.getSize().y
					)
				);
			}
			
			
			
		}
	if(ObjSpeed->y < 0){
		ObjSpeed->y += y_change;
		if (IsColliding = true)
			IsColliding = false;
	}
	}
	return Collision(IsColliding, IsEnemy);
}
