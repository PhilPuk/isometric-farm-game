#include "Game.h"

void Game::initWindow(sf::RenderWindow* window)
{
    this->window = window;

    this->winSize.x = this->window->getSize().x;
    this->winSize.y = this->window->getSize().y;
}

//Initialization
void Game::initVariables(sf::RenderWindow* window)
{
    this->endGame = false;
    this->endApplication = false;

    this->spawnTimerMax = 30.f;
    this->spawnTimer = this->spawnTimerMax;
}

Game::Game(sf::RenderWindow* window)
{
    this->initWindow(window);
    this->initVariables(window);
}

Game::~Game()
{

}

void Game::CloseApplication()
{
    this->endGame = true;
    this->endApplication = true;
}

void Game::resetVariables()
{
    this->initVariables(this->window);
}

const bool& Game::getEndGame() const
{
    return this->endGame;
}

const bool& Game::getEndApplication() const
{
    return this->endApplication;
}


void Game::run()
{
    //Main loop of the game

    while (!endGame)
    {
        this->update();

        this->render();
    }
}

void Game::pollEvents()
{
    while (this->window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            this->CloseApplication();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
                this->endGame = true;
            break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    this->window->clear();

    this->window->display();
}
