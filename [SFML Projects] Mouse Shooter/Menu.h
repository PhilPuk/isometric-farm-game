#pragma once

#include<iostream>
#include<string>

#include"Mouse.h"
#include"Game.h"


class Menu
{
private:
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	std::string Application_Title;
	int Framerate;

	//Fonts
	sf::Font font;

	//Texts
	sf::Text Text_Title;
	sf::Text Text_Menu_Options[3];
	sf::Color Color_Menu;
	sf::Color Color_Menu_Selected;
	sf::Vector2f Vector_Menu_Pos;
	float Spacing_Menu_Pos_Y;

	//Menu_Navigation
	short Menu_Navigation_Index;
	bool Navigation_Index_Changed;

	//Game
	Game* game;

	//Private functions
		//Menu_Navigation
	void navigateUP();
	void navigateDOWN();
	 
		//Initilalization
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initGame();

	//Mouse
	Mouse mouse;
public:
	//Constructor / Destructor
	Menu();
	~Menu();

	//Functions
	void run();
	void EventEnterPressed(sf::Event& ev);
	void EventMenuNavigation(sf::Event& ev);
	void pollEventsKeyPressed(sf::Event& ev);
	void pollEvents();
		//update
	void updateText();
	void udpate();
		//render
	void renderText();
	void render();
};

