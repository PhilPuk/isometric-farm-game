#pragma once

#include<iostream>
#include<vector>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>



class Grid
{
private:
//One big vector every cell instead of one each
//Get cutting points for snappoints of tiles

    void initVariables(sf::Vector2u& winSize, sf::Vector2f& tileSize);
    void initSellSize(sf::Vector2u& winSize, sf::Vector2f& tileSize);
    void initCalcSellOutLines(sf::Vector2u& winSize, sf::Vector2f& tileSize);

public:
    Grid(sf::Vector2u& winSize, sf::Vector2f& tileSize);
    virtual~Grid();
};