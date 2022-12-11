#include "TextureManager.h"

void TextureManager::initVariables()
{
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

void TextureManager::initUITextures()
{
	//Base layer stuff
	this->AutoTextureLoader("Textures/ui", ui);
	//Shop layer --> Seed icons
	this->AutoTextureLoader("Textures/ui/shop", shop_icons);
	//Build layer
	this->AutoTextureLoader("Textures/ui/building", build_icons);
}

void TextureManager::initPopBoxes()
{
	this->AutoTextureLoader("Textures/ui/popBox", popBoxes);
}

void TextureManager::initIsometricSquares()
{
	this->AutoTextureLoader("Textures/isometric_squares", isometric_squares);
}

void TextureManager::initTextures()
{
	this->initLightTextures();
	this->initSceneryTextures();
	this->initUITextures();
	this->initPopBoxes();
	this->initIsometricSquares();
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
