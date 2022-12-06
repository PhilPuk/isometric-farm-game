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
#include"FileManagement.h"
#include"baseLayer.h"

class Shop_UI :  public baseLayer
{
private:

    float prices[15] = {30,10,15,25,15,35,30,20,5,12,9,18,15,8,19};

    float bank;

    void initVariables();
    void initCreateSprites(std::vector<sf::Texture*> textures);
    void initSpritePositions(sf::Vector2u& winSize, sf::Vector2f bottom_bar_Pos);
    void initItemTexts(FileManagement& fileManager, sf::Vector2u& winSize, sf::Font& font);
    void initShopItems(sf::Vector2u& winSize, float popBoxHeight, float popBoxWidth);
    void initSeedClone(sf::Vector2u& winSize);
public:
    Shop_UI(FileManagement& fileManager, sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f bottom_bar_Pos, float popBoxHeight, float popBoxWidth, sf::Font& font);
    virtual~Shop_UI();

    sf::Sprite s_SeedClone;
    bool SeedCloneActivated;

    //TO DO MOVE INTO SHOP ENGINE CLASS!!!    
    //Modify the texture of the seed icon that can be moved around
    // void setSeedCloneTexture(sf::Texture& texture);
    // void reduceMoneyAfterBuy(float& reduce const);

    //Get the amount of the money the player owns
    const float& getMoneyInBank() const;

    void update();
};