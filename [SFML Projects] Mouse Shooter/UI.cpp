#include "UI.h"

void UI::initVariables(sf::Vector2u winSize)
{
	this->baseUIActive = true;
	this->shopActive = false;
	this->buildActive = false;
}

void UI::initSprites(sf::Vector2u winSize, std::vector<sf::Texture*> textures)
{ 
	//Get filepath to jump to next key
	for(auto&i : keys)
	{
		for(int j = 0; j < textures.size(); j++)
		{
			this->Layers[i].push_back(new sf::Sprite);
			this->Layers.[i][j].setTexture(*textures[j]);
		}
	}
	for (int i = 0; i < textures.size(); i++)
	{
		this->baseLayer.push_back(new sf::Sprite);
		this->baseLayer[i]->setTexture(*textures[i]);
	}
	//Bottom Bar
	this->baseLayer[0]->setPosition(0.f, static_cast<float>(winSize.y) - this->baseLayer[0]->getGlobalBounds().height);
	//Shop icon
	this->baseLayer[1]->scale(0.3f, 0.3f);
	this->baseLayer[1]->setPosition(20.f, static_cast<float>(winSize.y) - this->baseLayer[0]->getGlobalBounds().height * 0.86f );
	//Build icon
	this->baseLayer[2]->scale(0.3f, 0.3f);
	this->baseLayer[2]->setPosition(20.f * 2 + this->baseLayer[1]->getGlobalBounds().width, static_cast<float>(winSize.y) - this->baseLayer[0]->getGlobalBounds().height * 0.86f);
}

UI::UI(sf::Vector2u winSize, std::vector<sf::Texture*> textures)
{
	this->initVariables(winSize);
	this->initSprites(winSize, textures);
}

UI::~UI()
{
	for (auto& i : baseLayer)
	{
		this->baseLayer.erase(this->baseLayer.begin(), this->baseLayer.end());
	}

	std::cout << "Size of UI baseLayer vector array: " << this->baseLayer.size() << "\n";
}

void UI::update()
{

}

void UI::renderBaseLayer(sf::RenderTarget& target)
{
	for (auto& i : baseLayer)
	{
		target.draw(*i);
	}
}

void UI::render(sf::RenderTarget& target)
{
	this->renderBaseLayer(target);
}
