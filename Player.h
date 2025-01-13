#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "PhysicsComponent.h"
#include "Platform.h"
#include "Drawable.h"
#include <vector>
#include <string>
#include <map>
#include "Animation.h"
class Player : public Entity
{
public:
	Player(sf::Vector2f start_pos, std::vector<Platform*> InPlatforms, std::vector<Enemy*> InEnemies);
	~Player();
	void update();
	sf::RectangleShape get_hitbox() const;
	void take_dmg();
	int get_hearts();
	void set_position(sf::Vector2f);
	void move(sf::Vector2f, bool MvdByCamera);
	void draw(sf::RenderWindow&) const;
	sf::Vector2f get_MoveVec() const;

private:
	void handle_player_input();

	bool CanJump;
	
	Animation PlayerAnimation;
	std::map<std::string, std::vector<sf::IntRect>> AniTxtrRects;

	sf::Vector2f SpawnPos;
	sf::Vector2f MoveVec;
	sf::RectangleShape Hitbox;
	sf::Vector2f* Speed;
	PhysicsComponent PlayerPhys;
	sf::Clock DmgTimer;
	int Hearts;
};

