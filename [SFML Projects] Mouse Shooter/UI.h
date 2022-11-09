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

class UI
{
private:
	std::map<std::string, std::vector<sf::Sprite*>> Layers;
	std::string keys[3] = {"base", "shop", "building"};

	//Bools for activating modes
	bool baseUIActive;
	bool shopActive;
	bool buildActive;

	void initVariables(sf::Vector2u winSize);
	void initSprites(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	void initMainUIPos(sf::Vector2u winSize);
public:
	UI(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map);
	virtual ~UI();

	//Accessors
	const bool& getbaseUIActive() const;
	const bool& getShopActive() const;
	const bool& getBuildActive() const;
	
	void update();

	void renderLoop(sf::RenderTarget& target, std::string& key);
	void renderBaseLayer(sf::RenderTarget& target);
	void renderShopLayer(sf::RenderTarget& target);
	void renderBuildingLayer(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};
