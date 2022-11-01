#include "FieldManager.h"

void FieldManager::initVariables()
{

}

void FieldManager::initTextures(sf::Texture& t_Field, sf::Texture& t_Crop)
{
	this->t_Field = t_Field;
	this->t_Crop = t_Crop;
}

void FieldManager::initBeginnerField()
{
	this->fields.push_back(new Field(this->t_Crop, this->t_Field, sf::Vector2f(900, 450)));
}

FieldManager::FieldManager(sf::Vector2u& winSize, sf::Texture& t_Field, sf::Texture& t_Crop)
{
	this->initVariables();
	this->initTextures(t_Field, t_Crop);
	this->initBeginnerField();
}

FieldManager::~FieldManager()
{
	for (auto& i : fields)
	{
		this->fields.erase(this->fields.begin(), this->fields.end());
	}
	std::cout << "Size of fields vector array: " << this->fields.size() << " - SHOULD BE 0!\n";
}

void FieldManager::update()
{

}

void FieldManager::renderFields(sf::RenderTarget& target)
{
	for (auto& i : fields)
	{
		i->render(target);
	}
}
void FieldManager::render(sf::RenderTarget& target)
{
	this->renderFields(target);
}
