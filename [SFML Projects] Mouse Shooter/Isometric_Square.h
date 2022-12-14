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

//Update to the new tile system
//Build it like a cube two times the s_new sprite for top and bottom.
//Two squares tiles for the left and right face

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

	//Ordered by: 0 = BOTTOM , 1 = TOP, 2 = LEFT, 3 = RIGHT.
	sf::Sprite s_Square[4];
	//Ordered by: 0 = BOTTOM , 1 = TOP, 2 = LEFT, 3 = RIGHT.
	bool side_visible[4];

	void update();

	void renderSides(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);

	// For testing!!!
	sf::Sprite s_new;
	void initTestingSquare();
	void renderNew(sf::RenderTarget& target);
};

