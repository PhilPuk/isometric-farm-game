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

const bool& Navigation::getMouseClicked() const
{
    return this->sf::MouseButtonEvent::isButtonPressed(sf::Mouse::left);
}

void Navigation::update()
{

}

void Navigation::render(sf::RenderTarget& target)
{

}