#include "Player.h"

Player::Player(sf::Vector2f start_pos)
	:Hitbox(sf::Vector2f(50,100)), Speed(sf::Vector2f(0,0)), PlayerPhys()
{
	Hitbox.setPosition(start_pos);
}

void Player::update()
{
	handle_player_input();
	PlayerPhys.update_obj_pos(Hitbox, Speed);
}

void Player::handle_player_input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)){
		Speed.x = 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
		Speed.x = -10;
	}
	else {
		Speed.x = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
		Speed.y = -30;
	}
	else {
		Speed.y = 0;
	}
}

sf::RectangleShape Player::get_hitbox() const
{
	return Hitbox;
}
