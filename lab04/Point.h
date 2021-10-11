//
// Created by Orsi on 10/11/2021.
//

#ifndef LAB4_POINT_H
#define LAB4_POINT_H
#define M 2000

#include <iostream>
#include <cmath>
#include <random>

using namespace std;

class Point{
    private:
        int x, y;
    public:
        Point( int x=0, int y=0);
        int getX() const;
        int getY() const;
        double distanceTo(const Point& point)const;
};


#endif //LAB4_POINT_H
