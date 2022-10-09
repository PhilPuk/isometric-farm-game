#include "Mouse.h"

//Constructor / Destructor
Mouse::Mouse()
{

}

Mouse::~Mouse()
{

}

const sf::Vector2i Mouse::getMousePosWindow() const
{
	return this->mousePosWindow;
}

const sf::Vector2f Mouse::getMousePosView() const
{
	return this->mousePosView;
}

//Functions
	//Update
void Mouse::updateMousePositions(sf::RenderWindow& window, bool debug)
{
	this->mousePosWindow = sf::Mouse::getPosition(window);
	this->mousePosView = window.mapPixelToCoords(this->mousePosWindow);

	if (debug)
	{
		//To debug mouse positions
		system("cls");
		std::cout << "MOUSEPOSVIEW:		Mouse X: " << this->mousePosView.x << "	Mouse Y: " << this->mousePosView.y << "\n";
		std::cout << "MOUSEPOSWINDOW:	Mouse X: " << this->mousePosWindow.x << "	Mouse Y: " << this->mousePosWindow.y << "\n";
	}
}

void Mouse::update()
{

}
