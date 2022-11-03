#pragma once
#include<iostream>
#include<map>
#include<string>
#include<vector>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Scenery
{
private:
	//std::map<int, sf::Texture&> t_Sceneries;

	sf::Sprite s_Scenery;

	//std::string SCENERIES_KEYS[2] = {"MENU", "FARM"};
	enum keys {MENU = 0, FARM};
	int selectedScenery;

	void initVariables();
	void initTextures(std::vector<sf::Texture>& t_Sceneries);
public:
	Scenery(std::vector<sf::Texture>& t_Sceneries);
	virtual ~Scenery();

	//Accessors

	//Modifiers

	void switchScenery(int& key);

	void update();

	void renderSelectedScenery(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};