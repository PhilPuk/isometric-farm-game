#pragma once

#include<iostream>
#include<vector>
#include<map>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class TextureManager
{
private:

	void initVariables();
	void initLightTextures();
	void initSceneryTextures();
	void initCropTextures();
	void initSeedTextures();
	void initTextures();
public:
	TextureManager();
	virtual ~TextureManager();

	//Maybe use function pointer to create reusable for loops to load in each texture
	//Choose between these two methods

	std::vector<sf::Texture> lights;
	std::vector<sf::Texture> sceneries;
	std::vector<sf::Texture> crops;
	std::vector<sf::Texture> seeds;

	std::map<std::string, std::vector<sf::Texture>> textures;
};

