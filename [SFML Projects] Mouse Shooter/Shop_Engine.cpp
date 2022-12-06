#include"Shop_Engine.h"

void ShopEngine::initVariables()
{
    this->bank = 0.f;
}

ShopEngine::ShopEngine()
{
    this->initVariables();
}

virtual ShopEngine::~ShopEngine()
{

}

//Modifiers
void ShopEngine::addMoneytoBank(float& amount const)
{
    this->bank += amount;
}

void ShopEngine::reduceMoneyFromBank(float& amount const)
{
    this->bank -= amount;
}

//Accessors
const bool& ShopEngine::getMoneyFromBank() const
{
    return this->bank;
}

const float& ShopEngine::getPriceOfSeed(int index) const
{

}