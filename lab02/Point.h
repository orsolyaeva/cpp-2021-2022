//
// Created by Orsi on 9/27/2021.
//

#ifndef LAB2_POINT_H
#define LAB2_POINT_H

#include <iostream>
#include <cmath>
#include <ctime>
#include <cfloat>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class Point {
    private:
        int x, y;
    public:
        explicit Point(int x = 0, int y = 0);
        int getX() const;
        int getY() const;
        void print() const;
};

double distance(int a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
void testIsSquare(const char * filename);
bool collinear(const Point& a, const Point& b, const Point& c, const Point& d);
pair<Point, Point> closestPoints(Point* points, int numPoints);
int compareX(const void * a, const void * b);
int compareY(const void * a, const void * b);
double smallestDistance(pair<Point, Point> &closestPair, Point* points, int numPoints);
double findClosestPointsHelp (pair<Point, Point> &closestPair, Point* points, int numPoints, double dist);
double findClosestPoints(pair<Point, Point> &closestPair, Point* points, int numPoints);
int compareXDesc(const void * a, const void * b);
int compareYDesc(const void * a, const void * b);
double greatestDistance(pair<Point, Point> &farthestPair, Point* points, int numPoints);
double findFarthestPointsHelp(pair<Point, Point> &farthestPair, Point* points, int numPoints, double dist);
double findFarthestPoints(pair<Point, Point> &farthestPair, Point* points, int numPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
bool compareXHelp(const Point& a, const Point& b);
void sortPoints(Point* points, int numPoints);
bool operator<(const Point& a, const Point& b);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void insert(Point *&points, double *&distances, Point point, double value);
void deletePoints(Point* points);
void printExercises();

#endif //LAB2_POINT_H
