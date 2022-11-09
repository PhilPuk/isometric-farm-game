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

class Building_UI
{
private:
    std::vector<sf::Sprites*> s_Building;
    void initVariables();
    void initCreateSprites(std::vector<sf::Texture*> textures);
    void initSpritePositions(sf::Vector2u& winSize, , sf::Vector2f bottom_bar_Pos);
public:
    Shop_UI(sf::Vector2u& winSize, std::vector<sf::Texture*> textures, , sf::Vector2f bottom_bar_Pos);
    virtual~Shop_UI();

    void update();

    void renderShopButton(sf::RenderTarget& target);
    void renderItems(sf::RenderTarget& target, bool& buildingActivated);
    void render(sf::RenderTarget& target, bool& buildingActivated);
};