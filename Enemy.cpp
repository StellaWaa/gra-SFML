#include "Enemy.h"


Enemy::Enemy(sf::Vector2f in_pos, sf::Vector2f in_size)
{
    Hitbox.setPosition(in_pos);
    Hitbox.setSize(in_size);
    Hitbox.setFillColor(sf::Color::Red);
}

sf::RectangleShape Enemy::get_hitbox() const
{
    return Hitbox;
}
