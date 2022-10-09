#pragma once

#include<iostream>
#include<map>

#include"Light.h"
#include"Tracing.h"

class LightManager
{
private:

	bool keyPressed;

	//std::map<std::string, sf::Texture> textures;
	sf::Texture texture;

	//tracing
	//Tracing tracing;

	//Scaling Animation
	bool scale;
	float scaleMax;
	float scaleAmount;

	void initVariables();
	void initTextures(sf::Texture& texture);
	void initPreSpawnedLights(int amount);
public:
	LightManager(sf::Texture& texture);
	virtual ~LightManager();

	//LIGHTS
	std::vector<Light*> lights;
	std::vector<sf::Vector2f> velocity;

	//Create a new light with pre defined settings
	void newLight();
	void newVelocity();
	void SpawnOnEnterPressed();
	
	void updateMovement(int& i);
	void updateLightCollisionWall(int& i, sf::Vector2u& winSize);
	void updateScalingOfLights(int& i);
	void updateForLoop(sf::Vector2u& winSize);
	void update(sf::Vector2u& winSize);

	void renderLights(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

