#include "Scenery.h"

void Scenery::initVariables()
{

}

void Scenery::initStartScenery(sf::Vector2u& winSize, std::vector<sf::Texture*> t_Sceneries)
{
	this->s_Scenery.setTexture(*t_Sceneries[0]);
	//center origin
	sf::FloatRect textRect = this->s_Scenery.getLocalBounds();
	this->s_Scenery.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//center in screen
	this->s_Scenery.setPosition(sf::Vector2f(static_cast<int>(winSize.x) / 2.f, static_cast<int>(winSize.y) / 2.f));
}

Scenery::Scenery(std::vector<sf::Texture*> t_Sceneries, sf::Vector2u& winSize)
{
	this->initVariables();
	this->initStartScenery(winSize, t_Sceneries);
}

Scenery::~Scenery()
{

}
//Accessors

//Modifiers

void Scenery::switchScenery(int& key, std::vector<sf::Texture*> textures)
{
	this->s_Scenery.setTexture(*textures[key]);
}


void Scenery::update()
{

}

void Scenery::renderSelectedScenery(sf::RenderTarget& target)
{
	target.draw(this->s_Scenery);
}

void Scenery::render(sf::RenderTarget& target)
{
	this->renderSelectedScenery(target);
}
