#pragma once

#include<iostream>
#include<vector>
#include<map>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"baseLayer.h"

class Base_UI : virtual private baseLayer
{
private:
    //Sprite that contains the shop items and building options
    //Is switched over the bools of each class
    sf::Sprite s_popBox;

    void initSpritePositions(sf::Vector2u winSize);
    void initPopBox(sf::Vector2f winSize);
public:
    Base_UI(std::vector<sf::Texture*>& textures, sf::Vector2u winSize);
    virtual~Base_UI();

    //Modifiers
    void setPopBoxXPos(float& x);

    void update();
}