#pragma once

#include<stack>

#include"Shop_Engine.h"
#include"Field.h"
#include"Mouse.h"

class FieldManager
{
private:
	sf::Texture t_Field;
	sf::Texture t_Crop;

	void initVariables();
	void initTextures(sf::Texture* t_Field, sf::Texture* t_Crop);
	void initBeginnerField(sf::Vector2u& winSize);
public:
	FieldManager(sf::Vector2u& winSize, sf::Texture* t_Field, sf::Texture* t_Crop);
	virtual~FieldManager();

	bool anyCropisMarked;

	std::vector<Field*> fields;

	sf::Color color_GreenMark;
	sf::Color color_RedMark;
	sf::Color color_baseColor;

	//Called in Navigation update!!!
	void updateMarking(int& i, int& j, Mouse& mouse, static const bool&(&func)(Mouse& mouse, sf::FloatRect object),  ShopEngine& shop_e, int indexOfSeed);
	
	void update();

	void renderFields(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

