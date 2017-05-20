//
// Created by Piotrek on 21.04.2017.
//

#include <iostream>
#include "Point.h"
#include "Point3D.h"

int main(void) {
    Point point2d(2.0, 4.0);
    Point3D point3d(1.0, 5.0, 9.0);
    /* 6.
     * zostanie wykonana metoda Distance z klasy Point, przez co punkt 3d zostanie potraktowany jako punkt 2d,
     * wzieta zostanie jego wspolrzedna x i y, i na tej podstawie policzona zostanie odleglosc dwoch punktow
     * od siebie, dzieje sie tak, poniewaz metode distance wykonujemy na punkcie 2d, a zostaje ona wykonana,
     * poniewaz Point3D dziedziczy po klasie Point i moze zostac przekazany do tej metody jako argument */
    std::cout << "Distance" << point2d.Distance(point3d) << std::endl;

    /* 7.
     * zostanie wykonany operator << z klasy Point, wypisana zostanie wspolrzedna x i y,
     * dzieje sie tak poniewaz klasa Point3D nie posiada tego operatora przeciazonego, a dziedziczy ten operator
     * po klasie Point */
    std::cout << point3d << std::endl;

    /* 5.
     *  1. point2d zostaje tworzony: wykonuje sie konstruktor parametrowy Point
     *  2. point3d zostaje tworzony: wykonuje sie konstruktor bezparametrowy Point
     *                              wykonuje sie konstruktor parametrowy Point3D
     *  3. point3d zostaje unicestwiony: wykonuje sie destruktor 3d
     *                                  wykonuje sie destruktor 2d
     *  4. point2d zostaje unicestwiony: wykonuje sie destruktor 2d
     *
     * point2d zachowuje sie standardowo, point3d najpierw wywoluje konstruktor bezparametrowy Point, poniewaz
     * dziedziczy z tej klasy, nastepnie wywoluje konstruktor parametrowy Point3D, majac juz dostep do metod z klasy Point
     * i miejsce w pamieci na wspolrzedne punktu, przypisuje te wspolrzedne do zmiennych
     *
     * destruktory wykonuja sie w odwrotnej kolejnosci, najpierw destruktor klasy Point3D, nastepnie klasy Point,
     * z ktorej Point3D dziedziczylo
     * */
}