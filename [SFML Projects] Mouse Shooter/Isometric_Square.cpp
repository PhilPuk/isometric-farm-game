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
	this->initTestingSquare();
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
	this->renderNew(target);
}

//For testing!!! WORKS! tested in school
void Isometric_Square::initTestingSquare()
{
	this->s_new = s_Square;
	this->s_new.setPosition(100.f,100.f);

	s_new.setRotation(45.f);
	//adjust the position for new screen coordinates (once)
	s_new.setPosition(s_new.getPosition().x, s_new.getPosition().y * 2);

}

//For testing!!! | WORKS! tested in school
void Isometric_Square::renderNew(sf::RenderTarget& target)
{
	sf::View v = target.getDefaultView();
	v.setSize(v.getSize().x, v.getSize().y * 2);
	v.setCenter(v.getSize() *.5f);

	target.setView(v);
	target.draw(my_sprite);
	target.setView(target.getDefaultView());
}