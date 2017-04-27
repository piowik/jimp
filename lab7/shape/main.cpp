//
// Created by Piotrek on 21.04.2017.
//

#include <list>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

using std::list;
int main(void) {
    srand(time(NULL));
    list<Shape*> shapesList;

    for (int i = 0; i < 30; ++i) {
        int rand = std::rand()%3;
        switch(rand) {
            case 0: {
                shapesList.emplace_back(new Circle);
                break;
            }
            case 1: {
                shapesList.emplace_back(new Square);
                break;
            }
            case 2: {
                shapesList.emplace_back(new Triangle);
                break;
            }
        }
    }
    for (auto shape : shapesList) {
        shape->Rysuj();
        std::cout << std::endl;
    }

    /* efekt - ksztalty zostaja wyrysowane, poniewaz kolo, kwadrat jak i trojkat nadpisuja wirtualna metode rysuj */
}