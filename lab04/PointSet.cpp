//
// Created by Orsi on 10/11/2021.
//

#include "PointSet.h"

void PointSet::computeDistances() {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
           this->distances.emplace_back(this->points[i].distanceTo(this->points[j]));
        }
    }
}

PointSet::PointSet(int n) : n(n) {
    random_device rd; // seed the random number generator named rd
    // random_device() is slower than mt19937, but it does not need to be seeded because it requests random data from your operating system
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range

    this->points.reserve(n);
    int x, y;

    while (this->points.size() < n) {
        x = dist(mt); y = dist(mt);

        if( !stat[x][y] ) {
            this->points.emplace_back(dist(mt), dist(mt));
            stat[x][y] = true;
        }
    }

    this->points.reserve((n * (n - 1)) / 2);
    this->computeDistances();
}

double PointSet::maxDistance() const {
    return *max_element(this->distances.begin(), this->distances.end());
}

double PointSet::minDistance() const {
    return *min_element(this->distances.begin(), this->distances.end());
}

int PointSet::numDistances() const {
    // it can return (n * (n - 1)) / 2;
    return this->distances.size();
}

void PointSet::printPoints() const {
    for(auto & point : this->points) {
        cout << "( " << point.getX() << ", " << point.getY() << " )" << endl;
    }
}

void PointSet::printDistances() const {
    for(auto & distance : this->distances) {
        cout << distance << " ";
    }
    cout << endl;
}

void PointSet::sortPointsX() {
    sort(this->points.begin(), this->points.end(),
         [] (const Point& a, const Point& b) {
        return a.getX() < b.getX();
    });
}

void PointSet::sortPointsY() {
    sort(this->points.begin(), this->points.end(),
         [] (const Point& a, const Point& b) {
             return a.getY() < b.getY();
         });
}

void PointSet::sortDistances() {
    sort(this->distances.begin(), this->distances.end());
}

int PointSet::numDistinctDistances() {
    auto it = unique(this->distances.begin(), this->distances.end());
    return distance(this->distances.begin(), it);
}
