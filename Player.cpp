#include "Player.h"

Player::Player(sf::Vector2f start_pos,std::vector<Platform*> InPlatforms, std::vector<Enemy*> InEnemies)
	:Hitbox(sf::Vector2f(64,64)),PlayerPhys(InPlatforms, InEnemies)
	,Hearts(3),SpawnPos(start_pos),DmgTimer(),CanJump(true),MoveVec()
	,PlayerAnimation("AnimationSheet_Character.png",sf::Vector2f(32,32),sf::Vector2f(2,2))

{
	AniTxtrRects["Idle"] = { sf::IntRect(0, 0, 32,32),sf::IntRect(32, 0, 64,32) };
	PlayerAnimation.set_frames(AniTxtrRects["Idle"]);
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
	PlayerAnimation.set_pos(Hitbox.getPosition());
	PlayerAnimation.update();
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

void Player::move(sf::Vector2f MoveVec, bool MvdByCamera)
{
	Hitbox.move(MoveVec);
	if (MvdByCamera) {
		SpawnPos += MoveVec;
	}
}

void Player::draw(sf::RenderWindow& InWindow) const
{
	InWindow.draw(PlayerAnimation.get_sprite());
	
}

sf::Vector2f Player::get_MoveVec() const
{
	return MoveVec;
}
