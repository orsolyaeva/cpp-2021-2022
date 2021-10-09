#include "List.h"

/*
 ANSWER: When you create/delete a stack both (stack and list) constructors/destructors are called.
 */

int main() {
    int data_structure;

    while(true) {
        printOptions();
        cout << "Choose the data structure you want to work with:";
        cin >> data_structure;

        switch (data_structure) {
            case SINGLY_LINKED_LIST: { executeLinkedListExercises(); break; }
            case STACK: { executeStackExercises(); break; }
            case 3: { exit(0); }
            default: { cout << "Something went wrong! Please try again!" << endl; break; }
        }
    }
}
