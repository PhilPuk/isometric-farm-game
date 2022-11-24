#include"base.h"

void Base_UI::initCreateSprites(std::vector<sf::Texture*> textures)
{
    for (int i = 0; i < textures.size(); i++)
    {
        this->sprites.push_back(new sf::Sprite);
        this->sprites[i]->setTexture(*textures[i]);
    }
    std::cout << "Size of base sprites: " << this->sprites.size() << "\n";
}

void Base_UI::initSpritePositions(sf::Vector2u winSize)
{
    ////Bar on the bottom of the screen
    this->sprites[0]->setPosition(0.f, winSize.y - this->sprites[0]->getGlobalBounds().height);
}

void Base_UI::initPopBox(sf::Vector2u winSize)
{
    //Pop bar box on init on shop button position
    this->sprites[1]->setPosition(0.f, 0.f);
}

Base_UI::Base_UI(std::vector<sf::Texture*>& textures, sf::Vector2u winSize)
{
    this->initCreateSprites(textures);
    this->initSpritePositions(winSize);
    this->initPopBox(winSize);
}

Base_UI::~Base_UI()
{
    
}

void Base_UI::setPopBoxXPos(float& x)
{
        this->s_popBox.setPosition(x, this->s_popBox.getPosition().y);
}

void Base_UI::setPopBoxYPos(float& y)
{
    this->s_popBox.setPosition(this->s_popBox.getPosition().x, y);
}

void Base_UI::ActivateClickOnEffect(int index)
{

}

void Base_UI::update()
{
    
}

void Base_UI::renderPopBox(sf::RenderTarget& target)
{
    target.draw(this->s_popBox);   
}