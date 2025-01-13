#include "Animation.h"



Animation::Animation(std::string FileName, sf::Vector2f FrameSize,
    sf::Vector2f ScaleFactor)
{
    StartRect = sf::IntRect(0, 0, FrameSize.x, FrameSize.y);
    AniTexture.loadFromFile(FileName);
    AniSprite.setTexture(AniTexture);

    AniSprite.setTextureRect(StartRect);
    AniSprite.setScale(ScaleFactor);
    CurrFrame = 0;
}


sf::Sprite Animation::get_sprite() const
{
    return AniSprite;
}

void Animation::set_pos(sf::Vector2f NewPos)
{
    AniSprite.setPosition(NewPos);
}

void Animation::set_frames(std::vector<sf::IntRect> InFrames)
{
    Frames = InFrames;
}

void Animation::update()
{
    if(AniClock.getElapsedTime().asSeconds() > 0.4) {
        CurrFrame++;
        AniClock.restart();
        
        if (CurrFrame >= (Frames.size())) {
            CurrFrame = 0;
        }
        AniSprite.setTextureRect(Frames.at(CurrFrame));
    }
}

