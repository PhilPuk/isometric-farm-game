#include "TextureManager.h"

void TextureManager::initVariables()
{

}

int TextureManager::getFileAmountOfFolder(std::string Path)
{
	auto dirIter = std::experimental::filesystem::directory_iterator(Path);
	int fileCount = 0;

	for (auto& entry : dirIter)
	{
    	if (entry.is_regular_file())
    	{
	        ++fileCount;
	    }
	}
	return fileCount;
}

void TextureManager::initTexturesBaseLoop(std::string Path, int key, int size)
{
	std::stringstream s;
	this->tex[key].reserve(size);
	for (int i = 0; i < size; i++)
	{
		s << Path << i << ".png";
		if (!this->tex[key][i].loadFromFile(s.str()))
			std::cout << " - ERROR::TEXTUREMANAGER::INITTEXTURES::Coulnd't load texture at: " << s.str() << "\n";
		s.clear();
	}
}

void TextureManager::initLightTextures()
{
	//Test for file count in directory function
	//std::cout<<"File amount of textures: "<<this->getFileAmountOfFolder("Textures/bloom");

	this->initTexturesBaseLoop("Textures/bloom/bloom", lights, this->getFileAmountOfFolder("Textures/bloom"));
}

void TextureManager::initSceneryTextures()
{
	this->initTexturesBaseLoop("Textures/Scenery/scenery", sceneries, this->getFileAmountOfFolder("Textures/Scenery"));
}

void TextureManager::initCropTextures()
{
	this->initTexturesBaseLoop("Textures/Crops/crop", crops, this->getFileAmountOfFolder("Textures/Crops"));
}

void TextureManager::initSeedTextures()
{
	this->initTexturesBaseLoop("Textures/Seeds/seed", seeds, this->getFileAmountOfFolder("Textures/Seeds"));
}

void TextureManager::initFieldTextures()
{
	this->initTexturesBaseLoop("Textures/Fields/field", fields, this->getFileAmountOfFolder("Textures/Fields"));
}

void TextureManager::initTextures()
{
	this->initLightTextures();
	this->initSceneryTextures();
	this->initCropTextures();
	this->initSeedTextures();
}

TextureManager::TextureManager()
{
	this->initVariables();
	this->initTextures();
}

TextureManager::~TextureManager()
{

}
