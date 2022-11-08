#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<filesystem>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class TextureManager
{
private:

	void initVariables();
	int getFileAmountOfFolder(std::string Path);
	void AutoTextureLoader(std::string Path, int key);
	void initLightTextures();
	void initSceneryTextures();
	void initCropTextures();
	void initSeedTextures();
	void initFieldTextures();
	void initUITextures();
	void initTextures();
public:
	TextureManager();
	virtual ~TextureManager();

	enum keys{lights = 0, sceneries, crops, seeds, seeds_icon, fields, ui};
	//Keylist
	//{lights = 0, sceneries = 1, crops = 2, seeds = 3, seeds_icon = 4, fields = 5, ui = 6}
	std::map<int, std::vector<sf::Texture*>> tex;
};

