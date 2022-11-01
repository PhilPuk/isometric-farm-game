#pragma once

#include<vector>

#include"Crops.h"

class Field
{
private:
	sf::Sprite s_Field;

	enum CROPAMOUNT { ONE = 1, TWO = 2, FOUR = 4, SIX = 6 };
	uint8_t lvl;
	uint8_t currentCropAmount;
	bool FieldFilled;
	std::vector<Crops*> crops;

	void initVariables();
	void initFirstCrop(sf::Texture t_Crop, sf::Vector2f pos);
	void initField(sf::Texture t_Field, sf::Vector2f pos);
public:
	Field(sf::Texture t_Crop, sf::Texture t_Field, sf::Vector2f pos);
	virtual ~Field();

	void newCrop();
	void updateUpgradedCropTexture(sf::Texture& texture);
	void upgradeCrop();

	void update();

	void renderField(sf::RenderTarget& target);
	void renderCrops(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

