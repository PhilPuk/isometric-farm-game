#include"SeedManager.h"

void SeedManager::initVariables()
{
}

SeedManager::SeedManager()
{
	this->initVariables();
}

SeedManager::~SeedManager()
{
	for (auto& i : this->seeds)
	{
		this->seeds.erase(this->seeds.begin(), this->seeds.end());
	}
}

void SeedManager::createNewSeed(sf::Vector2f pos, int indexOfSeed, sf::Texture& t_OnCrop, sf::Texture& t_Icon)
{
	this->seeds.push_back(new Seed(t_OnCrop, t_Icon, pos));
}

void SeedManager::update(Timer& timer)
{

}

void SeedManager::renderSeeds(sf::RenderTarget& target)
{
	for (auto& i : this->seeds)
	{
		i->renderOnCroop(target);
	}
}

void SeedManager::render(sf::RenderTarget& target)
{
	this->renderSeeds(target);
}
