//
// Created by Piotrek on 21.04.2017.
//

#include <iostream>
#include <cmath>
#include "Point3D.h"

using std::cout;
using std::endl;

Point3D::Point3D(double x, double y, double z) {
    cout << "Konstruktor parametrowy 3d" << endl;
    SetX(x);
    SetY(y);
    z_ = z;
}

Point3D::Point3D() {
    cout << "Konstruktor bezparametrowy 3d" << endl;
}


Point3D::~Point3D() {
    cout << "Destruktor 3d";
    cout << endl;
}

double Point3D::GetZ() const {
    return z_;
}

void Point3D::SetZ(double z) {
    z_ = z;
}

double Point3D::Distance(const Point3D &other) const {
    return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2) + pow(GetZ() - other.GetZ(), 2));
}
