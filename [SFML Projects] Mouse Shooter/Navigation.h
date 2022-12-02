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
#include"TextureManager.h"
#include"UI.h"
#include"Timer.h"

class Navigation
{
private:
	void initVariables();
public:
	Navigation();
	virtual~Navigation();

	//Accessors
	
	bool CheckForObjectClicked(Mouse& mouse, sf::FloatRect& pos, Timer& timer);
	void updateShopItemsMoved(Mouse& mouse, Timer& timer, UI& ui, std::vector<sf::Texture*>& textures);
	void updateShopOrBuildPressedTemplate(UI& ui, Mouse& mouse, Timer& timer, sf::Vector2f pos, void(&activate)(), const bool& (&getActive)(), sf::Sprite*& sprite);
	void updateShopOrBuildPressed(UI& ui, Mouse& mouse, Timer& timer);
	void updateUI(UI& ui, Mouse& mouse, Timer& timer);
	void update(Mouse& mouse, UI& ui, Timer& timer, std::vector<sf::Texture*>& textures);

	void render(sf::RenderTarget& target);
};
