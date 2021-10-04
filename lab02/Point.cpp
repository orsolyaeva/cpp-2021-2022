//
// Created by Orsi on 9/27/2021.
//

#include "Point.h"

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

void Point::print() const {
    cout << "(" << x << ", " << y << ") ";
}

// function to calculate the distance between two points
double distance(const Point& a, const Point& b) {
    return sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
}

// function to check if tree points are collinear
bool collinear(const Point& a, const Point& b, const Point& c) {
   if(a.getX() == b.getX() && a.getX() == c.getX()) {
       return true;
   }

   if(a.getY() == b.getY() && a.getY() == c.getY()) {
       return true;
   }

   return false;
}

// function to check if four points can form a square
// this function only works if the parameters (points) are in a specific order (A, B, C, D)
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d) {

    // if any three points are collinear
    if(collinear(a, b, c) || collinear(a, b, d) || collinear(b, c, d)) {
        return false;
    }

    double side1 = distance(a, b);
    double side2 = distance(b, c);
    double side3 = distance(c, d);
    double side4 = distance(d, a);
    double diagonal1 = distance(a, c);
    double diagonal2 = distance(b, d);

    // if any distance is equal to 0 (it does not exist) they could not form a square
    if(side1 == 0 || side2 == 0 || side3 == 0 || side4 == 0 || diagonal2 == 0 || diagonal1 == 0) {
        return false;
    }

    /*
     In the case of floating-point numbers, the relational operator ('==') does not produce correct output
     If we do want to compare two double values we should find the absolute difference between the numbers and compare
     it with a very small number (epsilon). If the difference is less than this number, we can safely say that
     the 2 compared values are equal
     */
    if(fabs(side1 - side2) < DBL_EPSILON && fabs(side2 - side3) < DBL_EPSILON && fabs(diagonal1 - diagonal2) < DBL_EPSILON) {
        // if 3 sides and the diagonals are equal we can assume that the four given points can form a square
        return true;
    }

    return false;
}

void testIsSquare(const char * filename) {
    ifstream fin(filename);

    if(!fin) {
        exit(2);
    }

    int x, y;
    Point * square = new Point[4];

    while(!fin.eof()) {
        for(int i = 0; i < 4; i++) {
            fin >> x >> y;
            square[i] = Point(x, y);
        }

        printArray(square, 4);
        isSquare(square[0], square[1], square[2], square[3]) ? cout << "\tYES" : cout << "\tNO";
        cout << endl;
    }

    fin.close();
}

// function to create array which contains a given number of random generated points
Point* createArray(int numPoints) {
    Point * points = new Point[numPoints];

    srand(time(nullptr));

    int x, y;
    for(int i = 0; i < numPoints; i++) {
        x = rand() % 2001;
        y = rand() % 2001;

        points[i] = Point(x, y);
    }

    return points;
}

// function to print array of points
void printArray(Point* points, int numPoints) {
    if(numPoints == 0) {
        cout << "The array is empty! Please create one by pressing number 2" << endl;
        return;
    }

    for (int i = 0; i < numPoints; i++) {
        points[i].print();
    }
}

// sorting function according to X coordinate
int compareX(const void * a, const void * b) {
    Point *p1 = (Point *) a;
    Point *p2 = (Point *) b;

    return p1->getX() - p2->getX();
}

// sorting function according to Y coordinate
int compareY(const void * a, const void * b) {
    Point *p1 = (Point *) a;
    Point *p2 = (Point *) b;

    return p1->getY() - p2->getY();
}

// function to find the closest pair of points in an array of points
// note: it only works efficiently in case of small arrays
double smallestDistance(pair<Point, Point> &closestPair, Point* points, int numPoints) {
    double minimum = DBL_MAX;

    for(int i = 0; i < numPoints; i++) {
        for(int j = i + 1; j < numPoints; j++) {
            double dist = distance(points[i], points[j]);
            if(dist < minimum) {
                minimum = dist;
                closestPair.first = points[i];
                closestPair.second = points[j];
            }
        }
    }

    return minimum;
}

double findClosestPointsHelp(pair<Point, Point> &closestPair, Point* points, int numPoints, double dist) {
    double min = dist; // they all have a minimum distance (dist)

    // points are sorted according to their y coordinate
    qsort(points, numPoints, sizeof(Point), compareY);

    // find the closest points of given array
    for(int i = 0; i < numPoints; i++) {
        for(int j = i + 1; j < numPoints && min > (points[j].getY() - points[i].getY()); j++) {
           double dist1 = distance(points[i], points[j]);
           // find the points where the difference between the y coordinates is smaller than dist
           if(dist1 < min) {
               min = dist1;
               closestPair.first = points[i];
               closestPair.second = points[j];
           }
        }
    }

    return min;
}

double findClosestPoints(pair<Point, Point> &closestPair, Point* points, int numPoints) {
    pair<Point, Point> pair1, pair2;

    // if there are 3 or less points we can use the brute force method
    if(numPoints <= 3) {
        return smallestDistance(closestPair, points, numPoints);
    }

    int middle = numPoints / 2;
    Point middle_point = points[middle];

    // calculate the smallest distance on left and on the right side of the middle point
    double left = findClosestPoints(pair1, points, middle);
    double right = findClosestPoints(pair2, points + middle, numPoints - middle);

    double dist = min(left, right); // smaller of the above two

    if(left < right) {
        closestPair = pair1;
    } else {
        closestPair = pair2;
    }

    Point temp[numPoints];
    int j = 0;

    // build an array that contains points with smaller distance than dist
    for(int i = 0; i < numPoints; i++) {
        if(abs(points[i].getX() - middle_point.getX()) < dist) {
            temp[j] = points[i];
            j++;
        }
    }

    // find the minimum distance in the array above
    double min_strip = findClosestPointsHelp(pair1, temp, j, dist);

    // if its smaller than the actual distance
    if(min_strip < dist) {
        closestPair = pair1;
    }

    return min_strip;
}

pair<Point, Point> closestPoints(Point* points, int numPoints) {
    qsort(points, numPoints, sizeof(Point), compareX);

    pair<Point, Point> closestPair;

    findClosestPoints(closestPair, points, numPoints);

    return closestPair;
}

// sorting function according to X coordinate
int compareXDesc(const void * a, const void * b) {
    Point *p1 = (Point *) a;
    Point *p2 = (Point *) b;

    return p2->getX() - p1->getX();
}

// sorting function according to Y coordinate
int compareYDesc(const void * a, const void * b) {
    Point *p1 = (Point *) a;
    Point *p2 = (Point *) b;

    return p2->getY() - p1->getY();
}

// function to find the farthest pair of points in an array of points
// note: it only works efficiently in case of small arrays
double greatestDistance(pair<Point, Point> &farthestPair, Point* points, int numPoints) {
    double maximum = DBL_MIN;

    for(int i = 0; i < numPoints; i++) {
        for(int j = i + 1; j < numPoints; j++) {
            double dist = distance(points[i], points[j]);
            if(dist > maximum) {
                maximum = dist;
                farthestPair.first = points[i];
                farthestPair.second = points[j];
            }
        }
    }

    return maximum;
}

double findFarthestPointsHelp(pair<Point, Point> &farthestPair, Point* points, int numPoints, double dist) {
    double max = dist; // they all have a maximum distance (dist)

    // points are sorted according to their y coordinate
    qsort(points, numPoints, sizeof(Point), compareYDesc);

    // find the farthest points of given array
    for(int i = 0; i < numPoints; i++) {
        for(int j = i + 1; j < numPoints && max < (points[j].getY() - points[i].getY()); j++) {
            double dist1 = distance(points[i], points[j]);
            // find the points where the difference between the y coordinates is greater than dist
            if(dist1 > max) {
                max = dist1;
                farthestPair.first = points[i];
                farthestPair.second = points[j];
            }
        }
    }

    return max;
}

double findFarthestPoints(pair<Point, Point> &farthestPair, Point* points, int numPoints) {
    pair<Point, Point> pair1, pair2;

    // if there are 3 or less points we can use the brute force method
    if(numPoints <= 3) {
        return greatestDistance(farthestPair, points, numPoints);
    }

    int middle = numPoints / 2;
    Point middle_point = points[middle];

    // calculate the greatest distance on left and on the right side of the middle point
    double left = findFarthestPoints(pair1, points, middle);
    double right = findFarthestPoints(pair2, points + middle, numPoints - middle);

    double dist = max(left, right); // greater of the above two

    if(left > right) {
        farthestPair = pair1;
    } else {
        farthestPair = pair2;
    }

    Point temp[numPoints];
    int j = 0;

    // build an array that contains points with greater distance than dist
    for(int i = 0; i < numPoints; i++) {
        if(abs(points[i].getX() - middle_point.getX()) > dist) {
            temp[j] = points[i];
            j++;
        }
    }

    // find the maximum distance in the array above
    double max_strip = findFarthestPointsHelp(pair1, temp, j, dist);

    // if its greater than the actual distance
    if(max_strip > dist) {
        farthestPair = pair1;
    }

    return max_strip;
}

pair<Point, Point> farthestPoints(Point* points, int numPoints) {
    qsort(points, numPoints, sizeof(Point), compareXDesc);

    pair<Point, Point> farthestPair;

    findFarthestPoints(farthestPair, points, numPoints);

    return farthestPair;
}

bool operator<(const Point& a, const Point& b) {
    return a.getX() < b.getX();
}

// function to sort array of points according to X coordinate
void sortPoints(Point* points, int numPoints) {
    if(numPoints == 0) {
        cout << "The array is empty! Please create one by pressing number 2." << endl;
        return;
    }

    vector<Point> pointsV (points, points + numPoints);
    sort(pointsV.begin(), pointsV.end());

    for(auto it : pointsV) {
        it.print();
    }
}

void printArray(double * array, int length) {
    for(int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout<< endl;
}

void insert(Point *points, double *distances, Point point, double value) {
   if(distances[9] == 0) { // if the array is empty
       distances[9] = value;
       points[9] = point;
   } else {
       for(int i = 0; i < 9; i++) {
           if(value >= distances[i + 1]) {
               distances[i] = distances[i + 1];
               points[i] = points[i + 1];
           } else {
               distances[i] = value;
               points[i] = point;
               break;
           }
       }

       if(value > distances[9]) {
           distances[9] = value;
           points[9] = point;
       }
   }
}

Point* farthestPointsFromOrigin(Point* points, int numPoints) {
    Point * farthestPoints = new Point[10];
    double distances[10] = {0};
    Point origo;

    if(numPoints <= 10) {
        return points;
    }


    for(int i = 0; i < numPoints; i++) {
        double dist = distance(origo, points[i]);
        if(dist > distances[0]) {
            insert(farthestPoints, distances, points[i], dist);
        }
    }

    return farthestPoints;
}

void deletePoints(Point* points) {
    delete[] points;
}

void printExercises() {
    cout << "1. Test if 4 points form a Square (File)" << endl;
    cout << "2. Generate N point array" << endl;
    cout << "3. Print Array" << endl;
    cout << "4. Closest pair of points" << endl;
    cout << "5. Farthest pair of points" << endl;
    cout << "6. Sort array according to X coordinate" << endl;
    cout << "7. First 10 farthest points from Origin" << endl;
    cout << "8. Free arrays (delete)" << endl;
    cout << "9. Exit" << endl;
}