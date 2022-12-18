#include "Isometric_Square.h"

void Isometric_Square::initVariables()
{
	for(int i = 0; i < 4; i++)
		this->side_visible[i] = true;

	this->side_visible[0] = false;
}

void Isometric_Square::initSprite(std::vector<sf::Texture*>& texture, sf::Vector2f scale, sf::Vector2f pos)
{
	for(int i = 0; i < 4; i++)
	{
		this->side_visible[i] = true;
		this->s_Square[i].setScale(scale);
		this->s_Square[i].setPosition(pos);
		this->s_Square[i].setTexture(*texture[i]);
	}

	this->s_Square[1].setPosition(pos.x, pos.y - 200.f);


	this->s_Square[0].setRotation(45.f);
	this->s_Square[0].setPosition(s_Square[0].getPosition().x, s_Square[0].getPosition().y * 2);

	this->s_Square[1].setColor(sf::Color(255, 255, 255, 255));
	this->s_Square[1].setRotation(45.f);
	this->s_Square[1].setPosition(s_Square[1].getPosition().x, s_Square[1].getPosition().y * 2);

	//this->s_Square[2].setScale(scale.x * 0.7f, scale.y * 0.7f);
	this->s_Square[2].setPosition(sf::Vector2f(this->s_Square[2].getPosition().x - this->s_Square[2].getGlobalBounds().width, this->s_Square[2].getPosition().y - this->s_Square[2].getGlobalBounds().height * 0.17f));
	this->s_Square[3].setPosition(sf::Vector2f(this->s_Square[3].getPosition().x, this->s_Square[3].getPosition().y - this->s_Square[3].getGlobalBounds().height * 0.17f));
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
	if (this->side_visible[3])
		target.draw(this->s_Square[3]);
}

void Isometric_Square::render(sf::RenderTarget& target)
{
		this->renderBottom(target);
		this->renderTop(target);
		this->renderSides(target);
}