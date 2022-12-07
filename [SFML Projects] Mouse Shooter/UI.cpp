#include "UI.h"

bool UI::baseUIActive = true;
bool UI::shopActive = false;
bool UI::buildActive = false;

void UI::initVariables(sf::Vector2u winSize)
{

}

void UI::initBase(FileManagement& fileManager, sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map, sf::Font& font)
{
	this->base = new Base_UI(t_Map[TextureManager::ui], t_Map[TextureManager::popBoxes], winSize);
}

void UI::initShop(FileManagement& fileManager, sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map, sf::Font& font, ShopEngine& shop_engine)
{
	this->shop = new Shop_UI(fileManager, winSize, t_Map[TextureManager::shop_icons], sf::Vector2f(0.f,0.f), this->base->s_popBox.getGlobalBounds().height, this->base->s_popBox.getGlobalBounds().width, font);
}
void UI::initBuilding(FileManagement& fileManager, sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map, sf::Font& font)
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

UI::UI(FileManagement& fileManager, sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map, sf::Font& font, ShopEngine& shop_engine)
{
	this->initVariables(winSize);
	this->initBase(fileManager, winSize, t_Map, font);
	this->initShop(fileManager, winSize, t_Map, font, shop_engine);
	this->initBuilding(fileManager, winSize, t_Map, font);
	this->initSizeOfSelections();
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

void UI::update(Mouse& mouse, ShopEngine& shop_engine)
{
	this->selected.update();
	this->shop.update(shop_engine);
}


void UI::renderSeedClone(sf::RenderTarget& target)
{
	if(this->shop->SeedCloneActivated)
	target.draw(this->shop->s_SeedClone);
}

//Render all UI Layers
void UI::render(sf::RenderTarget& target)
{
	this->base->render(target, UI::baseUIActive);
	this->selected.render(target);
	this->shop->render(target, UI::shopActive);
	this->build->render(target, UI::buildActive);
	this->renderSeedClone(target);
}
