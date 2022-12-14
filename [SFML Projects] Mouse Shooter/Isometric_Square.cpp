#include "Isometric_Square.h"

void Isometric_Square::initVariables()
{
	r = 0;
	g = 0;
	b = 0;
}

void Isometric_Square::initSprite(sf::Texture& texture, sf::Vector2f scale, sf::Vector2f pos)
{
	for(int i = 0; i < 4; i++)
	{
		this->side_visible[i] = true;
		this->s_Square[i].setTexture(texture);
		this->s_Square[i].setScale(scale);
		this->s_Square[i].setPosition(pos);
	}
	this->s_Square[0].setRotation(45.f);
	this->s_Square[0].setPosition(s_Square[0].getPosition().x, s_Square[0].getPosition().y * 2);
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
	r += 1;
	g += 1;
	b += 1;
	//if (r < 255)
	//	r = 0;
	//if (g < 255)
	//	g = 0;
	//if (b < 255)
	//	b = 0;
	this->s_Square[0].setColor(sf::Color(r, g, b, 255));

}

void Isometric_Square::renderBottom(sf::RenderTarget& target)
{
	sf::View v = target.getDefaultView();
	v.setSize(v.getSize().x, v.getSize().y * 2);
	v.setCenter(v.getSize() * .5f);

	target.setView(v);
	target.draw(this->s_Square[0]);
	target.setView(target.getDefaultView());
}

void Isometric_Square::renderSides(sf::RenderTarget& target)
{
	this->renderBottom(target);
}

void Isometric_Square::render(sf::RenderTarget& target)
{
	this->renderSides(target);
}