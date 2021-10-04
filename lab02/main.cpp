#include "Point.h"

/*
 EXTRA EXERCISE - NOTE : The function runs well on inputs that contain no more than 100K points, above that
 there seems to be a memory limitation that makes the program crash.
 */

int main() {
    int exercise;
    printExercises();
    int N;
    Point * points;


    while(true){
        cout << endl << endl << "Enter the number of the exercise (to exit enter 11):";
        cin >> exercise;
        switch (exercise) {
            case 1: testIsSquare("points.txt"); break;
            case 2: {
                cout << "Enter N: ";
                cin >> N;
                points = createArray(N);
                break;
            }
            case 3: printArray(points, N); break;
            case 4: {
                cout << "Enter the number of Points: ";
                cin >> N;
                points = createArray(N);
                pair<Point, Point> pointsT;

                pointsT = closestPoints(points, N);

                cout << "Closest pair of points: ";
                pointsT.first.print();
                pointsT.second.print();
                break;
            }
            case 5: {
                cout << "Enter the number of Points: ";
                cin >> N;
                points = createArray(N);
                pair<Point, Point> pointsT;

                pointsT = farthestPoints(points, N);

                cout << "Farthest pair of points: ";
                pointsT.first.print();
                pointsT.second.print();
                break;
            }
            case 6: {
                cout << "Enter the number of Points: ";
                cin >> N;
                points = createArray(N);

                sortPoints(points, N);
                break;
            }
            case 7: {
                cout << "Enter the number of Points: ";
                cin >> N;
                points = createArray(N);

                if(N <= 10) {
                    printArray(farthestPointsFromOrigin(points, N), N);
                } else {
                    printArray(farthestPointsFromOrigin(points, N), 10);
                }

                break;
            }
            case 8: deletePoints(points); break;
            case 9: exit(0);
            default:{
                cout << "Something went wrong...please try again!" << endl;
                break;
            }
        }
    }
}
