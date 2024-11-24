#include "Player.h"

Player::Player(sf::Vector2f start_pos,std::vector<Platform*> InPlatforms)
	:Hitbox(sf::Vector2f(50,70)),PlayerPhys(InPlatforms)
	,Hearts(3),spawn_pos(start_pos),DmgTimer()

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
	handle_player_input();
	PlayerPhys.update_obj_pos(Hitbox, Speed);
	if (Hitbox.getPosition().y > 1000) {
		Hearts = 1;
		take_dmg();
	}
	//std::cout << Hitbox.getPosition().y << "x: " << Hitbox.getPosition().y << std::endl;
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
		Speed->y = -30;
	}
	else {
		Speed->y = 0;
	}
}

sf::RectangleShape Player::get_hitbox() const
{
	return Hitbox;
}

void Player::take_dmg()
{
	bool CanTakeDmg = DmgTimer.getElapsedTime().asSeconds() > 3;
	if (Hearts >= 2 and CanTakeDmg) {
		Hearts--;
		DmgTimer.restart();
	}
	else if(CanTakeDmg){
		Hitbox.setPosition(spawn_pos);
		*Speed = sf::Vector2f(0, 0);
		Hearts = 3;
	}
}
