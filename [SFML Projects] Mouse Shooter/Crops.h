#pragma once
#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"Seed.h"


class Crops
{
private:
	//Evolution stage of plant on crop
	enum Growth_Stage { SEED = 0, BABY, KID, TEEN, PARENT};
	Seed* seed;
	uint8_t PLACE_IN_FIELD;
	bool hasSeed;

	void initVariables(uint8_t PLACE_IN_FIELD);
	void initSprite(sf::Texture& texture, sf::Vector2f pos);
public:
	Crops(sf::Texture& texture, sf::Vector2f pos, uint8_t PLACE_IN_FIELD);
	virtual~ Crops();

	sf::Sprite s_crop;

	//Modifiers
	void assignSeed(Seed* seed);
	void removeSeed();
	void reScaleCrop(sf::Vector2f scale);

	void update();

	void renderCrop(sf::RenderTarget& target);
	void renderSeed(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

