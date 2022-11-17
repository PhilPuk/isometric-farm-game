#include "UI.h"

void UI::initVariables(sf::Vector2u winSize)
{
	this->baseUIActive = true;
	this->shopActive = false;
	this->buildActive = false;
}

void UI::initBase(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	this->base = new Base_UI(t_Map[TextureManager::ui], winSize);
}

void UI::initShop(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	//this->shop = new Shop_UI(winSize, t_Map, )
	this->shop = new Shop_UI(winSize, t_Map[TextureManager::shop_icons], sf::Vector2f(0.f,0.f));
}
void UI::initBuilding(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	this->build = new Building_UI(winSize, t_Map[TextureManager::build_icons], this->base->sprites[0]->getPosition());
}

UI::UI(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	this->initVariables(winSize);
	this->initBase(winSize, t_Map);
	this->initShop(winSize, t_Map);
	this->initBuilding(winSize, t_Map);
}

UI::~UI()
{
	delete this->shop;
	delete this->build;
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

void UI::updateNavigation(Mouse& mouse)
{
	//this->nav.update();

	//Check clicked ui icons
	for (size_t i = 0; i < this->shop->sprites.size(); i++)
	{
		sf::FloatRect s = this->shop->sprites[i]->getGlobalBounds();
		if (this->nav.CheckForObjectClicked(mouse, s))
			this->base->ActivateClickOnEffect(i);
	}
}

void UI::update(Mouse& mouse)
{
	this->updateNavigation(mouse);
}

void UI::render(sf::RenderTarget& target)
{
	this->base->render(target, this->baseUIActive);
	this->shop->render(target, this->shopActive);
	this->build->render(target, this->buildActive);
}
