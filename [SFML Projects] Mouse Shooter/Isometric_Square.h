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
	void initSprite(std::vector<sf::Texture*>& texture, sf::Vector2f scale, sf::Vector2f pos);
public:
	Isometric_Square(std::vector<sf::Texture*>& textures, sf::Vector2f spawn_position, sf::Vector2f scaleOfSprite);
	virtual ~Isometric_Square();

	//Ordered by: 0 = BOTTOM , 1 = TOP, 2 = LEFT, 3 = RIGHT.
	sf::Sprite s_Square[4];
	//Ordered by: 0 = BOTTOM , 1 = TOP, 2 = LEFT, 3 = RIGHT.
	bool side_visible[4];

	unsigned char r, g, b;

	void update();

	void renderBottom(sf::RenderTarget& target);
	void renderTop(sf::RenderTarget& target);
	void renderSides(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

