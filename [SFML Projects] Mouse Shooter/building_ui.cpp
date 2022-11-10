#include"building_ui.h"

void Building_UI::initVariables()
{

}
void Building_UI::initCreateSprites(std::vector<sf::Texture*> textures)
{
    for(int i = 0; i < textures.size(); i++)
    {
        this->s_Building.push_back(new sf::Sprite);
        this->s_Building[i]->setTexture(*textures[i]);
    }
}

void Building_UI::initSpritePositions(sf::Vector2u& winSize, sf::Vector2f bottom_bar_Pos)
{
    this->s_Building[0]->scale(0.3f, 0.3f);
	this->s_Building[0]->setPosition(20.f * 2.f + this->s_Building[0]->getGlobalBounds().width, static_cast<float>(winSize.y) - this->s_Building[0]->getGlobalBounds().height * 0.86f);
}

Building_UI::Building_UI(sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f bottom_bar_Pos)
{
    this->initCreateSprites(textures);
    this->initSpritePositions(winSize, bottom_bar_Pos);
}
Building_UI::~Building_UI()
{
    for(auto& i : this->s_Building)
    {
        this->s_Building.erase(this->s_Building.begin(), this->s_Building.end());
    }
}

void Building_UI::update()
{

}

void Building_UI::renderShopButton(sf::RenderTarget& target)
{
    target.draw(*this->s_Building[0]);
}
void Building_UI::renderItems(sf::RenderTarget& target, bool& buildingActivated)
{
    //element 0 gets double rendered!
    if(buildingActivated)
        for(auto& i : this->s_Building)
            target.draw(*i);
}
void Building_UI::render(sf::RenderTarget& target, bool& buildingActivated)
{
    this->renderShopButton(target);
    this->renderItems(target, buildingActivated);
}