#include"shop_ui.h"

void Shop_UI::initVariables()
{
    this->lastBank = 100.f;
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

void Shop_UI::initItemTexts(FileManagement& fileManager, sf::Vector2u& winSize, sf::Font& font)
{
    sf::Text base;
    base.setFont(font);
    base.setCharacterSize(12);
    base.setFillColor(sf::Color::Black);

    //Bank text
    this->text_bank = base;
    std::stringstream s;
    s << this->lastBank << "$";
    this->text_bank.setString(s.str());
    this->text_bank.setCharacterSize(32);
    this->text_bank.setPosition(static_cast<float>(winSize.x) - text_bank.getGlobalBounds().width - 10.f, 10.f);


    int amount = fileManager.getAmountOfFilesInsideAFolder("C:/Users/Phil/source/repos/[SFML Projects] SFML Template 1.0 - Kopie - Kopie/[SFML Projects] Mouse Shooter/Textures/ui/shop");
    for (int i = 1; i < amount; i++)
    {
        std::string x = fileManager.getNameOfFilesInsideAFolder("C:/Users/Phil/source/repos/[SFML Projects] SFML Template 1.0 - Kopie - Kopie/[SFML Projects] Mouse Shooter/Textures/ui/shop")[i] + " " + std::to_string((int)this->prices[i - 1]) + "$";
        base.setString(x);
        base.setPosition(this->sprites[i]->getPosition().x + (this->sprites[i]->getGlobalBounds().width - base.getGlobalBounds().width) / 2.f, this->sprites[i]->getPosition().y + this->sprites[i]->getGlobalBounds().height);
        this->texts.push_back(new sf::Text(base));
    }
}

void Shop_UI::initShopItems(sf::Vector2u& winSize, float popBoxHeight, float popBoxWidth)
{
    float scale = 0.3f;
    float spacingX = 35.f;
    float posX = this->sprites[0]->getPosition().x + spacingX;
    float posY = this->sprites[0]->getPosition().y - popBoxHeight + 20.f;

    for (int i = 1; i < this->sprites.size(); i++)
    {
        this->sprites[i]->scale(scale, scale);
        this->sprites[i]->setPosition(posX, posY);
        posX += this->sprites[0]->getGlobalBounds().width + spacingX;
        if (posX >= popBoxWidth - this->sprites[0]->getGlobalBounds().width)
        {
            posX = this->sprites[0]->getPosition().x + spacingX;
            posY += spacingX + this->sprites[1]->getGlobalBounds().height;
        }
    }
}

void Shop_UI::initSeedClone(sf::Vector2u& winSize)
{
    this->s_SeedClone.scale(0.3f, 0.3f);
    sf::FloatRect rect = this->s_SeedClone.getLocalBounds();
    this->s_SeedClone.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
}

Shop_UI::Shop_UI(FileManagement& fileManager, sf::Vector2u& winSize, std::vector<sf::Texture*> textures, sf::Vector2f bottom_bar_Pos, float popBoxHeight, float popBoxWidth, sf::Font& font)
{
    this->initVariables();
    this->initCreateSprites(textures);
    this->initSpritePositions(winSize, bottom_bar_Pos);
    this->initShopItems(winSize, popBoxHeight, popBoxWidth);
    this->initItemTexts(fileManager, winSize, font);
    this->initSeedClone(winSize);
}

Shop_UI::~Shop_UI()
{
    for(auto& i : this->sprites)
    {
        this->sprites.erase(this->sprites.begin(), this->sprites.end());
    }

    for (auto& i : this->texts)
    {
        this->texts.erase(this->texts.begin(), this->texts.end());
    }
}

void Shop_UI::setSeedCloneTexture(sf::Texture& texture)
{
    this->s_SeedClone.setTexture(texture);
}


void Shop_UI::reduceMoneyAfterBuy(float& reduce)
{
    if (this->lastBank >= reduce)
        this->lastBank -= reduce;
    else
        std::cout << " ERROR::SHOP_UI::REDUCEMONEYAFTERBUY::Not enough money to buy the item! Should not be handled by this assert!!!\n";
}

const float& Shop_UI::getMoneyInBank() const
{
    return this->lastBank;
}

void Shop_UI::updateBank(float& bank)
{
    if (lastBank != bank)
    {
        this->lastBank = bank;
        std::stringstream ss;
        ss << bank << "$";
        this->text_bank.setString(ss.str());
    }
}

void Shop_UI::update(float& bank)
{
    this->updateBank(bank);
}

void Shop_UI::renderBankText(sf::RenderTarget& target)
{
    target.draw(this->text_bank);
}

void Shop_UI::render(sf::RenderTarget& target, bool& activated)
{
    this->renderBaseIcon(target);
    if (activated)
    {
        this->renderItems(target);
        this->renderTexts(target);
    }
    this->renderBankText(target);
}
