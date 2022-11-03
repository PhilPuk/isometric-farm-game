#include "Scenery.h"

void Scenery::initVariables()
{

}

void Scenery::initTextures(std::vector<sf::Texture*> t_Sceneries)
{
	this->t_Sceneries = t_Sceneries;
}

void Scenery::initStartScenery(sf::Vector2u& winSize)
{
	this->s_Scenery.setTexture(*this->t_Sceneries[0]);
	//center origin
	sf::FloatRect textRect = this->s_Scenery.getLocalBounds();
	this->s_Scenery.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//center in screen
	this->s_Scenery.setPosition(sf::Vector2f(static_cast<int>(winSize.x) / 2.f, static_cast<int>(winSize.y) / 2.f));
}

Scenery::Scenery(std::vector<sf::Texture*> t_Sceneries, sf::Vector2u& winSize)
{
	this->initVariables();
	this->initTextures(t_Sceneries);
	this->initStartScenery(winSize);
}

Scenery::~Scenery()
{
	for (auto& i : this->t_Sceneries)
	{
		this->t_Sceneries.erase(this->t_Sceneries.begin(), this->t_Sceneries.end());
	}
	std::cout << "Size of scenery vector array: " << this->t_Sceneries.size()<<"\n";
}
//Accessors

//Modifiers

void Scenery::switchScenery(int& key)
{
	this->s_Scenery.setTexture(*this->t_Sceneries[key]);
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
