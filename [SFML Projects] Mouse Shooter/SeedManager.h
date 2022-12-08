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

	Seed createNewSeed(sf::Vector2f pos, int indexOfSeed);

	void update(Timer& timer);

	void render(sf::RenderTarget& target);
};

