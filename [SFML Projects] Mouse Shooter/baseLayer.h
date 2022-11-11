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

class baseLayer abstract
{
private:
	std::vector<sf::Sprite*> sprites;

	virtual void initVariables();
	virtual void initCreateSprites(std::vector<sf::Texture*> textures);
	virtual void initSpritePositions(sf::Vector2u& winSize, sf::Vector2f bottom_bar_Pos);
public:
	baseLayer(sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f bottom_bar_Pos);
	virtual~baseLayer();

	virtual void update();

	virtual void render(sf::RenderTarget& target, bool& Activated);
};