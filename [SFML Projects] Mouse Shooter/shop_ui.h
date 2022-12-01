#pragma once

#include<iostream>
#include<vector>
#include<map>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"TextureManager.h"
#include"baseLayer.h"

class Shop_UI :  public baseLayer
{
private:

    void initVariables();
    void initCreateSprites(std::vector<sf::Texture*> textures);
    void initSpritePositions(sf::Vector2u& winSize, sf::Vector2f bottom_bar_Pos);
    void initShopItems(sf::Vector2u& winSize, float popBoxHeight);
    void initSeedClone(sf::Vector2u& winSize);
public:
    Shop_UI(sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f bottom_bar_Pos, float popBoxHeight);
    virtual~Shop_UI();

    sf::Sprite s_SeedClone;
    bool SeedCloneActivated;

    void setSeedCloneTexture(sf::Texture& texture);


    void update();
};