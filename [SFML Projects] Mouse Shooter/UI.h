#pragma once

#include<iostream>
#include<vector>
#include<map>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"TextureManager.h"
#include"shop_ui.h"
#include"building_ui.h"
#include"baseLayer.h"

//Fix base ui abstraction class for inheritance.
//google: overwrite functions, keyword abstract, keyword virtual
//bzw. altem projekt inheritance abschauen!

class UI
{
private:
	std::string keys[3] = {"base", "shop", "building"};

	//Bools for activating modes
	bool baseUIActive;
	bool shopActive;
	bool buildActive;

	//Unter menu für building and shop stuff.
	sf::Sprite s_popBox;

	void initVariables(sf::Vector2u winSize);
	void initSprites(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	void initMainUIPos(sf::Vector2u winSize);
	void initPopBox(sf::Vector2u winSize);
	void initBaseLayer(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	void initShop(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	void initBuilding(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
public:
	UI(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	virtual ~UI();

	//Shop UI Class.
	Shop_UI shop;
	//Building UI Class.
	Building_UI build;

	//Accessors

	//Key list { base = 0, shop = 1, building = 2}.
	const std::string& getKey(int index);
	const bool& getbaseUIActive() const;
	const bool& getShopActive() const;
	const bool& getBuildActive() const;

	//Modifiers

	void activateShop();
	void activateBuilding();
	
	void updatePopBoxPos();
	void update();

	void renderLoop(sf::RenderTarget& target, std::string& key);
	void renderBaseLayer(sf::RenderTarget& target);
	void renderPopBox(sf::RenderTarget& target);
	void renderShopLayer(sf::RenderTarget& target);
	void renderBuildingLayer(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};
