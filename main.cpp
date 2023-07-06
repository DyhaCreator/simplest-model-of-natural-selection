#include <iostream>
#include <vector>
#include "Graph.h"

int main(){
    const int EAT_COUNT = 10;
    Graph gr = Graph();
    std::vector<Eat>eat = std::vector<Eat>();
    for(int i = 0; i < EAT_COUNT; i++){
        int x = rnd(0, gr.Width);
        //std::cout << x << std::endl;
        Eat e = Eat(x);
        eat.push_back(e);
    }
    std::vector<Units>units = std::vector<Units>();
    Units unit = Units(0,1,1);
    units.push_back(unit);
    while(gr.isOpen){
        gr.update();
        for(int i = 0; i < units.size(); i ++){
            units[i].update();
            for(int j = 0; j < eat.size(); j++){
                if(units[i].x > eat[j].x){
                    eat[j].x += gr.Width + rnd(0, 100);
                }
            }
        }
        gr.render(units, eat);
    }
}