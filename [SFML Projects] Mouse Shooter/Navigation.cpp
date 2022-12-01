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


bool Navigation::CheckForObjectClicked(Mouse& mouse, sf::FloatRect& pos, Timer& timer)
{
    //Checks if left mouse button is clicked
    if (mouse.getMouseLeftClicked())
    {
        //Checks if total time of application is bigger than the time the mouse should be available to be clicked again
        if (timer.getTotalTime() >= mouse.get_Mouse_Click_Time_Reach())
        {
            //Checks if mouse is on the object
            if (pos.contains(mouse.getMousePosView()))
            {
                //Sets the new timer when the mouse can be clicked again
                mouse.set_Mouse_Click_Time_Reach(timer.getTotalTime());
                return true;
            }
        }
    }
    //Debug times
    //std::cout << "Total time: " << timer.getTotalTime() << " - Mouse reach: " << mouse.get_Mouse_Click_Time_Reach()<<"\n";
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


void Navigation::updateIconsClickedTemplate(UI& ui, Mouse& mouse, Timer& timer, sf::Vector2f pos, void(&activate)(),  const bool&(& getActive)(), std::vector<sf::Sprite*>& sprites)
{
    int tmpIndex;
    //Checks for click on shop Icon
    //If its already active, activated base instead of shop
    tmpIndex = this->updateUIBaseLoop(sprites, mouse, timer);
    if (tmpIndex == 0)
        if (getActive())
        {
            ui.selected.deactivate();
            ui.activateBase();
        }
        else
        {
            activate();
            ui.selected.activate();
            ui.selected.changePositionXOfSelection(pos.x);
            ui.base->setPopBoxXPos(pos.x);
            ui.base->setPopBoxYPos(pos.y - ui.base->s_popBox.getGlobalBounds().height);
        }
}

void Navigation::updateMainIconsClicked(UI& ui, Mouse& mouse, Timer& timer)
{
    //Check if shop icons are clicked
    this->updateIconsClickedTemplate(ui, mouse, timer, ui.shop->sprites[0]->getPosition(), ui.activateShop, ui.getShopActive, ui.shop->sprites);

    //Check if building icons are clicked
    this->updateIconsClickedTemplate(ui, mouse, timer, ui.build->sprites[0]->getPosition(), ui.activateBuilding, ui.getBuildActive, ui.build->sprites);
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