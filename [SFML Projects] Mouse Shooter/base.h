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

class Base_UI : public baseLayer
{
private:
    //Sprite that contains the shop items and building options
    //Is switched over the bools of each class
    sf::Sprite s_popBox;

    void initCreateSprites(std::vector<sf::Texture*> textures) override;
    void initSpritePositions(sf::Vector2u winSize);
    void initPopBox(sf::Vector2u winSize);
public:
    Base_UI(std::vector<sf::Texture*>& textures, sf::Vector2u winSize);
    virtual~Base_UI();

    //Modifiers

    //Chage x position of the popBox
    void setPopBoxXPos(float& x);

    //Change y position of the popBox
    void setPopBoxYPos(float& y);

    //Change Color for clicked on object
    void ActivateClickOnEffect(int index);

    void update();

    void renderPopBox(sf::RenderTarget& target);
};