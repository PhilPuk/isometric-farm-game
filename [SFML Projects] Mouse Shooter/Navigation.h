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
#include"UI.h"

class Navigation
{
private:
	void initVariables();
public:
	Navigation();
	virtual~Navigation();

	//Accessors
	
	bool CheckForObjectClicked(Mouse& mouse, sf::FloatRect& pos);
	int updateUIBaseLoop(std::vector<sf::Sprites*>& objects);
	void updateMainIconsClicked(UI& ui);
	void updateUI(UI& ui);
	void update(Mouse& mouse, UI& ui);

	void render(sf::RenderTarget& target);
};
