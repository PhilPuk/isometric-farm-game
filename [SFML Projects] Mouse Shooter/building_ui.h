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

class Building_UI : private baseLayer
{
private:
    std::vector<sf::Sprite*> s_Building;
   // void initVariables();
    void initCreateSprites(std::vector<sf::Texture*> textures);
    void initSpritePositions(sf::Vector2u& winSize, sf::Vector2f bottom_bar_Pos);
public:
    Building_UI(sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f bottom_bar_Pos);
    virtual~Building_UI();

    void update();

    void renderShopButton(sf::RenderTarget& target);
    void renderItems(sf::RenderTarget& target, bool& buildingActivated);
    //void render(sf::RenderTarget& target, bool& buildingActivated);
    
};