#pragma once

#include<iostream>
#include<map>
#include<vector>

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
	
	bool CheckForObjectClicked(Mouse& mouse, sf::FloatRect& pos);
	void update(Mouse& mouse, std::map<std::string, std::vector<sf::Sprite*>>& ui_objects);

	void render(sf::RenderTarget& target);
};
