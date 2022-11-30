#include "UI.h"

bool UI::baseUIActive = true;
bool UI::shopActive = false;
bool UI::buildActive = false;

void UI::initVariables(sf::Vector2u winSize)
{

}

void UI::initBase(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	this->base = new Base_UI(t_Map[TextureManager::ui], winSize);
}

void UI::initShop(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	this->shop = new Shop_UI(winSize, t_Map[TextureManager::shop_icons], sf::Vector2f(0.f,0.f));
}
void UI::initBuilding(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	/*this->base->sprites[0]->getPosition()*/
	this->build = new Building_UI(winSize, t_Map[TextureManager::build_icons], sf::Vector2f(0.f,0.f));
}

void UI::initSizeOfSelections()
{
	//Size of cirlce
	selected.changeRadiusOfCircle(this->shop->sprites[0]->getGlobalBounds().width / 2.f);
	//Y pos of circle
	selected.changePositionYOfSelection(this->shop->sprites[0]->getPosition().y);
}

UI::UI(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	this->initVariables(winSize);
	this->initBase(winSize, t_Map);
	this->initShop(winSize, t_Map);
	this->initBuilding(winSize, t_Map);
	this->initSizeOfSelections();

	//Init pop box first position at shop button location
	float x = this->shop->sprites[0]->getPosition().x;
	float y = this->shop->sprites[0]->getPosition().y;
	this->base->setPopBoxXPos(x);
	this->base->setPopBoxYPos(y);
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

const bool& UI::getbaseUIActive()
{
	return UI::baseUIActive;
}
const bool& UI::getShopActive()
{
	return UI::shopActive;
}
const bool& UI::getBuildActive()
{
	return UI::buildActive;
}

void UI::activateBase()
{
	UI::shopActive = false;
	UI::buildActive = false;
	UI::baseUIActive = true;

	//Deactivated activated labels
}

void UI::activateShop()
{
	UI::shopActive = true;
	UI::buildActive = false;
	UI::baseUIActive = false;

	//New sprite or background that goes to the position of the activated label
}

void UI::activateBuilding()
{
	UI::shopActive = false;
	UI::buildActive = true;
	UI::baseUIActive = false;
}

void UI::update(Mouse& mouse)
{
	this->selected.update();
}

//Render all UI Layers
void UI::render(sf::RenderTarget& target)
{
	this->base->render(target, UI::baseUIActive);
	this->selected.render(target);
	this->shop->render(target, UI::shopActive);
	this->build->render(target, UI::buildActive);
}
