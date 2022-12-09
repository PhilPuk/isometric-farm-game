#pragma once
#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"Timer.h"
#include"TextureManager.h"
#include"Seed.h"

class SeedManager
{
private:

	void initVariables();
public:
	SeedManager();
	virtual ~SeedManager();

	//Contains all seeds that are on crops
	std::vector<Seed*> seeds;

	void createNewSeed(sf::Vector2f pos, int indexOfSeed, sf::Texture& t_OnCrop, sf::Texture& t_Icon);

	void update(Timer& timer);

	void renderSeeds(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

