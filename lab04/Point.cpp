//
// Created by Orsi on 10/11/2021.
//

#include "Point.h"

int Point::counter{0};

Point::Point(int x, int y) :  x (x >= 0 && x < M ? x : 0), y (y >= 0 && y < M ? y : 0)  {
    ++counter;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow(this->getX() -  point.getX(), 2) + pow(this->getY() - point.getY(), 2));
}

Point::Point(const Point &point) {
   this->x = point.getX();
   this->y = point.getY();
   ++counter;
}

