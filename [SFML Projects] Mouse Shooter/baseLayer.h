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
	virtual void initVariables();
	virtual void initCreateSprites(std::vector<sf::Texture*> textures);
	virtual void initSpritePositions(sf::Vector2u& winSize, sf::Vector2f Pos, sf::Vector2f scale);
public:
	baseLayer();
	baseLayer(sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f Pos, sf::Vector2f scale);
	virtual~baseLayer();

	std::vector<sf::Text*> texts;
	std::vector<sf::Sprite*> sprites;

	virtual void update();

	virtual void renderBaseIcon(sf::RenderTarget& target);
	virtual void renderItems(sf::RenderTarget& target);
	void renderTexts(sf::RenderTarget& target);
	virtual void render(sf::RenderTarget& target, bool& Activated);
};