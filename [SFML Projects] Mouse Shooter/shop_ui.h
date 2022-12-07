#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"TextureManager.h"
#include"FileManagement.h"
#include"Shop_Engine.h"
#include"baseLayer.h"

class Shop_UI :  public baseLayer
{
private:
    sf::Text text_bank;

    float lastBank;

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
     void setSeedCloneTexture(sf::Texture& texture);

    void updateBankText(float& bank);
    void update(ShopEngine& shop_e);

    void renderBankText(sf::RenderTarget& target);
    void render(sf::RenderTarget& target, bool& activated);
};