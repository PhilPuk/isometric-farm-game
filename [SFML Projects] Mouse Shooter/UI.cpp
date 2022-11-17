#include "UI.h"

void UI::initVariables(sf::Vector2u winSize)
{
	this->baseUIActive = true;
	this->shopActive = false;
	this->buildActive = false;
}

void initShop(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	//this->shop = new Shop_UI(winSize, t_Map, )
	this->shop = new Shop_UI(winSize, t_Map[Texturemanager::shop_icons]);
}
void initBuilding(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	this->build = new building_UI(winSize, t_Map[TextureManager::building_icons]);
}

UI::UI(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	this->initVariables(winSize);
	this->initSprites(winSize, t_Map);
	this->initMainUIPos(winSize);
	this->initBaseLayer(winSize, t_Map);
	this->initShop(winSize);
	this->initBuilding(winSize);
}

UI::~UI()
{
	delete this->shop;
	delete this->building;
	delete this->base;
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

void UI::updateNavigation()
{
	this->nav.update();

	//Check clicked ui icons
	for(auto& i : this->shop->sprites)
	{
		if(this->nav.CheckForObjectClicked(i.getGlobalBounds()))
		this->base->ActivateClickOnEffect();
	}
}

void UI::update()
{
	this->updateNavigation();
}

void UI::render(sf::RenderTarget& target)
{
	this->base->render(target);
	this->shop->render(target);
	this->building->render(target);
}
