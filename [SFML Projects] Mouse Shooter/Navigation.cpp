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
                mouse.set_Mouse_Held();
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


const bool& Navigation::CheckForMouseOnObject(Mouse& mouse, sf::FloatRect object_bounds)
{
    if (object_bounds.contains(mouse.getMousePosView()))
        return true;
    return false;
}

void Navigation::updateShopItemsMoved(Mouse& mouse, Timer& timer, UI& ui, std::vector<sf::Texture*>& textures)
{
    if (!ui.shop->SeedCloneActivated && ui.getShopActive())
    {
        sf::FloatRect tmp;
        for (int i = 1; i < ui.shop->sprites.size(); i++)
        {
            tmp = ui.shop->sprites[i]->getGlobalBounds();
            if (this->CheckForObjectClicked(mouse, tmp, timer))
            {
                ui.shop->SeedCloneActivated = true;
                ui.shop->setSeedCloneTexture(*textures[i]);
            }
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && ui.shop->SeedCloneActivated)
    {
        ui.shop->s_SeedClone.setPosition(mouse.getMousePosView().x - ui.shop->s_SeedClone.getGlobalBounds().width/2.f, mouse.getMousePosView().y - ui.shop->s_SeedClone.getGlobalBounds().height / 2.f);
    }
    else
    {
        ui.shop->SeedCloneActivated = false;
    }
}

void Navigation::updateShopOrBuildPressedTemplate(UI& ui, Mouse& mouse, Timer& timer, sf::Vector2f pos, void(&activate)(),  const bool&(& getActive)(), sf::Sprite*& sprite)
{
    //Get global bounds of the sprite
    sf::FloatRect tmp = sprite->getGlobalBounds();
    //Checks if the sprite is clicked
    if (this->CheckForObjectClicked(mouse, tmp, timer))
        //if its already activated deactivate it
        if (getActive())
        {
            ui.selected.deactivate();
            ui.activateBase();
        }
        //if not activate it and set the popBox on the given pos
        //plus set the selection pos on the clicked sprite
        else
        {
            activate();
            ui.selected.activate();
            ui.selected.changePositionXOfSelection(pos.x);
            ui.base->setPopBoxXPos(pos.x);
            ui.base->setPopBoxYPos(pos.y - ui.base->s_popBox.getGlobalBounds().height);
        }
}

void Navigation::updateShopOrBuildPressed(UI& ui, Mouse& mouse, Timer& timer)
{
    if (!mouse.getMouseHeld())
    {
        //Check if shop icons are clicked
        this->updateShopOrBuildPressedTemplate(ui, mouse, timer, ui.shop->sprites[0]->getPosition(), ui.activateShop, ui.getShopActive, ui.shop->sprites[0]);

        //Check if building icons are clicked
        this->updateShopOrBuildPressedTemplate(ui, mouse, timer, ui.build->sprites[0]->getPosition(), ui.activateBuilding, ui.getBuildActive, ui.build->sprites[0]);
    }
}

void Navigation::updateSeedHoverOnField(UI& ui, Mouse& mouse, Timer& timer, FieldManager& f_Manager,  ShopEngine& shop_e)
{
    //TO-DO
    //GET INDEX OF SEEDS TO BUY
    if (ui.shop->SeedCloneActivated || f_Manager.anyCropisMarked)
    {
        f_Manager.anyCropisMarked = false;
        //Loops through fields
        for (int i = 0; i < f_Manager.fields.size(); i++)
        {
            //Loop through crops
            for (int j = 0; j < f_Manager.fields[i]->crops.size(); j++)
            {
                f_Manager.updateMarking(i, j, mouse, this->CheckForMouseOnObject, shop_e, 0);
            }
        }
    }
}

void Navigation::updateUI(UI& ui, Mouse& mouse, Timer& timer)
{
    this->updateShopOrBuildPressed(ui, mouse, timer);

}
void Navigation::update(Mouse& mouse, UI& ui, Timer& timer, std::vector<sf::Texture*>& textures, FieldManager& f_Manager, ShopEngine& shop_e)
{
    this->updateShopItemsMoved(mouse, timer, ui, textures);
    this->updateSeedHoverOnField(ui, mouse, timer, f_Manager, shop_e);
    this->updateUI(ui, mouse, timer);
}

void Navigation::render(sf::RenderTarget& target)
{

}