//
// Created by Piotrek on 21.04.2017.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include <ostream>

class Point {
public:
    Point();

    Point(double x, double y);

    ~Point();

    void ToString(std::ostream *out) const;

    double Distance(const Point &other) const;

    double GetX() const;

    double GetY() const;

    void SetX(double x);

    void SetY(double y);

    friend std::ostream &operator<<(std::ostream &stream, const Point &point) {
        stream << "(" << point.x_ << ";" << point.y_ << ")";
        return stream;
    }

private:
    double x_, y_;
};


#endif //JIMP_EXERCISES_POINT_H
