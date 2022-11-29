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
#include"Timer.h"

class Navigation
{
private:
	typedef void(*func)(void);
	void initVariables();
public:
	Navigation();
	virtual~Navigation();

	//Accessors
	
	bool CheckForObjectClicked(Mouse& mouse, sf::FloatRect& pos, Timer& timer);
	int updateUIBaseLoop(std::vector<sf::Sprite*>& objects, Mouse& mouse, Timer& timer);
	void updateIconsClicked(UI& ui, Mouse& mouse, Timer& timer);
	void updateMainIconsClicked(UI& ui, Mouse& mouse, Timer& timer);
	void updateUI(UI& ui, Mouse& mouse, Timer& timer);
	void update(Mouse& mouse, UI& ui, Timer& timer);

	void render(sf::RenderTarget& target);
};
