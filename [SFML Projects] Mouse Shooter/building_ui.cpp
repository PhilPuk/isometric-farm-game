#include"building_ui.h"

void Building_UI::initVariables()
{

}

void Building_UI::initCreateSprites(std::vector<sf::Texture*> textures)
{
    for(int i = 0; i < textures.size(); i++)
    {
        this->sprites.push_back(new sf::Sprite);
        this->sprites[i]->setTexture(*textures[i]);
    }
}

void Building_UI::initSpritePositions(sf::Vector2u& winSize, sf::Vector2f bottom_bar_Pos)
{
    this->sprites[0]->scale(0.3f, 0.3f);
	this->sprites[0]->setPosition(20.f * 2.f + this->sprites[0]->getGlobalBounds().width, static_cast<float>(winSize.y) - this->sprites[0]->getGlobalBounds().height * 0.86f);
}

Building_UI::Building_UI(sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f bottom_bar_Pos)
{
    this->initCreateSprites(textures);
    this->initSpritePositions(winSize, bottom_bar_Pos);
}
Building_UI::~Building_UI()
{
    for(auto& i : this->sprites)
    {
        this->sprites.erase(this->sprites.begin(), this->sprites.end());
    }
}

void Building_UI::update()
{
    
}