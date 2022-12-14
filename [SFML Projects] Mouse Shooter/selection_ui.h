
#include<iostream>
#include<string>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Selection
{
private:
    bool Active;
    const std::string keys[2] = {"circle", "square"};
    std::string activatedShape;
    
    sf::Color color_selection;

    sf::CircleShape circle;
    sf::RectangleShape square;

    void initVariables();
    void initBaseCircle();
    void initBaseSquare();
public:
    Selection();
    virtual ~Selection();

    //Accessors

    //Key list: 1. Circle, 2.Square.
    const std::string& getKeyofShapes(int index) const;

    //Modifiers
    void activate();
    void deactivate();

    //Change size of square shape
    void changeSizeOfSquare(sf::Vector2f size);
    //Change radius of circle shape
    void changeRadiusOfCircle(float radius);
    //Change complete position of selection
    void changePositionOfSelection(sf::Vector2f& pos);
    //Change X Position of the selection
    void changePositionXOfSelection(float x);
    //Change Y Position of the selection
    void changePositionYOfSelection(float y);
    //Change shape of selection. Use getKeyOfShapes function for no mistakes.
    void changeShapeOfSelection(std::string& shape);

    void update();

    void renderSelection(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
};
