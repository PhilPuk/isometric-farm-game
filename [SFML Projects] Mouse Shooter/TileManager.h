#pragma once

class TileManager
{
private:
    void initVariables();
    void initTiles(std::map<int, std::vector<sf::Texture*>>& texture_map)
    void initStartWorld(int start_world_size);
public:
    std::vector<Isometric_Square*> tiles; 
    TileManager(std::map<int, std::vector<sf::Texture*>>& texture_map, int start_world_size);
    virtual~TileManager();

    void updateBottomVisibility();
    void updateTopVisibility();
    void updateFrontVisibility();
    void updateVisibility();
    
    void renderAllBottomsSides(sf::RenderTarget& target);
    void renderAllTopSides(sf::RenderTarget& target);
    void renderFrontSides(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
};