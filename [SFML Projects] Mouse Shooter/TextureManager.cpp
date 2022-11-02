#include "TextureManager.h"

void TextureManager::initVariables()
{

}

int TextureManager::getFileAmountOfFolder(std::string Path)
{
	int counter = 0;
	WIN32_FIND_DATAA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	hFind = ::FindFirstFileA(Path.c_str(), &ffd);
	//Iterating over the files in the directory
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			counter++;
		} while (::FindNextFileA(hFind, &ffd) == TRUE);
	}
	else
	{
		std::cout << " - ERROR::TEXTUREMANAGER::GETFILEAMOUNTOFFOLDER::Couldn't find folder:" << Path << "\n";
		return 0;
	}
	return counter;
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
	std::cout<<"File amount of textures: "<<this->getFileAmountOfFolder("C:/Users/Phil/source/repos/[SFML Projects] SFML Template 1.0 - Kopie - Kopie/[SFML Projects] Mouse Shooter/Textures");
}

void TextureManager::initSceneryTextures()
{

}

void TextureManager::initCropTextures()
{

}

void TextureManager::initSeedTextures()
{

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
