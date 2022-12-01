#include"shop_ui.h"

void Shop_UI::initVariables()
{

}

void Shop_UI::initCreateSprites(std::vector<sf::Texture*> textures)
{
    for(int i = 0; i < textures.size(); i++)
    {
        this->sprites.push_back(new sf::Sprite);
        this->sprites[i]->setTexture(*textures[i]);
    }
    std::cout << "Size of shop sprites: " << this->sprites.size() << "\n";
}
void Shop_UI::initSpritePositions(sf::Vector2u& winSize, sf::Vector2f bottom_bar_Pos)
{
    this->sprites[0]->scale(0.3f, 0.3f);
	this->sprites[0]->setPosition(20.f, static_cast<float>(winSize.y) - this->sprites[0]->getGlobalBounds().height * 1.2f);
}

void Shop_UI::initShopItems(sf::Vector2u& winSize, float popBoxHeight)
{
    float scale = 0.3f;
    float spacingX = 20.f;
    float posX = this->sprites[0]->getPosition().x + spacingX;
    float posY = this->sprites[0]->getPosition().y - popBoxHeight + 20.f;

    for (int i = 1; i < this->sprites.size(); i++)
    {
        this->sprites[i]->scale(scale, scale);
        this->sprites[i]->setPosition(posX * i, posY);
    }
}

void Shop_UI::initSeedClone(sf::Vector2u& winSize)
{
    this->s_SeedClone.scale(0.3f, 0.3f);
    sf::FloatRect rect = this->s_SeedClone.getLocalBounds();
    this->s_SeedClone.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);

}

Shop_UI::Shop_UI(sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f bottom_bar_Pos, float popBoxHeight)
{
    this->initCreateSprites(textures);
    this->initSpritePositions(winSize, bottom_bar_Pos);
    this->initShopItems(winSize, popBoxHeight);
    this->initSeedClone(winSize);
}

Shop_UI::~Shop_UI()
{
    for(auto& i : this->sprites)
    {
        this->sprites.erase(this->sprites.begin(), this->sprites.end());
    }
}

void Shop_UI::setSeedCloneTexture(sf::Texture& texture)
{
    this->s_SeedClone.setTexture(texture);
}

void Shop_UI::update()
{

}