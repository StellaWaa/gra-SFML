#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<string>
#include<vector>
#include<iostream>
class Animation
{
public:
	Animation(std::string, sf::Vector2f FrameSize, sf::Vector2f ScaleFactor);
	sf::Sprite get_sprite() const;
	void set_pos(sf::Vector2f);
	void set_frames(std::vector<sf::IntRect>);
	void update();
private:
	sf::Clock AniClock;
	sf::Texture AniTexture;
	sf::Sprite AniSprite;
	std::vector<sf::IntRect> Frames;
	sf::IntRect StartRect;
	int CurrFrame;
};

