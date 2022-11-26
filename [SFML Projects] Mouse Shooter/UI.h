#pragma once

#include"TextureManager.h"
#include"shop_ui.h"
#include"building_ui.h"
#include"base.h"
#include"baseLayer.h"
#include"Mouse.h"
#include"selection_ui.h"

//Notes:
//baseLayer is the abstract class.
//Shop, building and base inherit of it.

class UI
{
private:
	std::string keys[3] = {"base", "shop", "building"};

	//Bools for activating modes
	bool baseUIActive;
	bool shopActive;
	bool buildActive;

	void initVariables(sf::Vector2u winSize);
	void initBase(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	void initShop(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	void initBuilding(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	void initSizeOfSelections();
public:
	UI(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
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
	const bool& getbaseUIActive() const;
	const bool& getShopActive() const;
	const bool& getBuildActive() const;

	//Modifiers

	void activateBase();
	void activateShop();
	void activateBuilding();
	
	void update(Mouse& mouse);

	void render(sf::RenderTarget& target);
};
