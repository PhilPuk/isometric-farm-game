#pragma once

#include"Field.h"

class FieldManager
{
private:
	sf::Texture t_Field;
	sf::Texture t_Crop;

	void initVariables();
	void initTextures(sf::Texture* t_Field, sf::Texture* t_Crop);
	void initBeginnerField(sf::Vector2u& winSize);
public:
	FieldManager(sf::Vector2u& winSize, sf::Texture* t_Field, sf::Texture* t_Crop);
	virtual~FieldManager();

	std::vector<Field*> fields;

	void update();

	void renderFields(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

