#include"baseLayer.h"

void baseLayer::initVariables()
{
	

}
void baseLayer::initCreateSprites(std::vector<sf::Texture*> textures)
{
	//for(int i = 0; i < textures.size(); i++)
 //   {
 //       this->sprites.push_back(new sf::Sprite);
 //       this->sprites[i]->setTexture(*textures[i]);
 //   }
}
void baseLayer::initSpritePositions(sf::Vector2u& winSize, sf::Vector2f Pos, sf::Vector2f scale)
{
 //   this->sprites[0]->scale(scale);
	//this->sprites[0]->setPosition(Pos);
}

baseLayer::baseLayer()
{

}

baseLayer::baseLayer(sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f Pos, sf::Vector2f scale)
{
    this->initCreateSprites(textures);
    this->initSpritePositions(winSize, Pos, scale);
}

baseLayer::~baseLayer()
{
    for(auto& i : this->sprites)
    {
        this->sprites.erase(this->sprites.begin(), this->sprites.end());
    }
}

void baseLayer::update()
{
}

//Renders base icon only.
void baseLayer::renderBaseIcon(sf::RenderTarget& target)
{
    target.draw(*this->sprites[0]);
}

//Renders all sprites in the container.
void baseLayer::renderItems(sf::RenderTarget& target)
{
    for(auto& i : this->sprites)
    {
        target.draw(*i);
    }
}

void baseLayer::renderTexts(sf::RenderTarget& target)
{
    for (auto& it : this->texts)
    {
        target.draw(*it);
    }
}

void baseLayer::render(sf::RenderTarget& target, bool& Activated)
{
    if(!Activated)
    this->renderBaseIcon(target);
    else
    {
        this->renderItems(target);
        this->renderTexts(target);
    }
}