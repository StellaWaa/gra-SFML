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

void Enemy::set_position(sf::Vector2f InPos)
{
    Hitbox.setPosition(InPos);
}

void Enemy::move(sf::Vector2f MoveVec, bool MvdByCamera)
{
    Hitbox.move(MoveVec);
}

void Enemy::draw(sf::RenderWindow& InWindow) const
{
    InWindow.draw(Hitbox);
}
