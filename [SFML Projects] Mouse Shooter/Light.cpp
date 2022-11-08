#include "Light.h"

void Light::initVariables()
{

}

void Light::initSprite(sf::Texture& texture, sf::Vector2f* scale, sf::Vector2f& pos, bool CenterOrigin)
{
	
	this->sprite.setTexture(texture);
	this->sprite.setColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 30));
	if (CenterOrigin)
	{
		this->sprite.setOrigin
		(
			this->sprite.getLocalBounds().left + this->sprite.getLocalBounds().width / 2.0f,
			this->sprite.getLocalBounds().top + this->sprite.getLocalBounds().height / 2.0f
		);
	}

	if (scale != nullptr)
		this->sprite.setScale(*scale);

	this->sprite.setPosition(pos);
}

void Light::initCenter(sf::Vector2f* scale, sf::Vector2f& pos, bool CenterOrigin)
{
	this->center.setFillColor(sf::Color(255, 255, 255, 10));
	this->center.setRadius(10.f);
	if (CenterOrigin)
	{
		this->center.setOrigin
		(
			this->center.getLocalBounds().left + this->center.getLocalBounds().width / 2.0f,
			this->center.getLocalBounds().top + this->center.getLocalBounds().height / 2.0f
		);
	}
	if (scale != nullptr)
		this->center.setScale(*scale);

	this->center.setPosition(pos);
}

Light::Light(sf::Texture& texture, sf::Vector2f* scale, sf::Vector2f& pos, bool CenterOrigin)
{
	this->initVariables();
	this->initSprite(texture, scale, pos, CenterOrigin);
	this->initCenter(scale, pos, CenterOrigin);
}   

Light::~Light()
{

}

void Light::moveLight(sf::Vector2f& velocity)
{
	this->sprite.move(velocity);
	this->center.move(velocity);
}

void Light::renderSprite(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

void Light::renderCenter(sf::RenderTarget& target)
{
	target.draw(this->center);
}

void Light::render(sf::RenderTarget& target)
{
	this->renderSprite(target);
	this->renderCenter(target);
}
