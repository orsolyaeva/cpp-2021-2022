//
// Created by Orsi on 10/9/2021.
//

#ifndef LAB3_LIST_H
#define LAB3_LIST_H

#include <iostream>
using namespace std;

class List {
    public:
        /* creates an empty list */
            List();
        /* destroys this list */
            ~List();
        /* returns true if d is in the list - complexity: O(n) */
            bool exists(int d) const;
        /* returns the size of the list - complexity: O(1) */
            int size() const;
        /* returns true if the list is empty - complexity: O(1) */
            bool empty() const;
        /* inserts d into this list as the first element - complexity: O(1) */
            void insertFirst(int d);
        /* removes the first element of the list - complexity: O(1) */
        /* throws an exception in case of empty list*/
            int removeFirst();
        /* removes the first element less than/equal to/greater than d,
        depending on the value of df. Does nothing if there is no value
        to remove. The enum values are accessed with List::DeleteFlag::LESS,
        ..., outside the class */
            enum class DeleteFlag {
                LESS, EQUAL, GREATER
            };
            void remove(int d, DeleteFlag df = DeleteFlag::EQUAL);
        /* prints the contents of this list */
            void print() const;
        /* forbid copying of lists */
            List(const List&) = delete;
            List& operator= (const List&) = delete;
    private:
        /* number of nodes in the list */
            int nodeCounter{0};
        /* a list node */
            struct Node {
                int value; // the node value
                Node* next; // pointer to the next node, nullptr in the last node
                Node(int v, Node* n) : value(v), next(n) {
                }
            };
            Node* first{}; // pointer to the first node
};

class Stack {
    public:
        /* inserts e into the stack - complexity: O(1) */
            void push(int e);
        /* removes the top (first) element of the stack- complexity: O(1) */
        /* throws an exception in case of empty stack */
            int pop();
        /* returns true if the stack is empty - complexity: O(1) */
            bool isEmpty() const;
        /* prints the contents of the stack */
            void print() const;

    private:
        List list; // an instance of the List class
};


/*   Functions used in the user interface    */

enum {SINGLY_LINKED_LIST = 1, STACK = 2}; /* enum to store the data structure options of the User */

void printOptions();

void printLinkedListExercises(); /* print all implemented tasks you can do with the linked list */
void executeLinkedListExercises(); /* user interface of the list + execution of exercises */

void printStackExercises(); /* print all implemented tasks you can do with the stack */
void executeStackExercises(); /* user interface of the stack + execution of exercises */

#endif //LAB3_LIST_H
