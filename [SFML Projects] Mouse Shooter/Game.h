#pragma once

#include<iostream>
#include"time.h"

#include"TextureManager.h"
#include"UI.h"
#include"Scenery.h"
#include"Field.h"
#include"FieldManager.h"
#include"Mouse.h"
#include"Navigation.h"
#include"Timer.h"

/*
* Class Info:
* Used as wrapper class for the whole game.
* Only the menu is above this class.
*/

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::Vector2u winSize;

	//TextureManager
	TextureManager textures;

	//Timer
	Timer timer;

	//UI
	UI* ui;

	//Events
	sf::Event ev;

	//User Mouse
	Mouse mouse;

	//User navigation system
	Navigation nav;

	//FieldManager
	FieldManager* f_Manager;

	//End logic
	bool endGame;
	bool endApplication;

	void initWindow(sf::RenderWindow* window);
	void initVariables(sf::RenderWindow* window);
	void initUI();
	void initScenery();
	void initf_Manager();
public:
	Game(sf::RenderWindow* window);
	virtual ~Game();

	//Scenery
	Scenery* scenery;

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

