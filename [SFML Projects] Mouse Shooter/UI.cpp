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
	//Bottom bar
	this->Layers["base"][0]->setPosition(0.f, static_cast<float>(winSize.y) - this->Layers["base"][0]->getGlobalBounds().height);

}

void initBaseLayer(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{

}

void initPopBox(sf::Vector2u winSize)
{
	//this->s_popBox.setPosition(this->shop)
}

void initShop(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	//this->shop = new Shop_UI(winSize, t_Map, )
}
void initBuilding(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{

}

UI::UI(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	this->initVariables(winSize);
	this->initSprites(winSize, t_Map);
	this->initMainUIPos(winSize);
	this->initShop(winSize);
	this->initBuilding(winSize);
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

const std::string& UI::getKey(int index)
{
	return this->keys[index];
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

void UI::activateShop()
{
	this->shopActive = true;
	this->buildActive = false;
	this->baseUIActive = false;
}
void UI::activateBuilding()
{
	this->shopActive = false;
	this->buildActive = true;
	this->baseUIActive = false;
}

void UI::updatePopBoxPos()
{
	//if(!this->baseUIActive)
	//{
	//	if(this->shopActive)
	//	this->s_popBox.setPosition(this->Layers["shop"][0].getPosition().x, this->Layers["shop"][0].getPosition().y - this->s_popBox.getGlobalBounds().height);
	//	else
	//	this->s_popBox.setPosition(this->Layers["building"][0].getPosition().x, this->Layers["building"][0].getPosition().y - this->s_popBox.getGlobalBounds().height);
	//}
}

void UI::update()
{
	this->updatePopBoxPos();
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

void UI::renderPopBox(sf::RenderTarget& target)
{
	target.draw(this->s_popBox);
}

void UI::renderShopLayer(sf::RenderTarget& target)
{
	//Shop Icon
	target.draw(*this->Layers["shop"][0]);

	if(this->shopActive)
	{
		target.draw(this->s_popBox);
		this->renderLoop(target, this->keys[1]);
	}
}

void UI::renderBuildingLayer(sf::RenderTarget& target)
{
	//Build Icon
	target.draw(*this->Layers["building"][0]);

	if (this->buildActive)
	{
		target.draw(this->s_popBox);
		this->renderLoop(target, this->keys[2]);
	}
}

void UI::render(sf::RenderTarget& target)
{
	this->renderBaseLayer(target);
	this->renderPopBox(target);
	this->renderShopLayer(target);
	this->renderBuildingLayer(target);
}
