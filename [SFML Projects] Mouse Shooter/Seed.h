#pragma once
#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Seed
{
private:
	sf::Sprite s_OnCrop;
	sf::CircleShape cSh_Icon;

	void initVariables();
	void init_s_OnCrop(sf::Texture& t_OnCrop, sf::Vector2f pos);
	void init_cSh_Pic(sf::Texture& t_Pic, sf::Vector2f pos);
	void initSprites(sf::Texture& t_OnCrop, sf::Texture& t_Pic, sf::Vector2f pos);
public:
	Seed(sf::Texture& t_OnCrop, sf::Texture& t_Pic, sf::Vector2f pos);
	virtual ~Seed();

	void renderIcon(sf::RenderTarget& target);
	void renderOnCroop(sf::RenderTarget& target);
};

