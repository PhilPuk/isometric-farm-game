#include "Scenery.h"

void initVariables()
{

}

void Scenery::initVariables()
{

}

void Scenery::initTextures(std::vector<sf::Texture>& t_Sceneries)
{
}

Scenery::Scenery(std::vector<sf::Texture>& t_Sceneries)
{
	this->initVariables();
	this->initTextures(t_Sceneries);
}

Scenery::~Scenery()
{

}
//Accessors

//Modifiers

void Scenery::switchScenery(int& key)
{
	//this->s_Scenery.setTexture(this->t_Sceneries[key]);
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
