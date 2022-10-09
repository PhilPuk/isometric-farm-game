#pragma once

#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>


class Mouse
{
private:
	//Private functions

	//Mouse variables
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

public:
	//Constructor / Destrucotr
	Mouse();
	~Mouse();

	//Accessors
	const sf::Vector2i getMousePosWindow() const;
	const sf::Vector2f getMousePosView() const;

	//Modifiers


	//Functions
		//Update
	void updateMousePositions(sf::RenderWindow& window, bool debug);
	void update();
};

