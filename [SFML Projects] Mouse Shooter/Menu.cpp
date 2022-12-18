#include "Menu.h"

//Private functions
	//Initialization
void Menu::initVariables()
{
	//Window
		//Screen size
	this->videoMode.width = 1600;
	this->videoMode.height = 900;
		//Framerate
	this->Framerate = 60;

	//Texts
	this->Application_Title = "Gardenia";
	this->Color_Menu = sf::Color(255,255,100,255);
	this->Color_Menu_Selected = sf::Color(255, 200, 10, 255);
		//Text Pos
	this->Vector_Menu_Pos.x = 100.f;
	this->Vector_Menu_Pos.y = static_cast<float>(this->videoMode.height) / 1.7f;
		//Text spacing
	this->Spacing_Menu_Pos_Y = 75.f;

	//Menu navigation
	this->Menu_Navigation_Index = 0;
	this->Navigation_Index_Changed = false;
}

void Menu::initWindow()
{
	//Create window with framerate cap
	this->window = new sf::RenderWindow(this->videoMode, this->Application_Title, sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(this->Framerate);
}

void Menu::initFonts()
{
	//Initialize all fonts
	if (!this->font.loadFromFile("Fonts/Starborn.ttf"))
		std::cout << " - ERROR::MENU::INITFONTS:: Couldn't load font!\n";
}

void Menu::initText()
{
	//sets all texts content
	this->Text_Title.setString("Gardenia");
		//Start
	this->Text_Menu_Options[0].setString("Start");
		//Options
	this->Text_Menu_Options[1].setString("Settings");
		//Stop
	this->Text_Menu_Options[2].setString("Stop");

	//sets all texts settings
		//Title
	this->Text_Title.setFont(this->font);
	this->Text_Title.setCharacterSize(44);
	this->Text_Title.setFillColor(this->Color_Menu);
	this->Text_Title.setPosition(this->Vector_Menu_Pos.x, this->Vector_Menu_Pos.y - this->Spacing_Menu_Pos_Y * 2.f);

		//Menu_Options
	sf::Vector2f tmp_saveVector = this->Vector_Menu_Pos;
	for (int i = 0; i < 3; i++)
	{
		this->Text_Menu_Options[i].setFont(this->font);
		this->Text_Menu_Options[i].setCharacterSize(24);
		this->Text_Menu_Options[i].setFillColor(this->Color_Menu);
		this->Text_Menu_Options[i].setPosition(this->Vector_Menu_Pos);
		//Increase spacing for each text
		this->Vector_Menu_Pos.y = this->Vector_Menu_Pos.y + this->Spacing_Menu_Pos_Y;
	}
	//Reset vector
	this->Vector_Menu_Pos = tmp_saveVector;

	//Sets first option to Navigation Index Color
	this->Text_Menu_Options[this->Menu_Navigation_Index].setFillColor(this->Color_Menu_Selected);
}

void Menu::initGame()
{
	this->game = new Game(this->window, font);
}

	//Menu_Navigation
void Menu::navigateUP()
{
	if (this->Menu_Navigation_Index > 0)
	{
		this->Menu_Navigation_Index--;
		this->Navigation_Index_Changed = true;
	}
}

void Menu::navigateDOWN()
{
	if (this->Menu_Navigation_Index < 2)
	{
		this->Menu_Navigation_Index++;
		this->Navigation_Index_Changed = true;
	}
}

void Menu::navigateWithMouse()
{
	for (int i = 0; i < sizeof(this->Text_Menu_Options) / sizeof(this->Text_Menu_Options[0]); i++)
	{
		if (this->Text_Menu_Options[i].getGlobalBounds().contains(this->mouse.getMousePosView()))
		{
			this->Menu_Navigation_Index = i;
			this->Navigation_Index_Changed = true;

			if (mouse.getMouseLeftClicked())
			{
				this->pollMainActions();
			}
		}
	}
}


//Constructor / Destructor
Menu::Menu()
{
	//Call all functions that need to be initialized
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
	this->initGame();
}

Menu::~Menu()
{
	delete this->window;

	delete this->game;
}

void Menu::pollGame()
{
	//Start button action
	this->game->run();
	this->game->resetVariables();
}

void Menu::pollSettings()
{

}

void Menu::pollStop()
{
	//Stop button action
	this->window->close();
}

void Menu::pollMainActions()
{
	//Menu_Options function called here
	if (this->Menu_Navigation_Index == 0)
	{
		this->pollGame();
	}
	else if (this->Menu_Navigation_Index == 1)
	{
		//Settings button action
		this->pollSettings();
	}
	else if (this->Menu_Navigation_Index == 2)
	{
		this->pollStop();
	}
}

//Functions
void Menu::run()
{
	//Main loop for whole application
	while (this->window->isOpen() && !this->game->getEndApplication())
	{
		this->udpate();

		this->render();
	}
}

void Menu::EventEnterPressed(sf::Event& ev)
{
	if (ev.key.code == sf::Keyboard::Enter)
	{
		this->pollMainActions();
	}
}

void Menu::EventMenuNavigation(sf::Event& ev)
{
	//Menu Navigation Event
	if (ev.key.code == sf::Keyboard::W || ev.key.code == sf::Keyboard::Up)
		this->navigateUP();
	else if (ev.key.code == sf::Keyboard::S || ev.key.code == sf::Keyboard::Down)
		this->navigateDOWN();
}

void Menu::pollEventsKeyPressed(sf::Event& ev)
{
	//Esc to close
	if (ev.key.code == sf::Keyboard::Escape)
		this->window->close();

	this->EventEnterPressed(ev);

	this->EventMenuNavigation(ev);
}

void Menu::pollEvents()
{
	sf::Event ev;
	while (this->window->pollEvent(ev))
	{
		switch (ev.type)
		{
		//Closing Event
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			this->pollEventsKeyPressed(ev);
			break;
		}
	}
}

//update
void Menu::updateText()
{
	//Changes color of currently selected option 
	//Resets other to standart color
	if (this->Navigation_Index_Changed)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == this->Menu_Navigation_Index)
				this->Text_Menu_Options[i].setFillColor(this->Color_Menu_Selected);
			else
				this->Text_Menu_Options[i].setFillColor(this->Color_Menu);
		}
		this->Navigation_Index_Changed = false;
	}
}

void Menu::udpate()
{
	//Event polling
	this->pollEvents();

	//Text updating
	this->updateText();

	mouse.update(*this->window, false);

	this->navigateWithMouse();
}

//render
void Menu::renderText()
{
	//Title text
	this->window->draw(this->Text_Title);

	//Menu_Options
	for (int i = 0; i < 3; i++)
	{
		this->window->draw(this->Text_Menu_Options[i]);
	}
}

void Menu::render()
{
	this->window->clear();

	this->game->scenery->render(*this->window);

	this->renderText();

	this->window->display();
}
