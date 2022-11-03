#include "TextureManager.h"

void TextureManager::initVariables()
{

}

int TextureManager::getFileAmountOfFolder(std::string Path)
{
	auto dirIter = std::filesystem::directory_iterator(Path);
	int fileCount = 0;

	for (auto& entry : dirIter)
	{
    	if (entry.is_regular_file())
    	{
	        ++fileCount;
	    }
	}
	std::cout << " - INITCHECK::TEXTUREMANAGER::GETFILEAMOUNTOFFOLDER::Files loaded: " << fileCount << " at: " << Path << "\n";
	return fileCount;
}

void TextureManager::initTexturesBaseLoop(std::string Path, int key, int size)
{
	std::stringstream s;
	for (int i = 0; i < size; i++)
	{
		s << Path << i << ".png";
		this->tex[key].push_back(new sf::Texture);
		if (!this->tex[key][i]->loadFromFile(s.str()))
			std::cout << " - ERROR::TEXTUREMANAGER::INITTEXTURES::Coulnd't load texture at: " << s.str() << "\n";
		s.clear();
	}
}

void TextureManager::initLightTextures()
{
	this->initTexturesBaseLoop("Textures/blooms/bloom", lights, this->getFileAmountOfFolder("Textures/blooms"));
}

void TextureManager::initSceneryTextures()
{
	this->initTexturesBaseLoop("Textures/scenery/scenery", sceneries, this->getFileAmountOfFolder("Textures/scenery"));
}

void TextureManager::initCropTextures()
{
	this->initTexturesBaseLoop("Textures/crops/crop", crops, this->getFileAmountOfFolder("Textures/crops"));
}

void TextureManager::initSeedTextures()
{
	this->initTexturesBaseLoop("Textures/seeds/seed", seeds, this->getFileAmountOfFolder("Textures/seeds"));
}

void TextureManager::initFieldTextures()
{
	this->initTexturesBaseLoop("Textures/fields/field", fields, this->getFileAmountOfFolder("Textures/fields"));
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
	for (int i = 0; i < fields; i++)
	{
		for (int j = 0; j < this->tex[i].size(); j++)
		{
			this->tex[i].erase(this->tex[i].begin(), this->tex[i].end());
		}
		//Check for deletion
		//std::cout << "TEXTUREMANAGER DESTRUCTOR SIZE OF VECTOR ARRAY IN MAP AT KEY: " << i << " SIZE: " << this->tex[i].size()<<"\n";
	}
}
