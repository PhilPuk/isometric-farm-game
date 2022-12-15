#include"TileManager.h"

void TileManager::initVariables()
{

}

void TileManager::initTiles(std::map<int, std::vector<sf::Texture*>>& texture_map)
{

}

void TileManager::initStartWorld(int start_world_size)
{

}


void TileManager::initViews(sf::RenderTarget& target)
{
    //Isometric view for tiles
    this->v_Manipulated_to_Isometric = target.getDefaultView();
	v.setSize(v.getSize().x, v.getSize().y * 2);
	v.setCenter(v.getSize() * .5f);
}

TileManager::TileManager(std::map<int, std::vector<sf::Texture*>>& texture_map, int start_world_size, sf::RenderTarget& target)
{
    this->initVariables();
    this->initTiles(texture_map);
    this->initStartWorld(start_world_size);
    this->initViews(target);
}

TileManager::~TileManager()
{
    for(auto i : this->tiles)
    {
        this->tiles.erase(this->tiles.begin(), this->tiles.end());
    }
}

//To-do
//Algorithm to get if the part of the tile is visible or not.
void TileManager::updateBottomVisibility()
{

}

void TileManager::updateTopVisibility()
{

}

void TileManager::updateFrontVisibility()
{

}

void TileManager::updateVisibility()
{

}

void TileManager::renderManipulateView(sf::RenderTarget& target)
{
	target.setView(v);
}

void TileManager::renderResetView(sf::RenderTarget& target)
{
    target.setView(target.getDefaultView());
}
    
void TileManager::renderAllBottomsSides(sf::RenderTarget& target)
{
    for(auto& i : this->tiles)
    {
        i.renderBottom(target);
    }
}

void TileManager::renderAllTopSides(sf::RenderTarget& target)
{
    for(auto& i : this->tiles)
    {
        i.renderTop(target);
    }
}

void TileManager::renderFrontSides(sf::RenderTarget& target)
{
    for(auto& i : this->tiles)
    {
        i.renderSides(target);
    }
}

void TileManager::renderAllTiles(sf::RenderTarget& target)
{
    this->renderAllBottomsSides(target);
    this->renderFrontSides(target);
    this->renderAllTopSides(target);
}

void TileManager::render(sf::RenderTarget& target)
{
    this->renderAllTiles(target);
}
