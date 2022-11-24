#include"Navigation.h"

void Navigation::initVariables()
{

}

Navigation::Navigation()
{
    this->initVariables();
}

Navigation::~Navigation()
{

}


bool Navigation::CheckForObjectClicked(Mouse& mouse, sf::FloatRect& pos)
{
    if(mouse.getMouseLeftClicked())
    {
        if(pos.contains(mouse.getMousePosView()))
        return true;
    }
    return false;
}

int Navigation::updateUIBaseLoop(std::vector<sf::Sprite*>& objects, Mouse& mouse)
{
   //Check each content if its clicked
    //if one is clicked return and save the index of the clicked object
    sf::FloatRect tmp;
    for(int i = 0; i < objects.size(); i++)
    {
        tmp = objects[i]->getGlobalBounds();
        if(this->CheckForObjectClicked(mouse, tmp))
        return i;
    }
    return -1;
}

void Navigation::updateMainIconsClicked(UI& ui, Mouse& mouse)
{
    int tmpIndex;
    //Checks for click on shop Icon
    //If its already active, activated base instead of shop
    tmpIndex = this->updateUIBaseLoop(ui.shop->sprites, mouse);
    if(tmpIndex == 0)
        if(ui.getShopActive())
            ui.activateBase();
        else
            ui.activateShop();

    //Checks for click on build Icon
    //If its already active, activated base instead of build
    tmpIndex = this->updateUIBaseLoop(ui.build->sprites, mouse);
    if(tmpIndex == 0)
        if(ui.getBuildActive())
            ui.activateBase();
        else
            ui.activateBuilding();
}

void Navigation::updateUI(UI& ui, Mouse& mouse)
{
    this->updateMainIconsClicked(ui, mouse);

}
void Navigation::update(Mouse& mouse, UI& ui)
{
    this->updateUI(ui, mouse);
}

void Navigation::render(sf::RenderTarget& target)
{

}