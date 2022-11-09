#include "UI.h"

void UI::initVariables(sf::Vector2u winSize)
{
	this->baseUIActive = true;
	this->shopActive = false;
	this->buildActive = false;
}

void UI::initSprites(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{ 
	int keyFromString = 0;
	for(int i = TextureManager::ui ; i <= TextureManager::build_icon; i++)
	{
		//Debugging
		//std::cout << "Key: " << this->keys[keyFromString]<<"\n";
		for(int j = 0; j < t_Map[i].size(); j++)
		{
			this->Layers[this->keys[keyFromString]].push_back(new sf::Sprite);
			this->Layers[this->keys[keyFromString]][j]->setTexture(*t_Map[i][j]);
		}
		keyFromString++;
	}
}

void UI::initMainUIPos(sf::Vector2u winSize)
{
	//Init positions of main ui parts
	//
	//Bottom layer
	this->Layers["base"][0]->setPosition(0.f, static_cast<float>(winSize.y) - this->Layers["base"][0]->getGlobalBounds().height);
	//
	//Shop Icon
	this->Layers["shop"][0]->scale(0.3f, 0.3f);
	this->Layers["shop"][0]->setPosition(20.f, static_cast<float>(winSize.y) - this->Layers["base"][0]->getGlobalBounds().height * 0.86f);
	//
	//Build Icon
	this->Layers["building"][0]->scale(0.3f, 0.3f);
	this->Layers["building"][0]->setPosition(20.f * 2 + this->Layers["shop"][0]->getGlobalBounds().width, static_cast<float>(winSize.y) - this->Layers["base"][0]->getGlobalBounds().height * 0.86f);

}

UI::UI(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	this->initVariables(winSize);
	this->initSprites(winSize, t_Map);
	this->initMainUIPos(winSize);
}

UI::~UI()
{
	for(auto& i : keys)
	{
		for(auto&j : this->Layers[i])
		{
			this->Layers[i].erase(this->Layers[i].begin(), this->Layers[i].end());
		}
	}
	std::cout << "Size of UI baseLayer vector array after deleting: " << this->Layers.size() << "\n";
}

const bool& UI::getbaseUIActive() const
{
	return this->baseUIActive;
}
const bool& UI::getShopActive() const
{
	return this->shopActive;
}
const bool& UI::getBuildActive() const
{
	return this->buildActive;
}

void UI::update()
{

}

void UI::renderLoop(sf::RenderTarget& target, std::string& key)
{
	//Renders the element of the map at the given key.
	for (auto& i : this->Layers[key])
	{
		target.draw(*i);
	}
}

void UI::renderBaseLayer(sf::RenderTarget& target)
{
	this->renderLoop(target, this->keys[0]);
}

void UI::renderShopLayer(sf::RenderTarget& target)
{
	//Shop Icon
	target.draw(*this->Layers["shop"][0]);

	if(this->shopActive)
		this->renderLoop(target, this->keys[1]);
}

void UI::renderBuildingLayer(sf::RenderTarget& target)
{
	//Build Icon
	target.draw(*this->Layers["building"][0]);

	if (this->buildActive)
		this->renderLoop(target, this->keys[2]);
}

void UI::render(sf::RenderTarget& target)
{
	this->renderBaseLayer(target);
	this->renderShopLayer(target);
	this->renderBuildingLayer(target);
}
