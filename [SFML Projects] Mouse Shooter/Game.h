#pragma once

#include<iostream>
#include"time.h"

#include"TextureManager.h"
#include"UI.h"
#include"Scenery.h"
#include"Field.h"
#include"FieldManager.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::Vector2u winSize;

	//Events
	sf::Event ev;

	//UI
	UI* ui;

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

	//TextureManager
	TextureManager textures;

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

