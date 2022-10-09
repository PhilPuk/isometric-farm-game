#pragma once

#include<iostream>
#include<vector>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Tracing
{
private:

	sf::CircleShape box;

	float msgTimeMax;
	float msgTime;

	void initVariables();
	void initBox();
public:
	Tracing();
	virtual ~Tracing();

	std::vector<sf::CircleShape*> traces;

	void createNewTraceBox(const sf::Vector2f& pos);

	void deleteSpecificTrace(int& index);

	void updateCMDMessages();
	void updateOpacity(int& i);
	void updateTraceDeletion(int& i);
	void updateForLoop();
	void update();

	void renderTraces(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

