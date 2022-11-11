#include"shop_ui.h"

void Shop_UI::initVariables()
{

}

void Shop_UI::initCreateSprites(std::vector<sf::Texture*> textures)
{
    for(int i = 0; i < textures.size(); i++)
    {
        this->s_Shop.push_back(new sf::Sprite);
        this->s_Shop[i]->setTexture(*textures[i]);
    }
}
void Shop_UI::initSpritePositions(sf::Vector2u& winSize, sf::Vector2f bottom_bar_Pos)
{
    this->s_Shop[0]->scale(0.3f, 0.3f);
	this->s_Shop[0]->setPosition(20.f, static_cast<float>(winSize.y) - this->s_Shop[0]->getGlobalBounds().height * 0.86f);
}

Shop_UI::Shop_UI(sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f bottom_bar_Pos)
{
    this->initCreateSprites(textures);
    this->initSpritePositions(winSize, bottom_bar_Pos);
}
Shop_UI::~Shop_UI()
{
    for(auto& i : this->s_Shop)
    {
        this->s_Shop.erase(this->s_Shop.begin(), this->s_Shop.end());
    }
}

void Shop_UI::update()
{

}

void Shop_UI::renderShopButton(sf::RenderTarget& target)
{
    target.draw(*this->s_Shop[0]);
}
void Shop_UI::renderItems(sf::RenderTarget& target, bool& shopActivated)
{
        if(shopActivated)
        for(auto& i : this->s_Shop)
            target.draw(*i);
}
void Shop_UI::render(sf::RenderTarget& target, bool& shopActivated)
{
    this->renderShopButton(target);
    this->renderItems(target, shopActivated);
}