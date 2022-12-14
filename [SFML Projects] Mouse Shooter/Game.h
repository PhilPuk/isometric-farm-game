#pragma once

#include<iostream>
#include<memory
#include"time.h"

#include"TextureManager.h"
#include"UI.h"
#include"Shop_Engine.h"
#include"Scenery.h"
#include"Isometric_Square.h"
#include"TileManager.h"
#include"Mouse.h"
#include"Navigation.h"
#include"Timer.h"
#include"FileManagement.h"
#include"Grid.h"

/*
* Class Info:
* Used as wrapper class for the whole game.
* Only the menu is above this class.
*/

/*To-do:
*	Change up normal pointers to smart pointers
		Testing this with grid system
*/

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::Vector2u winSize;

	//FileManager
	FileManagement fileManager;

	//TextureManager
	TextureManager textures;

	//Timer
	Timer timer;

	//UI
	UI* ui;

	//Shop Engine
	ShopEngine shop_e;

	//Events
	sf::Event ev;

	//User Mouse
	Mouse mouse;

	//User navigation system
	Navigation nav;

	//Isometric tiles
	TileManager* t_Manager;

	//End logic
	bool endGame;
	bool endApplication;

	void initWindow(sf::RenderWindow* window);
	void initVariables(sf::RenderWindow* window);
	void initUI(sf::Font& font);
	void initScenery();
	void initTileManager();
	void initGrid();
public:
	Game(sf::RenderWindow* window, sf::Font& font);
	virtual ~Game();

	//Scenery
	Scenery* scenery;

	//Grid system
	std::unique_ptr<Grid> grid;

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

