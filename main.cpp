#include <iostream>
#include <vector>
#include <cmath>
#include "Graph.h"
#include "random.h"

int main(){
    const int EAT_COUNT = 20;
    const int START_X = 0;
    const int START_SPEED = 1;
    const int START_EAT = 750;
    const int MAX_SAT = 100;
    const int MIN_SAT = MAX_SAT / 2;
    const float MAX_EV = 0.1;
    int frame = 0;
    Graph gr = Graph();
    std::vector<Eat>eat = std::vector<Eat>();
    for(int i = 0; i < EAT_COUNT; i++){
        int x = rnd(0, gr.Width);
        int sat = rnd(MIN_SAT, MAX_SAT);
        //std::cout << x << std::endl;
        Eat e = Eat(x, sat);
        eat.push_back(e);
    }
    std::vector<Units>units = std::vector<Units>();
    Units unit = Units(START_X, START_SPEED, START_EAT);
    units.push_back(unit);
    while(gr.isOpen){
        frame ++;
        gr.update();
        std::vector<int>indexes = std::vector<int>();
        for(int i = 0; i < units.size(); i++){
            units[i].update();
            if(units[i].eat <= 0){
                indexes.push_back(i);
            }
            if(units[i].eat > unit.EAT_TO_DIVISION){
                //std::cout << units[i].gen_speed + (float)rnd(0, MAX_EV * 10) / 10 << std::endl;
                Units new_unit = Units(units[i].x, units[i].gen_speed + (float)rnd(0, MAX_EV * 10) / 10, START_EAT);
                units[i].eat -= START_EAT;
                //std::cout << new_unit.gen_speed << std::endl;
                units.push_back(new_unit);
            }
            for(int j = 0; j < eat.size(); j++){
                if(units[i].x > eat[j].x){
                    eat[j].x += gr.Width + rnd(0, 100);
                    eat[j].sat = rnd(MIN_SAT, MAX_SAT);
                    units[i].eat += eat[j].sat;
                    //std::cout << units[i].eat << std::endl;
                }
            }
        }
        for(int i = 0; i < indexes.size(); i++){
            units = del(units, indexes[i] - i);
        }
        gr.render(units, eat, frame);
    }
}