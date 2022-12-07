#pragma once

#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"FileManagement.h"

//To-do
//Create savefiles
//Read savefiles from txt

class ShopEngine
{
private:
    float seed_prices[15] = {30,10,15,25,15,35,30,20,5,12,9,18,15,8,19};
    float bank;
    void initVariables();
public:
    ShopEngine();
    virtual ~ShopEngine();

    //Modifiers
    void addMoneytoBank(float& amount);
    void reduceMoneyFromBank(float& amount);

    //Accessors
    const bool& getMoneyInBank() const;
    const float& getPriceOfSeed(int index) const;
    const bool& getBuyIsPossible(float price);

    void 

    void update();
};