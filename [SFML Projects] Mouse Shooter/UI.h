#pragma once

#include"TextureManager.h"
#include"FieldManager.h"
#include"shop_ui.h"
#include"building_ui.h"
#include"base.h"
#include"baseLayer.h"
#include"Mouse.h"
#include"selection_ui.h"
#include"Shop_Engine.h"

//Notes:
//baseLayer is the abstract class.
//Shop, building and base inherit of it.

class UI
{
private:
	std::string keys[3] = {"base", "shop", "building"};

	//Bools for activating modes
	static bool baseUIActive;
	static bool shopActive;
	static bool buildActive;

	void initVariables(sf::Vector2u winSize);
	void initBase(FileManagement& fileManager, sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map, sf::Font& font);
	void initShop(FileManagement& fileManager, sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map, sf::Font& font, ShopEngine& shop_engine);
	void initBuilding(FileManagement& fileManager, sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map, sf::Font& font);
	void initSizeOfSelections();
public:
	UI(FileManagement& fileManager,sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map, sf::Font& font, ShopEngine& shop_engine);
	virtual ~UI();

	//Class for visual apperance of selected / clicked on items, icons whatever.
	Selection selected;
	//Base UI Class.
	Base_UI* base;
	//Shop UI Class.
	Shop_UI* shop;
	//Building UI Class.
	Building_UI* build;

	//Accessors

	//Key list { base = 0, shop = 1, building = 2}.
	const std::string& getKey(int index);
	static const bool& getbaseUIActive();
	static const bool& getShopActive();
	static const bool& getBuildActive();

	//Modifiers

	static void activateBase();
	static void activateShop();
	static void activateBuilding();
	
	void update(Mouse& mouse, ShopEngine& shop_engine);

	void render(sf::RenderTarget& target);
};
