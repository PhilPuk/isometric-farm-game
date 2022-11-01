#pragma once

#include"Field.h"

class FieldManager
{
private:
	sf::Texture t_Field;
	sf::Texture t_Crop;

	std::vector<Field*> fields;

	void initVariables();
	void initTextures(sf::Texture& t_Field, sf::Texture& t_Crop);
	void initBeginnerField();
public:
	FieldManager(sf::Vector2u& winSize, sf::Texture& t_Field, sf::Texture& t_Crop);
	virtual~FieldManager();

	void update();

	void renderFields(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

