#include "Seed.h"

void Seed::initVariables()
{

}

void Seed::init_s_OnCrop(sf::Texture& t_OnCrop, sf::Vector2f pos)
{
	this->s_OnCrop.setTexture(t_OnCrop);
	this->s_OnCrop.setPosition(pos);
}

void Seed::init_cSh_Pic(sf::Texture& t_Pic, sf::Vector2f pos)
{
	this->cSh_Icon.setTexture(&t_Pic);
	this->cSh_Icon.setPosition(pos);
}

void Seed::initSprites(sf::Texture& t_OnCrop, sf::Texture& t_Pic, sf::Vector2f pos)
{
	this->init_s_OnCrop(t_OnCrop, pos);
	this->init_cSh_Pic(t_Pic, pos);
}

Seed::Seed(sf::Texture& t_OnCrop, sf::Texture& t_Pic, sf::Vector2f pos)
{
	this->initVariables();
	this->initSprites(t_OnCrop, t_Pic, pos);
}

Seed::~Seed()
{

}

void Seed::renderIcon(sf::RenderTarget& target)
{
	target.draw(this->cSh_Icon);
}

void Seed::renderOnCroop(sf::RenderTarget& target)
{
	target.draw(this->s_OnCrop);
}
