#include <SFML/Graphics.hpp>
#include <iostream>

class Graph{
public:
    bool isOpen = true;
    const int Width = 1000;
    const int Height = 600;
    sf::Event ev;
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1000,600), "Test game");
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
    void render(){
        this->window.clear(sf::Color(55,55,200));
        this->window.display();
    }
};