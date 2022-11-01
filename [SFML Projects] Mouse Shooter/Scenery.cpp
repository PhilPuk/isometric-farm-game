#include "Scenery.h"

void initVariables()
{

}

void Scenery::initTextures(std::vector<sf::Texture>& t_Sceneries)
{
	for (int i = 0; i < (sizeof(SCENERIES_KEYS) / sizeof(SCENERIES_KEYS[0])); i++)
	{
		this->t_Sceneries[this->SCENERIES_KEYS[i]] = t_Sceneries[i];
	}
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

std::string Scenery::get_Scenery_Keys(int index)
{
	return this->SCENERIES_KEYS[index];
}

//Modifiers

void Scenery::switchScenery(std::string& key)
{
	this->s_Scenery.setTexture(this->t_Sceneries[key]);
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
