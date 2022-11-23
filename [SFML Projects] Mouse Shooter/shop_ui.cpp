#include"shop_ui.h"

void Shop_UI::initVariables()
{

}

void Shop_UI::initCreateSprites(std::vector<sf::Texture*> textures)
{
    for(int i = 0; i < textures.size(); i++)
    {
        this->sprites.push_back(new sf::Sprite);
        this->sprites[i]->setTexture(*textures[i]);
    }
    std::cout << "Size of shop sprites: " << this->sprites.size() << "\n";
}
void Shop_UI::initSpritePositions(sf::Vector2u& winSize, sf::Vector2f bottom_bar_Pos)
{
    this->sprites[0]->scale(0.3f, 0.3f);
	this->sprites[0]->setPosition(20.f, static_cast<float>(winSize.y) - this->sprites[0]->getGlobalBounds().height * 1.2f);
}

Shop_UI::Shop_UI(sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f bottom_bar_Pos)
{
    this->initCreateSprites(textures);
    this->initSpritePositions(winSize, bottom_bar_Pos);
}

Shop_UI::~Shop_UI()
{
    for(auto& i : this->sprites)
    {
        this->sprites.erase(this->sprites.begin(), this->sprites.end());
    }
}

void Shop_UI::update()
{

}