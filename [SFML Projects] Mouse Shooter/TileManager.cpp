#include"TileManager.h"

void TileManager::initVariables()
{
    this->indexOfTile = -1;
}

void TileManager::initTiles(std::map<int, std::vector<sf::Texture*>>& texture_map)
{
    this->addNewTile(texture_map[TextureManager::isometric_squares], sf::Vector2f(500.f, 250.f));
    this->addNewTile(texture_map[TextureManager::isometric_squares], sf::Vector2f(this->tiles[0]->s_Square[1].getPosition().x + this->tiles[0]->s_Square[1].getGlobalBounds().width / 2.f, this->tiles[0]->s_Square[1].getPosition().y + this->tiles[0]->s_Square[1].getGlobalBounds().height / 2.f + 9.f));
}

void TileManager::initStartWorld(int start_world_size)
{

}


void TileManager::initViews(sf::RenderTarget& target)
{
    //Isometric view for tiles
    this->v_Manipulated_to_Isometric = target.getDefaultView();
	this->v_Manipulated_to_Isometric.setSize(this->v_Manipulated_to_Isometric.getSize().x, this->v_Manipulated_to_Isometric.getSize().y * 2);
	this->v_Manipulated_to_Isometric.setCenter(this->v_Manipulated_to_Isometric.getSize() * .5f);
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

void TileManager::addNewTile(std::vector<sf::Texture* >& textures, sf::Vector2f pos)
{
    tiles.push_back(new Isometric_Square(textures, pos, sf::Vector2f(1.f, 1.f)));
}

void TileManager::updateTileMovement(Mouse& mouse)
{
    if (mouse.getMouseLeftClicked())
    {
        sf::Vector2f pos = mouse.getMousePosView();
        if (this->indexOfTile == -1)
        {

            for (int i = 0; i < this->tiles.size(); i++)
            {
                if (this->tiles[i]->getBoundsContain(&pos))
                {
                    this->tiles[i]->setPosition(pos);
                    this->indexOfTile = i;
                    mouse.set_Mouse_Held();
                }
            }
        }
        else
        {
            if (mouse.getMouseHeld())
                this->tiles[this->indexOfTile]->setPosition(pos);
            else
                this->indexOfTile = -1;
        }
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
    /*Main Ideas:
    *Check if there is another one the the left or/and right
    *Check if one above or/and below
    *
    */
}

void TileManager::update(Mouse& mouse)
{
    this->updateTileMovement(mouse);
}

void TileManager::renderManipulateView(sf::RenderTarget& target)
{
	target.setView(this->v_Manipulated_to_Isometric);
}

void TileManager::renderResetView(sf::RenderTarget& target)
{
    target.setView(target.getDefaultView());
}
    
void TileManager::renderAllBottomsSides(sf::RenderTarget& target)
{
    for(auto& i : this->tiles)
    {
        i->renderBottom(target);
    }
}

void TileManager::renderAllTopSides(sf::RenderTarget& target)
{
    for(auto& i : this->tiles)
    {
        i->renderTop(target);
    }
}

void TileManager::renderFrontSides(sf::RenderTarget& target)
{
    for(auto& i : this->tiles)
    {
        i->renderSides(target);
    }
}

void TileManager::renderAllTiles(sf::RenderTarget& target)
{
    this->renderFrontSides(target);
    this->renderManipulateView(target);
    //this->renderAllBottomsSides(target);
    this->renderAllTopSides(target);
    this->renderResetView(target);

    //Renders tile that is getting moved above all other ones
    if (this->indexOfTile >= 0)
    {
        this->tiles[this->indexOfTile]->render(target);
    }
}

void TileManager::render(sf::RenderTarget& target)
{
    this->renderAllTiles(target);
}
