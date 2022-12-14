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
}

void Game::initUI(sf::Font& font)
{
    this->ui = new UI(this->fileManager, this->winSize, this->textures.tex, font, shop_e);
}

void Game::initScenery()
{
    this->scenery = new Scenery
    (
        this->textures.tex[TextureManager::sceneries],
        this->winSize
    );
}

Game::Game(sf::RenderWindow* window, sf::Font& font)
{
    this->initWindow(window);
    this->initVariables(window);
    this->initUI(font);
    this->initScenery();

    //FOR TESTING !!!!
    this->iso_square = new Isometric_Square(*this->textures.tex[TextureManager::isometric_squares][0], sf::Vector2f(500.f, 350.f), sf::Vector2f(1.f, 1.f));
}

Game::~Game()
{
    delete this->ui;

    //FOR TESTING !!!!
    delete this->iso_square;
    
    delete this->scenery;
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

    this->timer.update();

    this->mouse.update(*this->window, false);

    this->nav.update(this->mouse, *this->ui, this->timer, this->textures.tex[TextureManager::shop_icons], this->shop_e);

    this->shop_e.update();

    this->scenery->update();

    //this->f_Manager->update();
    this->iso_square->update();

    this->ui->update(mouse, shop_e);
}

void Game::render()
{
    this->window->clear();
    
    this->scenery->render(*this->window);

    //FOR TESTING !!!!
    this->iso_square->render(*this->window);

    this->ui->render(*this->window);

    this->window->display();
}
