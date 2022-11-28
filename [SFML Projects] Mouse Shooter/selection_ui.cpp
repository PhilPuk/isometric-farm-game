#include "selection_ui.h"

void Selection::initVariables()
{
	this->Active = false;
	this->activatedShape = this->keys[0];

	this->color_selection = sf::Color(255, 0, 255, 110);
}

void Selection::initBaseCircle()
{
	this->circle.setRadius(10.f);
	this->circle.setFillColor(this->color_selection);
}

void Selection::initBaseSquare()
{
	this->square.setSize(sf::Vector2f(10.f, 10.f));
	this->square.setFillColor(this->color_selection);
}

Selection::Selection()
{
	this->initVariables();
	this->initBaseCircle();
	this->initBaseSquare();
}

Selection::~Selection()
{

}

const std::string& Selection::getKeyofShapes(int index) const
{
	return keys[index];
}

void Selection::activate()
{
	this->Active = true;
}

void Selection::deactivate()
{
	this->Active = false;
}

void Selection::changeSizeOfSquare(sf::Vector2f size)
{
	this->square.setSize(size);
}

void Selection::changeRadiusOfCircle(float radius)
{
	this->circle.setRadius(radius);
}

void Selection::changePositionOfSelection(sf::Vector2f& pos)
{
	this->square.setPosition(pos);
	this->circle.setPosition(pos);
}

void Selection::changePositionXOfSelection(float x)
{
	this->square.setPosition(x, this->square.getPosition().y);
	this->circle.setPosition(x, this->circle.getPosition().y);
}

void Selection::changePositionYOfSelection(float y)
{
	this->square.setPosition(this->square.getPosition().x, y);
	this->circle.setPosition(this->circle.getPosition().x, y);
}

void Selection::changeShapeOfSelection(std::string& shape)
{
	this->activatedShape = shape;
}

void Selection::update()
{
	if (this->Active)
	{

	}
}

void Selection::renderSelection(sf::RenderTarget& target)
{
	if (activatedShape == keys[0])
		target.draw(this->circle);
	else
		target.draw(this->square);
}

void Selection::render(sf::RenderTarget& target)
{
	if (this->Active)
	{
		this->renderSelection(target);
	}
}
