#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<stdio.h>
#include<Windows.h>

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
	void initTexturesBaseLoop(std::string Path, int key, int size);
	void initLightTextures();
	void initSceneryTextures();
	void initCropTextures();
	void initSeedTextures();
	void initTextures();
public:
	TextureManager();
	virtual ~TextureManager();

	enum keys{lights = 0, sceneries, crops, seeds, fields};
	std::map<int, std::vector<sf::Texture>> tex;
};

