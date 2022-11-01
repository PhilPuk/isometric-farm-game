#include "Field.h"

void Field::initVariables()
{
	this->lvl = ONE;
	this->currentCropAmount = lvl;
	this->FieldFilled = false;
}

void Field::initFirstCrop(sf::Texture t_Crop, sf::Vector2f pos)
{
	//Create first crop
	this->crops.push_back(new Crops(t_Crop, pos, 0));
}

void Field::initField(sf::Texture t_Field, sf::Vector2f pos)
{
	this->s_Field.setTexture(t_Field);
	this->s_Field.setPosition(pos);
}

Field::Field(sf::Texture t_Crop, sf::Texture t_Field, sf::Vector2f pos)
{
	this->initVariables();
	this->initFirstCrop(t_Crop, pos);
	this->initField(t_Field, pos);
}

Field::~Field()
{
	for (auto& i : crops)
	{
		this->crops.erase(this->crops.begin(), this->crops.end());
	}
	std::cout << "Size of deleted crop vector array: " << this->crops.size() << "\n";
}

void Field::newCrop()
{

}

void Field::updateUpgradedCropTexture(sf::Texture& texture)
{

}

void Field::upgradeCrop()
{

}

void Field::update()
{

}

void Field::renderField(sf::RenderTarget& target)
{
	target.draw(this->s_Field);
}

void Field::renderCrops(sf::RenderTarget& target)
{
	for (auto& i : crops)
	{
		i->render(target);
	}
}

//Renders crops on top of the field
void Field::render(sf::RenderTarget& target)
{
	this->renderField(target);
	this->renderCrops(target);
}
