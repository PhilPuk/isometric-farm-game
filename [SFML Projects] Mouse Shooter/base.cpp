#include"base.h"

void Base_UI::initSpritePositions(sf::Vector2u winSize)
{
    
}

void Base_UI::initPopBox(sf::Vector2f winSize, sf::Vector2f shop_icon_pos)
{

}

Base_UI::Base_UI()
{
    initCreateSprites(textures);
    this->initSpritePositions(winSize);
}

Base_UI::~Base_UI()
{
    
}

void Base_UI::setPopBoxXPos(float& x)
{
        this->s_popBox.setPosition(x, this->s:popBox.getPosition().y);
}

void Base_UI::update()
{
    
}