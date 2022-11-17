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
			//std::cout << entry.path() << "\n";
	    }
	}
	std::cout << " - INITCHECK::TEXTUREMANAGER::GETFILEAMOUNTOFFOLDER::Files loaded: " << fileCount << " at: " << Path << "\n";
	return fileCount;
}

void TextureManager::AutoTextureLoader(std::string Path, int key)
{
	auto dirIter = std::filesystem::directory_iterator(Path);
	int fileCount = 0;

	for (auto& entry : dirIter)
	{
		if (entry.is_regular_file())
		{
			this->tex[key].push_back(new sf::Texture);
			this->tex[key][fileCount]->loadFromFile(entry.path().string());
			++fileCount;
		}
	}
	std::cout << " - INITCHECK::TEXTUREMANAGER::GETFILEAMOUNTOFFOLDER::Files loaded: " << fileCount << " at: " << Path << "\n";
}

void TextureManager::initLightTextures()
{
	this->AutoTextureLoader("Textures/blooms", lights);
}

void TextureManager::initSceneryTextures()
{
	this->AutoTextureLoader("Textures/scenery", sceneries);
}

void TextureManager::initCropTextures()
{
	this->AutoTextureLoader("Textures/crops", crops);
}

void TextureManager::initSeedTextures()
{
	this->AutoTextureLoader("Textures/seeds/onField", seeds);
}

void TextureManager::initFieldTextures()
{
	this->AutoTextureLoader("Textures/fields", fields);
}

void TextureManager::initUITextures()
{
	//Base layer stuff
	this->AutoTextureLoader("Textures/ui", ui);
	//Shop layer --> Seed icons
	this->AutoTextureLoader("Textures/ui/shop", seeds);
	//Build layer
	this->AutoTextureLoader("Textures/ui/building", build_icons);
}

void TextureManager::initTextures()
{
	this->initLightTextures();
	this->initSceneryTextures();
	this->initCropTextures();
	this->initSeedTextures();
	this->initFieldTextures();
	this->initUITextures();
}

TextureManager::TextureManager()
{
	this->initVariables();
	this->initTextures();
}

TextureManager::~TextureManager()
{
	for (int i = 0; i < this->tex.size(); i++)
	{
		for (int j = 0; j < this->tex[i].size(); j++)
		{
			this->tex[i].erase(this->tex[i].begin(), this->tex[i].end());
		}
		//Check for deletion
		std::cout << "TEXTUREMANAGER DESTRUCTOR SIZE OF VECTOR ARRAY IN MAP AT KEY: " << i << " SIZE: " << this->tex[i].size()<<"\n";
	}
}
