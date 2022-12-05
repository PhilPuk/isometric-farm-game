#include "Crops.h"

void Crops::initVariables(uint8_t PLACE_IN_FIELD)
{
	this->seed = nullptr;

	this->PLACE_IN_FIELD = PLACE_IN_FIELD;

	this->hasSeed = false;
	this->isMarked = false;
}

void Crops::initSprite(sf::Texture& texture, sf::Vector2f pos)
{
	this->s_crop.setTexture(texture);
	this->s_crop.setPosition(pos);
}

Crops::Crops(sf::Texture& texture, sf::Vector2f pos, uint8_t PLACE_IN_FIELD)
{
	this->initVariables(PLACE_IN_FIELD);
	this->initSprite(texture, pos);
}

Crops::~Crops()
{
	delete this->seed;
}

void Crops::assignSeed(Seed* seed)
{
	if (this->seed != nullptr)
	{
		std::cout << " - Assert: Crop already got a seed!\n";
		return;
	}
	else
	{
		this->seed = seed;
	}
}

void Crops::removeSeed()
{
	if (this->seed == nullptr)
	{
		std::cout << " - Assert: Crop is already empty!\n";
	}
	else
	{
		this->seed = nullptr;
	}
}

void Crops::reScaleCrop(sf::Vector2f scale)
{
	this->s_crop.setScale(scale);
}

void Crops::setIsMarked()
{
	this->isMarked = true;
}

void Crops::resetIsMarked()
{
	this->isMarked = false;
}

const bool& Crops::getHasSeed() const
{
	return this->hasSeed;
}

const bool& Crops::getIsMarked() const
{
	return this->isMarked;
}

void Crops::update()
{

}

void Crops::renderCrop(sf::RenderTarget& target)
{
	target.draw(this->s_crop);
}

void Crops::renderSeed(sf::RenderTarget& target)
{
	this->seed->renderOnCroop(target);
}

void Crops::render(sf::RenderTarget& target)
{
	this->renderCrop(target);
	if(this->hasSeed)
		this->renderSeed(target);
}
