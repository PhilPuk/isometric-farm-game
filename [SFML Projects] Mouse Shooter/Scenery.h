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
	sf::Sprite s_Scenery;


	int selectedScenery;

	void initVariables();
	void initStartScenery(sf::Vector2u& winSize, std::vector<sf::Texture*>& t_Sceneries);
public:
	Scenery(std::vector<sf::Texture*>& t_Sceneries, sf::Vector2u& winSize);
	virtual ~Scenery();

	//Accessors

	//Modifiers

		//{MENU = 0, FARM};
	enum keys { MENU = 0, FARM };
	void switchScenery(int& key, std::vector<sf::Texture*>& textures);

	void update();

	void renderSelectedScenery(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};