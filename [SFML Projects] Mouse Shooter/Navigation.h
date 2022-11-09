#pragma once

#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"Mouse.h"

class Navigation
{
private:
	void initVariables();
public:
	Navigation();
	virtual~Navigation();

	//Accessors
	

	void update(Mouse& mouse);

	void render(sf::RenderTarget& target);
};
