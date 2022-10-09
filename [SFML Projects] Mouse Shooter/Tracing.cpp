#include "Tracing.h"

void Tracing::initVariables()
{
	this->msgTimeMax = 60.f;
	this->msgTime = this->msgTimeMax;
}

void Tracing::initBox()
{
	this->box.setFillColor(sf::Color(255,0,0,100));
	//this->box.setSize(sf::Vector2f(10.f, 10.f));
	this->box.setRadius(5.f);

	this->box.setPosition(sf::Vector2f(-100.f, -100.f));

	this->box.setOrigin
	(
		this->box.getLocalBounds().left + this->box.getLocalBounds().width / 2.0f,
		this->box.getLocalBounds().top + this->box.getLocalBounds().height / 2.0f
	);
}

Tracing::Tracing()
{
	this->initVariables();
	this->initBox();
}

Tracing::~Tracing()
{
	for (int i = 0; i < this->traces.size(); i++)
	{
		delete this->traces[i];
		this->traces.erase(this->traces.begin(), this->traces.end());
	}
	std::cout << "Traces vector size: " << this->traces.size() << "\n";
}

void Tracing::createNewTraceBox(const sf::Vector2f& pos)
{
	this->traces.push_back(new sf::CircleShape(box));
	this->traces[this->traces.size() - 1]->setPosition(pos);
}

void Tracing::deleteSpecificTrace(int& index)
{
	delete this->traces[index];
	this->traces.erase(this->traces.begin() + index);
}

void Tracing::updateCMDMessages()
{
	if (this->msgTime < this->msgTimeMax)
	{
		this->msgTime++;
	}
	else
	{
		this->msgTime = 0.f;
		std::cout << "Traces vector size: " << this->traces.size() << "\n";
	}
}

void Tracing::updateOpacity(int& i)
{
	//RGB Circles
	//this->traces[i]->setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, this->traces[i]->getFillColor().a - 1));
	//Red
	this->traces[i]->setFillColor(sf::Color(255, 0, 0, this->traces[i]->getFillColor().a - 1));
}

void Tracing::updateTraceDeletion(int& i)
{
	if (this->traces[i]->getFillColor().a <= 0)
		this->deleteSpecificTrace(i);
}

void Tracing::updateForLoop()
{
	for (int i = 0; i < this->traces.size(); i++)
	{
		this->updateOpacity(i);
		this->updateTraceDeletion(i);
	}
}

void Tracing::update()
{
	this->updateCMDMessages();
	this->updateForLoop();
}

void Tracing::renderTraces(sf::RenderTarget& target)
{
	for (int i = 0; i < this->traces.size(); i++)
	{
		target.draw(*this->traces[i]);
	}
}

void Tracing::render(sf::RenderTarget& target)
{
	this->renderTraces(target);
}

