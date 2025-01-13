#include "Animation.h"



Animation::Animation(std::string FileName, sf::Vector2f FrameSize,
    sf::Vector2f ScaleFactor)
{
    StartRect = sf::IntRect(0, 0, FrameSize.x, FrameSize.y);
    AniTexture.loadFromFile(FileName);
    AniSprite.setTexture(AniTexture);

    //AniSprite.setTextureRect(StartRect);
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
    int NumOfFrames = Frames.size();
    if(AniClock.getElapsedTime().asSeconds() > (1/60. * 60/NumOfFrames)) {
        CurrFrame++;
        AniClock.restart();
        
        if (CurrFrame >= (NumOfFrames)) {
            CurrFrame = 0;
        }
        std::cout << CurrFrame << '\n';
        AniSprite.setTextureRect(Frames.at(CurrFrame));
    }
}

