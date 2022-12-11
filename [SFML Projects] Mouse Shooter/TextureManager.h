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

#include"FileManagement.h"

class TextureManager
{
private:
	FileManagement filemanager;
	void initVariables();
	void AutoTextureLoader(std::string Path, int key);
	void initLightTextures();
	void initSceneryTextures();
	void initUITextures();
	void initPopBoxes();
	void initIsometricSquares();
	void initTextures();
public:
	TextureManager();
	virtual ~TextureManager();
	enum keys{lights = 0, sceneries, ui, shop_icons, build_icons, popBoxes, isometric_squares};
	//Keylist
	//Use TextureManager::... keys are in enums.
	std::map<int, std::vector<sf::Texture*>> tex;
};

