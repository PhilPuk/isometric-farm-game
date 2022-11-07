#pragma once

#include<iostream>
#include<vector>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class UI
{
private:
	std::vector<sf::Sprite*> baseLayer;

	void initVariables(sf::Vector2u winSize);
	void initSprites(sf::Vector2u winSize, std::vector<sf::Texture*> textures);
public:
	UI(sf::Vector2u winSize, std::vector<sf::Texture*> textures);
	virtual ~UI();

	template<class T>
		void centerOrigin(T x);
	
	void update();

	void renderBaseLayer(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

template<class T>
inline void UI::centerOrigin(T x)
{
	sf::FloatRect rect = x.getLocalBounds();
	x.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
}
