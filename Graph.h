#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "units.h"
#include "Eat.h"

class Graph{
public:
    bool isOpen = true;
    const int Width = 1000;
    const int Height = 100;
    const int FRAMERATE = 100;
    const int EatRadius = 15;
    const int UnitRadius = 25;
    sf::Event ev;
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1000,100), "Test game");
    Graph(){
        this->window.setFramerateLimit(FRAMERATE);
    }
    void update(){
        this->isOpen = this->window.isOpen();
        while(this->window.pollEvent(this->ev)){
            switch(this->ev.type){
            case sf::Event::Closed:
                this->window.close();
                break;
            }
        }
    }
    void render(std::vector<Units>units, std::vector<Eat>eat){
        this->window.clear(sf::Color(55,55,200));

        for(int i = 0; i < eat.size(); i++){
            sf::CircleShape circle(this->EatRadius);
            circle.setPosition(eat[i].x - this->EatRadius, this->Height / 2 - this->EatRadius);
            circle.setFillColor(sf::Color(250, 250, 50));
            this->window.draw(circle);
        }

        for(int i = 0; i < units.size(); i++){
            sf::CircleShape circle(this->UnitRadius);
            circle.setPosition(units[i].x - this->UnitRadius, this->Height / 2 - this->UnitRadius);
            circle.setFillColor(sf::Color(50, 200, 0));
            this->window.draw(circle);
        }

        this->window.display();
    }
};