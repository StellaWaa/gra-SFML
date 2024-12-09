#include "Platform.h"

Platform::Platform(sf::Vector2f in_pos, sf::Vector2f in_size)
{
    Hitbox.setPosition(in_pos);
    Hitbox.setSize(in_size);
}

sf::RectangleShape Platform::get_hitbox() const
{
    return Hitbox;
}

void Platform::set_position(sf::Vector2f InPos)
{
    Hitbox.setPosition(InPos);
}

void Platform::move(sf::Vector2f MoveVec)
{
    Hitbox.move(MoveVec);
}
