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

int updateUIBaseLoop(std::vector<sf::Sprites*>& objects)
{
   //Check each content if its clicked
    //if one is clicked return and save the index of the clicked object
    for(int i = 0; i < objects.size(); i++)
    {
        if(this->CheckForObjectClicked(objects[i].getGlobalBounds()))
        return i;
    }
    return -1;
}

void updateMainIconsClicked(UI& ui)
{
    //Checks for click on shop Icon
    //If its already active, activated base instead of shop
    tmpIndex = this->updateUIBaseLoop(ui.shop.sprites);
    if(tmpIndex = 0)
        if(ui.getShopActive())
            ui.activateBase();
        else
            ui.activateShop();

    //Checks for click on build Icon
    //If its already active, activated base instead of build
    tmpIndex = this->updateUIBaseLoop(ui.building.sprites);
    if(tmpIndex= 0)
        if(ui.getBuildActive())
            ui.activateBase();
        else
            ui.activateBuilding();
}

void Navigation::updateUI(UI& ui)
{
    this->updateMainIconsClicked(ui);

}
void Navigation::update(Mouse& mouse, UI& ui)
{
    this->updateUI(ui);
}

void Navigation::render(sf::RenderTarget& target)
{

}