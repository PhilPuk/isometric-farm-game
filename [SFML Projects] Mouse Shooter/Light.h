#pragma once

#include<iostream>
#include<time.h>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>


class Light
{
private:
	void initVariables();
	void initSprite(sf::Texture& texture, sf::Vector2f* scale, sf::Vector2f& pos, bool CenterOrigin);
	void initCenter(sf::Vector2f* scale, sf::Vector2f& pos, bool CenterOrigin);
public:
	Light(sf::Texture& texture, sf::Vector2f* scale, sf::Vector2f& pos, bool CenterOrigine);
	virtual ~Light();

	sf::Sprite sprite;
	sf::CircleShape center;

	void moveLight(sf::Vector2f& velocity);

	void renderSprite(sf::RenderTarget& target);
	void renderCenter(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

