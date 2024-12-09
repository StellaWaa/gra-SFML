#include "Player.h"

Player::Player(sf::Vector2f start_pos,std::vector<Platform*> InPlatforms, std::vector<Enemy*> InEnemies)
	:Hitbox(sf::Vector2f(50,70)),PlayerPhys(InPlatforms, InEnemies)
	,Hearts(3),SpawnPos(start_pos),DmgTimer(),CanJump(true),MoveVec()

{
	Speed = new sf::Vector2f(0, 0);
	Hitbox.setPosition(start_pos);
	Hitbox.setFillColor(sf::Color::Magenta);
}

Player::~Player()
{
	delete Speed;
}

void Player::update()
{
	MoveVec = Hitbox.getPosition();
	Collision CurCollision = PlayerPhys.update_obj_pos(Hitbox, Speed);
	if (CurCollision.IsColliding == false)
		CanJump = false;
	else
		CanJump = true;
	if (CurCollision.IsEnemy) {
		take_dmg();
	}
	handle_player_input();

	if (Hitbox.getPosition().y > 1000) {
		Hearts = 1;
		take_dmg();
	}
	MoveVec -= Hitbox.getPosition();
}

void Player::handle_player_input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)){
		Speed->x = 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
		Speed->x = -10;
	}
	else {
		Speed->x = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W) and CanJump) {
		Speed->y = -100;
	}
	else {
		//Speed->y = 0;
	}
}

sf::RectangleShape Player::get_hitbox() const
{
	return Hitbox;
}

void Player::take_dmg()
{
	bool CanTakeDmg = DmgTimer.getElapsedTime().asSeconds() > 1;
	if (Hearts >= 2 and CanTakeDmg) {
		Hearts--;
		DmgTimer.restart();
	}
	else if(CanTakeDmg){
		Hitbox.setPosition(SpawnPos);
		*Speed = sf::Vector2f(0, 0);
		Hearts = 3;
	}
}

int Player::get_hearts()
{
	return Hearts;
}

void Player::set_position(sf::Vector2f InPos)
{
	Hitbox.setPosition(InPos);
}

void Player::move(sf::Vector2f MoveVec)
{
	Hitbox.move(MoveVec);
}

sf::Vector2f Player::get_MoveVec() const
{
	return MoveVec;
}
