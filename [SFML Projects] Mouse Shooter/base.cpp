#include"base.h"

void Base_UI::initSpritePositions(sf::Vector2u winSize)
{
    //Bar on the bottom of the screen
    this->sprites[0].setPosition(0.f, winSize.y - this->sprite[0].getGlobalBounds().height);
}

void Base_UI::initPopBox(sf::Vector2f winSize, sf::Vector2f shop_icon_pos)
{
    //Pop bar box on init on shop button position
    this->sprites[1].setPosition(shop_icon_pos.x, shop_icon_pos.y - this->sprites[1].getGlobalBounds().height);
}

Base_UI::Base_UI(std::vector<sf::Texture*>& textures, sf::Vector2u winSize, sf::Vector2f shop_icon_pos)
{
    initCreateSprites(textures);
    this->initSpritePositions(winSize);
    this->initPopBox(winSize, shop_icon_pos);
}

Base_UI::~Base_UI()
{
    
}

void Base_UI::setPopBoxXPos(float& x)
{
        this->s_popBox.setPosition(x, this->s:popBox.getPosition().y);
}

void ActivateClickOnEffect(int index)
{
    
}

void Base_UI::update()
{
    
}