#include "LightManager.h"

void LightManager::initVariables()
{
    this->keyPressed = false;

    //Scaling
    this->scale = false;
    this->scaleMax = 1.3f;
    this->scaleAmount = 0.02f;
}

void LightManager::initTextures(sf::Texture& texture)
{
    //this->textures.emplace("yellow", texture);
    this->texture = texture;
}

void LightManager::initPreSpawnedLights(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        this->newLight();
    }
}

LightManager::LightManager(sf::Texture& texture)
{
	this->initVariables();
	this->initTextures(texture);
    this->initPreSpawnedLights(0);
}

LightManager::~LightManager()
{
    for (size_t i = 0; i < this->lights.size(); i++)
    {
        delete this->lights[i];
        this->lights.erase(this->lights.begin(), this->lights.end());

        this->velocity.erase(this->velocity.begin(), this->velocity.end());
    }

    std::cout << "Size of lights vector: " << this->lights.size() << "\n";
    std::cout << "Size of lights velocity vector: " << this->velocity.size() << "\n";
}

void LightManager::newLight()
{
    sf::Vector2f pos(static_cast<float>(rand() % 1500 + 50), static_cast<float>(rand() % 800 + 50));
    this->lights.push_back(new Light(this->texture, 0, pos, true));
    this->newVelocity();
    std::cout << "New lights vector size: " << this->lights.size() << "\n";
}

void LightManager::newVelocity()
{
    //New velocity randomized
    float velX = static_cast<float>(rand() % 100 + 1) / 7.5f;
    float velY = static_cast<float>(rand() % 100 + 1) / 7.5f;
    this->velocity.push_back(sf::Vector2f(velX, velY));
}

void LightManager::SpawnOnEnterPressed()
{
    /*
    //Only works once, need to release enter key to spawn another one.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        if (!keyPressed)
        {
            this->keyPressed = true;
            this->newLight();
        }
    }
    else
        this->keyPressed = false;


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
            this->newLight();
    }
    */
}

void LightManager::updateMovement(int& i)
{
    this->lights[i]->moveLight(this->velocity[i]);
  //  this->tracing.createNewTraceBox(this->lights[i]->sprite.getPosition());
}

void LightManager::updateLightCollisionWall(int& i, sf::Vector2u& winSize)
{
    if (this->lights[i]->sprite.getPosition().x > winSize.x)
    {
        this->velocity[i].x *= -1;
    }
    else if (this->lights[i]->sprite.getPosition().x < 0)
    {
        this->velocity[i].x *= -1;
    }

    if (this->lights[i]->sprite.getPosition().y > winSize.y)
    {
        this->velocity[i].y *= -1;
    }
    else if (this->lights[i]->sprite.getPosition().y < 0)
    {
        this->velocity[i].y *= -1;
    }
}

void LightManager::updateScalingOfLights(int& i)
{
    if (scale)
    {
        if (this->lights[i]->sprite.getScale().x > this->scaleMax)
        {
            this->scale = !this->scale;
            return;
        }
        this->lights[i]->sprite.scale(1.f + this->scaleAmount, 1.f + this->scaleAmount);
    }
    else
    {
        if (this->lights[i]->sprite.getScale().x < 1.f)
        {
            this->scale = !this->scale;
            return;
        }
        this->lights[i]->sprite.scale(1.f - this->scaleAmount, 1.f - this->scaleAmount);
    }
}

void LightManager::updateForLoop(sf::Vector2u& winSize)
{
    for (int i = 0; i < lights.size(); i++)
    {
        this->updateScalingOfLights(i);
        this->updateMovement(i);
        this->updateLightCollisionWall(i, winSize);
    }
}

void LightManager::update(sf::Vector2u& winSize)
{
    this->SpawnOnEnterPressed();

    this->updateForLoop(winSize);

   // this->tracing.update();
}

void LightManager::renderLights(sf::RenderTarget& target)
{
    for (int i = 0; i < lights.size(); i++)
    {
        lights[i]->render(target);
    }
}

void LightManager::render(sf::RenderTarget& target)
{
    this->renderLights(target);
   // this->tracing.render(target);
}
