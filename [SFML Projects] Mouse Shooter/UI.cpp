#include "UI.h"

void UI::initVariables(sf::Vector2u winSize)
{
	this->baseUIActive = true;
	this->shopActive = false;
	this->buildActive = false;
}

void UI::initSprites(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{ 
	int keyFromString = 0;
	for(int i = TextureManager::ui ; i <= TextureManager::build_icon; i++)
	{
		for(int j = 0; j < t_Map[i].size(); j++)
		{
			this->Layers[this->keys[keyFromString]].push_back(new sf::Sprite);
			this->Layers[this->keys[keyFromString]][j]->setTexture(*t_Map[i][j]);
		}
		keyFromString++;
	}
	//Bottom layer
	if(this->Layers["base"][0] != nullptr)
	this->Layers["base"][0]->setPosition(0.f, static_cast<float>(winSize.y) - this->Layers["base"][0]->getGlobalBounds().height);

	//Shop Icon
	if (this->Layers["shop"][0] != nullptr)
	{
		this->Layers["shop"][0]->scale(0.3f, 0.3f);
		this->Layers["shop"][0]->setPosition(20.f, static_cast<float>(winSize.y) - this->Layers["base"][0]->getGlobalBounds().height * 0.86f);
	}
	//Build Icon
	std::cout << "read1\n";
	if (this->Layers["building"][0] != nullptr)
	{
		std::cout << "read\n";
		this->Layers["building"][0]->scale(0.3f, 0.3f);
		this->Layers["building"][0]->setPosition(20.f * 2 + this->Layers["base"][0]->getGlobalBounds().width, static_cast<float>(winSize.y) - this->Layers["base"][0]->getGlobalBounds().height * 0.86f);
	}
	std::cout << "Successfully initalized building 0 sprite!\n";
	// //Bottom Bar
	// this->baseLayer[0]->setPosition(0.f, static_cast<float>(winSize.y) - this->baseLayer[0]->getGlobalBounds().height);
	// //Shop icon
	// this->baseLayer[1]->scale(0.3f, 0.3f);
	// this->baseLayer[1]->setPosition(20.f, static_cast<float>(winSize.y) - this->baseLayer[0]->getGlobalBounds().height * 0.86f );
	// //Build icon
	// this->baseLayer[2]->scale(0.3f, 0.3f);
	// this->baseLayer[2]->setPosition(20.f * 2 + this->baseLayer[1]->getGlobalBounds().width, static_cast<float>(winSize.y) - this->baseLayer[0]->getGlobalBounds().height * 0.86f);
}

UI::UI(sf::Vector2u winSize, std::map<int, std::vector<sf::Texture*>>& t_Map)
{
	this->initVariables(winSize);
	this->initSprites(winSize, t_Map);
}

UI::~UI()
{
	// for (auto& i : baseLayer)
	// {
	// 	this->baseLayer.erase(this->baseLayer.begin(), this->baseLayer.end());
	// }

	for(auto& i : keys)
	{
		for(auto&j : this->Layers[i])
		{
			this->Layers[i].erase(this->Layers[i].begin(), this->Layers[i].end());
		}
	}
	std::cout << "Size of UI baseLayer vector array: " << this->Layers.size() << "\n";
}

void UI::updateNavigation()
{
	nav.update();
}

void UI::update()
{

}

void UI::renderBaseLayer(sf::RenderTarget& target)
{
	for(auto& i : keys)
	{
		for(int j = 0; j < this->Layers[i].size();j++)
		{
			target.draw(*this->Layers[i][j]);
		}
	}
}

void UI::render(sf::RenderTarget& target)
{
	this->renderBaseLayer(target);
}
