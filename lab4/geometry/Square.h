//
// Created by Piotrek on 23.03.2017.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"

namespace geometry {


    class Square {
    public:
        //Konstruktor bezparametrowy
        Square(Point p1, Point p2, Point p3, Point p4);
        //Destruktor wykonywany przed zwolnieniem pamięci
        ~Square();

        //Metody nie modyfikujące stanu obiektu (const na końcu metody)
        //nie mogą zmodyfikować tego obiektu.
        double Area() const;
        double Circumference() const;

    private:
        //w przeciwienstwie do pythona C++ wymaga jawnej deklaracji składowych pól klasy:
        Point p1_, p2_, p3_, p4_;
    };
}

#endif //JIMP_EXERCISES_SQUARE_H
