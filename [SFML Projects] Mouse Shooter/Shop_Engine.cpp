#include"Shop_Engine.h"

void ShopEngine::initVariables()
{
    this->bank = 100.f;
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
    this->bank +=amount;
}

void ShopEngine::reduceMoneyFromBank(float& amount)
{
    this->bank -=amount;
}

//Accessors
const bool& ShopEngine::getMoneyInBank() const
{
    return this->bank;
}

const float& ShopEngine::getPriceOfSeed(int index) const
{
    if(index < 0 || index > (sizeof(this->seed_prices) / sizeof(this->seed_prices[0]))) return -1;
    return this->seed_prices[index];
}

const bool& ShopEngine::getBuyIsPossible(float price)
{
    if(this->bank >= price)
        return true;
    return false;
}

void ShopEngine::update()
{

}