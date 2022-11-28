#include"Navigation.h"

void Navigation::initVariables()
{
    this->mouse_click_goal = 0.f;
    this->mouse_click_puffer = 30.f / 5.f;
}

Navigation::Navigation()
{
    this->initVariables();
}

Navigation::~Navigation()
{

}


bool Navigation::CheckForObjectClicked(Mouse& mouse, sf::FloatRect& pos, Timer& timer)
{
    //Checks if total time of application is bigger the time the mouse should be available to be clicked again
    if (timer.getTotalTime() >= this->mouse_click_goal)
    {
        //Checks if left mouse button is clicked
        if (mouse.getMouseLeftClicked())
        {
            //Checks if mouse is on the object
            if (pos.contains(mouse.getMousePosView()))
            {
                //Sets the new timer when the mouse can be clicked again
                this->mouse_click_goal = timer.getTotalTime() + this->mouse_click_puffer;
                return true;
            }
        }
    }
    return false;
}

int Navigation::updateUIBaseLoop(std::vector<sf::Sprite*>& objects, Mouse& mouse, Timer& timer)
{
    //Check each content if its clicked
     //if one is clicked return and save the index of the clicked object
    sf::FloatRect tmp;
    for (int i = 0; i < objects.size(); i++)
    {
        tmp = objects[i]->getGlobalBounds();
        if (this->CheckForObjectClicked(mouse, tmp, timer))
            return i;
    }
    return -1;
}

void Navigation::updateMainIconsClicked(UI& ui, Mouse& mouse, Timer& timer)
{
    //To-do change so i can do both in one loop
    //Repetition is bad!

    int tmpIndex;
    //Checks for click on shop Icon
    //If its already active, activated base instead of shop
    tmpIndex = this->updateUIBaseLoop(ui.shop->sprites, mouse, timer);
    if (tmpIndex == 0)
        if (ui.getShopActive())
        {
            ui.selected.deactivate();
            ui.activateBase();
        }
        else
        {
            ui.activateShop();
            ui.selected.activate();
            ui.selected.changePositionXOfSelection(ui.shop->sprites[0]->getPosition().x);
        }

    //Checks for click on build Icon
    //If its already active, activated base instead of build
    tmpIndex = this->updateUIBaseLoop(ui.build->sprites, mouse, timer);
    if (tmpIndex == 0)
        if (ui.getBuildActive())
        {
            ui.selected.deactivate();
            ui.activateBase();
        }
        else
        {
            ui.activateBuilding();
            ui.selected.activate();
            ui.selected.changePositionXOfSelection(ui.build->sprites[0]->getPosition().x);
        }
}

void Navigation::updateUI(UI& ui, Mouse& mouse, Timer& timer)
{
    this->updateMainIconsClicked(ui, mouse, timer);

}
void Navigation::update(Mouse& mouse, UI& ui, Timer& timer)
{
    this->updateUI(ui, mouse, timer);
}

void Navigation::render(sf::RenderTarget& target)
{

}