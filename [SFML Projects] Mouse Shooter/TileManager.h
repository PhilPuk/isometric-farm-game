#pragma once

#include"Isometric_Square.h"
#include"TextureManager.h"
#include"Mouse.h"

class TileManager
{
private:
    void initVariables();
    void initTiles(std::map<int, std::vector<sf::Texture*>>& texture_map);
    void initStartWorld(int start_world_size);
    void initViews(sf::RenderTarget& target);
    sf::View v_Manipulated_to_Isometric;

    int indexOfTile;
public:
    std::vector<Isometric_Square*> tiles; 
    TileManager(std::map<int, std::vector<sf::Texture*>>& texture_map, int start_world_size, sf::RenderTarget& target);
    virtual~TileManager();

    void addNewTile(std::vector<sf::Texture*>& textures, sf::Vector2f pos);

    /*Algorithms thoughts:
    *Check sorrounding tiles 
    *Implement grid system
    */

    void updateTileMovement(Mouse& mouse);

    void updateBottomVisibility();
    void updateTopVisibility();
    void updateFrontVisibility();
    void updateVisibility();

    void update(Mouse& mouse);
    
    void renderManipulateView(sf::RenderTarget& target);
    void renderResetView(sf::RenderTarget& target);
    void renderAllBottomsSides(sf::RenderTarget& target);
    void renderAllTopSides(sf::RenderTarget& target);
    void renderFrontSides(sf::RenderTarget& target);
    void renderMovedTile(sf::RenderTarget& target);
    void renderAllTiles(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
};
