#include "Isometric_Square.h"

void Isometric_Square::initVariables()
{
	r = 0;
	g = 0;
	b = 0;
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

	this->s_Square[3].setTexture(*texture[1]);
}

Isometric_Square::Isometric_Square(std::vector<sf::Texture*>& textures, sf::Vector2f spawn_position, sf::Vector2f scaleOfSprite)
{
	this->initVariables();
	this->initSprite(textures, scaleOfSprite, spawn_position);
}

Isometric_Square::~Isometric_Square()
{

}

void Isometric_Square::update()
{

}

void Isometric_Square::renderBottom(sf::RenderTarget& target)
{
	sf::View v = target.getDefaultView();
	v.setSize(v.getSize().x, v.getSize().y * 2);
	v.setCenter(v.getSize() * .5f);

	target.setView(v);
	target.draw(this->s_Square[0]);
	target.draw(this->s_Square[1]);
	target.setView(target.getDefaultView());
	target.draw(this->s_Square[2]);
}

void Isometric_Square::renderSides(sf::RenderTarget& target)
{
	this->renderBottom(target);
}

void Isometric_Square::render(sf::RenderTarget& target)
{
	this->renderSides(target);
}