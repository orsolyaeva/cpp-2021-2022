//
// Created by Orsi on 10/11/2021.
//

#ifndef LAB4_POINTSET_H
#define LAB4_POINTSET_H

#include "Point.h"
#include <vector>
#include <algorithm>
using namespace std;

static bool stat[M][M] { false };

class PointSet {
    vector<Point> points; /* distinct points */
    int n; /* number of distinct points */
    vector <double> distances;  /* distances between the points */
    void computeDistances(); /* helper function to fill the distances vector */

public:
    /* constructor: creates the points array */
    /* compute the distances between the points (distances vector) */
        PointSet( int n = 100 );
    /* max distance from the vector*/
        double maxDistance() const;
    /* min distance from the vector */
        double minDistance() const;
    /* number of distances between n distinct points*/
        int numDistances() const;
    /* prints the content of the point vector*/
        void printPoints() const;
    /* prints the content of the distances vector*/
        void printDistances() const;
    /* sort the points according to X coordinate*/
        void sortPointsX();
    /* sort the points according to Y coordinate */
        void sortPointsY();
    /* sort the distances vector */
        void sortDistances();
    /* number of distinct distances in the distances vector*/
        int numDistinctDistances();

};

#endif //LAB4_POINTSET_H
