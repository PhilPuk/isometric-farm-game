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

//Maybe split into seperate classes
//Shop class included in ui
//Building class included in ui
//Gives better overview
//maybe change it to one base class that everyone inherit from

class UI
{
private:
	std::map<std::string, std::vector<sf::Sprite*>> Layers;
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
	void initShop(sf::Vector2u winSize);
	void initBuilding(sf::Vector2u winSize);
public:
	UI(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	virtual ~UI();


	//Accessors

	//Key list { base = 0, shop = 1, building = 2};
	const std::string& getKey(int index);
	const bool& getbaseUIActive() const;
	const bool& getShopActive() const;
	const bool& getBuildActive() const;
	const sf::FloatRect& getRectofMapElement(std::string& key, int index);

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
