#include "Isometric_Square.h"

void Isometric_Square::initVariables()
{

}

void Isometric_Square::initTexture(sf::Texture& texture)
{
	this->s_Square.setTexture(texture);
}

void Isometric_Square::initSpriteScale(sf::Vector2f scale)
{
	this->s_Square.setScale(scale);
}

void Isometric_Square::initSpritePos(sf::Vector2f pos)
{
	this->s_Square.setPosition(pos);
}

void Isometric_Square::initSprite(sf::Texture& texture, sf::Vector2f scale, sf::Vector2f pos)
{
	this->initTexture(texture);
	this->initSpriteScale(scale);
	this->initSpritePos(pos);
}

Isometric_Square::Isometric_Square(sf::Texture& texture_of_square, sf::Vector2f spawn_position, sf::Vector2f scaleOfSprite)
{
	this->initVariables();
	this->initSprite(texture_of_square, scaleOfSprite, spawn_position);
}

Isometric_Square::~Isometric_Square()
{

}

void Isometric_Square::update()
{

}

void Isometric_Square::renderSquare(sf::RenderTarget& target)
{
	target.draw(this->s_Square);
}

void Isometric_Square::render(sf::RenderTarget& target)
{
	this->renderSquare(target);
}
