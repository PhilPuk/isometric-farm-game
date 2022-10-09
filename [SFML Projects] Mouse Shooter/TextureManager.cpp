#include "TextureManager.h"

void TextureManager::initVariables()
{

}

void TextureManager::initLightTextures()
{
	if (!this->light.loadFromFile("Textures/bloom.png"))
	{
		std::cout << " - ERROR::TEXTUREMANAGER::INITLIGHTTEXTURES::Couldn't load texture: Textures/bloom.png\n";
	}
}

void TextureManager::initTextures()
{
	this->initLightTextures();
}

TextureManager::TextureManager()
{
	this->initVariables();
	this->initTextures();
}

TextureManager::~TextureManager()
{

}
