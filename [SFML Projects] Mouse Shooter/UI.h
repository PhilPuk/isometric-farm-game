#pragma once

#include"TextureManager.h"
#include"shop_ui.h"
#include"building_ui.h"
#include"baseLayer.h"
#include"base.h"
#include"Navigation.h"

//To-do.
//Move popBox into base ui.
//add modifiers to switch positions on the activated layer.

//Notes:
//baseLayer is the abstract class.
//Shop, building and base inherit of it.

class UI
{
private:
	std::string keys[3] = {"base", "shop", "building"};

	//Navigation
	Navigation nav;
	//Bools for activating modes
	bool baseUIActive;
	bool shopActive;
	bool buildActive;

	//Unter menu für building and shop stuff.
	sf::Sprite s_popBox;

	void initVariables(sf::Vector2u winSize);
	void initBaseLayer(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	void initShop(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	void initBuilding(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
public:
	UI(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	virtual ~UI();

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

	void activateShop();
	void activateBuilding();
	
	void updateNavigation();
	void update();

	void render(sf::RenderTarget& target);
};
