#include "functions.h"

int main() {
    int exercise;
    printExercises();
    while(true){
        cout << endl << endl << "Enter the number of the exercise (to exit enter 11):";
        cin >> exercise;
        switch (exercise) {
            case 1: exercise1(); break;
            case 2: exercise2(); break;
            case 3: exercise3(); break;
            case 4: exercise4(); break;
            case 5: exercise5(); break;
            case 6: exercise6(); break;
            case 7: exercise7(); break;
            case 8: exercise8(); break;
            case 9: exercise9(); break;
            case 10: exercise10(); break;
            case 11: exit(0);
            default:{
                cout << "Something went wrong...please try again!" << endl;
                break;
            }
        }
    }
}

