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
	//Mouse position variables

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	
	//Click time variables

	float mouse_click_puffer;
	float mouse_click_time_reach;

	void initVariables();
public:
	//Constructor / Destrucotr
	Mouse();
	~Mouse();

	//Modifiers
	void set_Mouse_Click_Time_Reach(float current_Application_Time);

	//Accessors
	const sf::Vector2i getMousePosWindow() const;
	const sf::Vector2f getMousePosView() const;
	const bool& getMouseLeftClicked() const;
	const float& get_Mouse_Click_Time_Reach() const;

	//Functions
		//Update
	void updateMousePositions(sf::RenderWindow& window, bool debug);
	void update();
};

