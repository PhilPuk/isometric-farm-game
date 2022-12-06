#include"Shop_Engine.h"

void ShopEngine::initVariables()
{
    this->bank = 0.f;
}

ShopEngine::ShopEngine()
{
    this->initVariables();
}

ShopEngine::~ShopEngine()
{

}

//Modifiers
void ShopEngine::addMoneytoBank(float& amount)
{
    this->bank += amount;
}

void ShopEngine::reduceMoneyFromBank(float& amount)
{
    this->bank -= amount;
}

//Accessors
const bool& ShopEngine::getMoneyInBank() const
{
    return this->bank;
}

const float& ShopEngine::getPriceOfSeed(int index) const
{
    //To-do
    return 0;
}