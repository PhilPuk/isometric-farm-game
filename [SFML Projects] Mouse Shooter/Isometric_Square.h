#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Isometric_Square
{
private:
	void initVariables();
	void initTexture(sf::Texture& texture);
	void initSpriteScale(sf::Vector2f scale);
	void initSpritePos(sf::Vector2f pos);
	void initSprite(sf::Texture& texture, sf::Vector2f scale, sf::Vector2f pos);
public:
	Isometric_Square(sf::Texture& texture_of_square, sf::Vector2f spawn_position, sf::Vector2f scaleOfSprite);
	virtual ~Isometric_Square();

	sf::Sprite s_Square;


	void update();

	void renderSquare(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);

	// For testing!!!
	sf::Sprite s_new;
	void initTestingSquare();
	void renderNew(sf::RenderTarget& target);
};

