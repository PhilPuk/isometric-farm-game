#include"Navigation.h"

void Navigation::initVariables()
{

}

Navigation::Navigation()
{

}

Navigation::~Navigation()
{

}


bool Navigation::CheckForObjectClicked(Mouse& mouse, sf::FloatRect& pos)
{
    if(mouse.getMouseLeftClicked())
    {
        if(pos.contains(mouse.getMousePosView()));
        return true;
    }
    return false;
}

void Navigation::update(Mouse& mouse)
{

}

void Navigation::render(sf::RenderTarget& target)
{

}