#include <iostream>

class Units{
public:
    //vars
    int x, eat;
    //gens
    int gen_speed;
    Units(int x, int gen_speed, int start_eat){
        this->x = x;
        this->gen_speed = gen_speed;
        this->eat = start_eat;
    }
    void update(){
        x += gen_speed;
    }
};