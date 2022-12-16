#include "Isometric_Square.h"

void Isometric_Square::initVariables()
{
	for(int i = 0; i < 3; i++)
		this->side_visible[i] = true;
}

void Isometric_Square::initSprite(std::vector<sf::Texture*>& texture, sf::Vector2f scale, sf::Vector2f pos)
{
	for(int i = 0; i < 4; i++)
	{
		this->side_visible[i] = true;
		this->s_Square[i].setScale(scale);
		this->s_Square[i].setPosition(pos);
	}

	this->s_Square[1].setPosition(pos.x, pos.y - (0.2f * this->s_Square[0].getGlobalBounds().height));

	this->s_Square[0].setTexture(*texture[0]);
	this->s_Square[0].setRotation(45.f);
	this->s_Square[0].setPosition(s_Square[0].getPosition().x, s_Square[0].getPosition().y * 2);

	this->s_Square[1].setTexture(*texture[0]);
	this->s_Square[1].setPosition(s_Square[1].getPosition().x, s_Square[1].getPosition().y * 2);

	this->s_Square[2].setTexture(*texture[1]);
}

Isometric_Square::Isometric_Square(std::vector<sf::Texture*>& textures, sf::Vector2f spawn_position, sf::Vector2f scaleOfSprite)
{
	this->initVariables();
	this->initSprite(textures, scaleOfSprite, spawn_position);
}

Isometric_Square::~Isometric_Square()
{

}


void Isometric_Square::activateFrontVisibility()
{
	this->side_visible[2] = true;
}

void Isometric_Square::activateTopVisibility()
{
	this->side_visible[1] = true;
}

void Isometric_Square::activateBottomVisibility()
{
	this->side_visible[0] = true;
}

void Isometric_Square::deActivateFrontVisibility()
{
	this->side_visible[2] = false;
}

void Isometric_Square::deActivateTopVisibility()
{
	this->side_visible[1] = false;
}

void Isometric_Square::deActivateBottomVisibility()
{
	this->side_visible[0] = false;
}

void Isometric_Square::update()
{

}

void Isometric_Square::renderBottom(sf::RenderTarget& target)
{
	if(this->side_visible[0])
		target.draw(this->s_Square[0]);
}


void Isometric_Square::renderTop(sf::RenderTarget& target)
{
	if(this->side_visible[1])
		target.draw(this->s_Square[1]);
}

void Isometric_Square::renderSides(sf::RenderTarget& target)
{
	if(this->side_visible[2])
		target.draw(this->s_Square[2]);
}

void Isometric_Square::render(sf::RenderTarget& target)
{
	if(this->side_visible[0])
		this->renderBottom();
	if(this->side_visible[1])
		this->renderTop();
	if(this->side_visible[2])
		this->renderSides();
}