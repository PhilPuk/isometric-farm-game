#pragma once

#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class UI
{
private:

public:
	UI(sf::Vector2u winSize);
	virtual ~UI();

	void update();

	void render(sf::RenderTarget& target);
};

