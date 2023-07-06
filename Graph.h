#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "units.h"
#include "Eat.h"

class Graph{
public:
    bool isOpen = true;
    const int Width = 1080;
    const int Height = 720;
    const int FRAMERATE = 100;
    const int EatRadius = 10;
    const int UnitRadius = 25;
    int INDENT;
    sf::Event ev;
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1080,720), "Test game");
    Graph(){
        this->window.setFramerateLimit(FRAMERATE);
        this->INDENT = Width / 2;
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

        int max_x = 0;
        int indent_micro = INDENT;

        for(int i = 0; i < units.size(); i ++){
            if(units[i].x > max_x){
                max_x = units[i].x;
            }
        }
        if(max_x < this->INDENT){
            max_x = 0;
            indent_micro = 0;
        }

        for(int i = 0; i < eat.size(); i++){
            sf::CircleShape circle(this->EatRadius);
            circle.setPosition(eat[i].x - this->EatRadius - max_x + indent_micro, this->Height / 2 - this->EatRadius);
            circle.setFillColor(sf::Color(250, 250, 50));
            this->window.draw(circle);
        }

        for(int i = 0; i < units.size(); i++){
            sf::CircleShape circle(this->UnitRadius);
            circle.setPosition(units[i].x - this->UnitRadius - max_x + indent_micro, this->Height / 2 - this->UnitRadius);
            circle.setFillColor(sf::Color(50, 200, 0));
            this->window.draw(circle);
        }

        this->window.display();

        std::cout << units[0].eat << std::endl;
    }
};