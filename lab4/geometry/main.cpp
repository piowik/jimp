//
// Created by Piotrek on 23.03.2017.
//


#include <iostream>
#include "Square.h"
#include <memory>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;


using namespace geometry;
int main(void){
    Point tp1(0,1);
    Point tp2(0,0);
    Point tp3(1,1);
    Point tp4(1,0);
    Square sq(tp1,tp2,tp3,tp4);
    cout << sq.Area() << endl;
    cout << sq.Circumference() << endl;

}