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

    float bank;
    void initVariables();
public:
    ShopEngine();
    virtual ~ShopEngine();

    //Modifiers
    void addMoneytoBank(float& amount const);
    void reduceMoneyFromBank(float& amount const);

    //Accessors
    const bool& getMoneyFromBank() const;
    const float& getPriceOfSeed(int index) const;
}