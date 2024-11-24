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
