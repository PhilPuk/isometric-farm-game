#pragma once

#include<iostream>
#include<vector>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

/*To-do:
*   resize grid lines automatically once the size
*/

class Grid
{
private:
    sf::Vector2f sellSize;
    void initVariables(sf::Vector2u& winSize, sf::Vector2f& tileSize);
    void initSellSize(sf::Vector2u& winSize, sf::Vector2f& tileSize);
    void initCalcSellOutLines(sf::Vector2u& winSize, sf::Vector2f& tileSize, sf::Vector2f& pos);
    std::vector<sf::Vector2f> cellPos;

    Uint16 oldTileAmount;
public:
    Grid(sf::Vector2u& winSize, sf::Vector2f& tileSize, sf::Vector2f& pos);
    virtual~Grid();

    std::vector<std::unique_ptr<sf::RectangleShape>> horizontal_lines;
    std::vector<std::unique_ptr<sf::RectangleShape>> vertical_lines;

    /*  Checks if mouse is in one specific cell.
    *   returns top left corner point of cell.
    */
    sf::Vector2f& getSnapPoint(sf::Vector2f& currentPos);

    void updateCellOutLining(Uint16 tileAmount);

    void renderHorizontal(sf::RenderTarget& target);
    void renderVertical(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
};