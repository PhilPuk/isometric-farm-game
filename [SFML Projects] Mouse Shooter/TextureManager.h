#pragma once

#include<iostream>
#include<vector>

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
	void initTextures();
public:
	TextureManager();
	virtual ~TextureManager();

	sf::Texture light;
};

