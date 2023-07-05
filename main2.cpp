#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
    const int Width = 1000;
    const int Height = 600;

    sf::RenderWindow window(sf::VideoMode(Width, Height), "Test game");
    window.setFramerateLimit(500);
    sf::Event ev;

    //Game loop

    sf::CircleShape shape;
    float x = 100.f;
    float y = 100.f;
    float speedX = 1.f;
    float speedY = 1.f;
    float radius = 30;
    //enemy.setPosition();

    while(window.isOpen()){
        while(window.pollEvent(ev)){
            switch(ev.type){
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(ev.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }
        }
        //Update

        //Render
        window.clear(sf::Color(0,0,255));

        //Draw game
        shape.setFillColor(sf::Color(255,0,0));
        shape.setPosition(sf::Vector2f(x - radius, y - radius));
        shape.setRadius(radius);
        
        window.draw(shape);

        x += speedX;
        y += speedY;

        if(y >= Height - radius)speedY = -speedY;
        if(y <= radius)speedY = -speedY;
        if(x >= Width - radius)speedX = -speedX;
        if(x <= radius)speedX = -speedX;

        window.display();
    }
    
    return 0;
}