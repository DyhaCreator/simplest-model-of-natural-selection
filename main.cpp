#include "Graph.h"

int main(){
    Graph gr = Graph();
    while(gr.isOpen){
        gr.update();
        gr.render();
    }
}