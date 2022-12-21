void Grid::initVariables(sf::Vector2u& winSize, sf::Vector2f& tileSize)
{
    this->oldTileAmount = 1;
}

void Grid::initSellSize(sf::Vector2u& winSize, sf::Vector2f& tileSize)
{
    this->sellSize = tileSize;

}

void Grid::initCalcSellOutLines(sf::Vector2u& winSize, sf::Vector2f& tileSize, sf::Vector2f& pos)
{
    for(int i = 0; i < 2; i++)
    {
    this->horizontal_lines.push_back(new sf::RectangleShape);
    this->vertical_lines.push_back(new sf::RectangleShape);
    this->horizontal_lines[i].setPosition(pos.x + tileSize.x * (i+1), pos.y + tileSize.y * (i+1));
    this->vertical_lines[i].setPosition(pos.x + tileSize.x * (i+1), pos.y+ tileSize.y * (i+1));
    this->horizontal_lines[i].setRotation(45);
    this->vertical_lines[i].setRotation(45);
    }
}

Grid::Grid(sf::Vector2u& winSize, sf::Vector2f& tileSize, sf::Vector2f& pos)
{
    this->initVariables(winSize, tileSize);
    this->initSellSize(winSize, tileSize);
    this->initCalcSellOutLines(winSize, tileSize);
}

Grid::~Grid()
{

}

sf::Vector2f& Grid::getSnapPoint(sf::Vector2f& currentPos) 
{
    for(int i = 0; i < this->horizontal_lines.size(); i++)
    {
        if(
            currentPos.x >= this->horizontal_lines[i].getPosition().x + this->tileSize.x &&
            currentPos.x <= this->horizontal_lines[i].getPosition().x &&
            currentPos.y >= this->vertical_lines[i].getPosition().y + this->tileSize.y &&
            currentPos.y <= this->vertical_lines[i].getPosition().y
        )
        {
            return sf::Vector2f(this->horizontal_lines[i].getPosition().x, this->vertical_lines[i].getPosition().y);
        }
    }
}


void Grid::updateCellOutLining(Uint16 tileAmount)
{
    if(this->oldTileAmount != tileAmount)
    {
        this->oldTileAmount = tileAmount;
        for(auto& i : tileAmount)
        {  
            //Create calc formula
        }
    }
}

void Grid::renderHorizontal(sf::RenderTarget& target)
{
    for(auto& i : this->horizontal_lines)
    {
        traget.draw(*i);
    }
}

void Grid::renderVertical(sf::RenderTarget& target)
{
    for(auto& i : this->vertical_lines)
    {
        traget.draw(*i);
    }
}

void Grid::render(sf::RenderTarget& target)
{
    this->renderHorizontal(target);
    this->renderVertical(target);
}
