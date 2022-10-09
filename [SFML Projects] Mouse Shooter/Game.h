#pragma once

#include<iostream>
#include"time.h"

#include"TextureManager.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::Vector2u winSize;

	//Events
	sf::Event ev;

	//TextureManager
	TextureManager textures;

	//End logic
	bool endGame;
	bool endApplication;

	void initWindow(sf::RenderWindow* window);
	void initVariables(sf::RenderWindow* window);
public:
	Game(sf::RenderWindow* window);
	virtual ~Game();

	void CloseApplication();
	void resetVariables();

	//Accessors
	const bool& getEndGame() const;
	const bool& getEndApplication() const;

	//Main loop
	void run();

	//Update
	void pollEvents();
	void update();

	//Render
	void render();
};

