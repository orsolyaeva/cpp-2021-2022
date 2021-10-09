//
// Created by Orsi on 10/9/2021.
//

#include "List.h"

/* creates an empty list */
List::List() {
    this->first = nullptr;
}

/* destroys this list */
List::~List() {
    while(this->first != nullptr) { // go through the list
        auto prev = this->first;
        this->first = this->first->next;
        delete prev; // delete every node
    }
}

/* returns true if d is in the list - complexity: O(n) */
bool List::exists(int d) const {
    if(this->empty()) {
        return false;
    }

    for(auto temp = this->first; temp != nullptr; temp = temp->next) {
        if(temp->value == d) {
            return true;
        }
    }

    return false;
}

/* returns the size of the list - complexity: O(1) */
int List::size() const {
    return this->nodeCounter;
}

/* returns true if the list is empty - complexity: O(1) */
bool List::empty() const {
   return this->nodeCounter == 0;
}

/* inserts d into this list as the first element - complexity: O(1) */
void List::insertFirst(int d) {
    this->first = new Node(d, this->first);
    this->nodeCounter += 1; // increment the node counter
}

/* removes the first element of the list - complexity: O(1) */
/* throws an exception in case of empty list*/
int List::removeFirst() {
    if(this->first != nullptr) {
        auto temp = this->first;
        auto temp_value = this->first->value; // save the value of the first node so we can return it later
        this->first = this->first->next;
        delete temp;
        this->nodeCounter -= 1;

        return temp_value;
    } else {
        throw invalid_argument("The list is empty!");
    }
}

/* removes the first element less than/equal to/greater than d, depending on the value of df.
 * Does nothing if there is no value to remove. */
void List::remove(int d, List::DeleteFlag df) {
    if(this->empty()) {
        return;
    }

    if(this->size() == 1) {
        switch (df) {
            case DeleteFlag::LESS: {
                if (this->first->value < d) {
                    removeFirst();
                    return;
                }
            }
            case DeleteFlag::EQUAL: {
                if (this->first->value == d) {
                    removeFirst();
                    return;
                }
            }
            case DeleteFlag::GREATER: {
                if (this->first->value > d) {
                    removeFirst();
                    return;
                }
            }
        }

        return;
    }

    for(auto temp = this->first; temp->next!= nullptr; temp = temp->next) {
        switch (df) {
            case DeleteFlag::LESS: {
                if(this->first->value < d) { // if the element we search for is the first in the list
                    removeFirst();
                    return;
                }

                if(temp->next->value < d) {
                    auto node = temp->next->next;
                    delete temp->next;
                    temp->next = node;
                    this->nodeCounter -= 1;
                    return;
                }

                break;
            }
            case DeleteFlag::EQUAL: {
                if(this->first->value == d) {
                    removeFirst();
                    return;
                }

                if(temp->next->value == d) {
                    auto node = temp->next->next;
                    delete temp->next;
                    temp->next = node;
                    this->nodeCounter -= 1;
                    return;
                }

                break;
            }
            case DeleteFlag::GREATER: {
                if(this->first->value > d) {
                    removeFirst();
                    return;
                }

                if(temp->next->value > d) {
                    auto node = temp->next->next;
                    delete temp->next;
                    temp->next = node;
                    this->nodeCounter -= 1;
                    return;
                }

                break;
            }
        }
    }
}

/* prints the contents of this list */
void List::print() const {
    if(empty()) {
        cout << endl;
        return;
    }
    for(auto temp = this->first; temp != nullptr; temp = temp->next) {
        cout << temp->value << " ";
    }
    cout << endl;
}

/* inserts e into the stack - complexity: O(1) */
void Stack::push(int e) {
    this->list.insertFirst(e);
}

/* removes the top (first) element of the stack- complexity: O(1) */
/* throws an exception in case of empty stack */
int Stack::pop() {
    if(this->isEmpty()) {
        throw invalid_argument("The stack is empty!");
    } else {
        return this->list.removeFirst();
    }
}

/* returns true if the stack is empty - complexity: O(1) */
bool Stack::isEmpty() const {
    return list.empty();
}

/* prints the contents of the stack */
void Stack::print() const {
    this->list.print();
}


/* Functions used to create the user interface */

void printOptions() {
    cout << "1. Singly linked list" << endl;
    cout << "2. Stack" << endl;
    cout << "3. Exit" << endl;
}

/* print all implemented tasks you can do with the linked list */
void printLinkedListExercises() {
    cout << "1. Check if given value is in the list" << endl;
    cout << "2. Print the size of the list" << endl;
    cout << "3. Check if the list is empty" << endl;
    cout << "4. Insert element" << endl;
    cout << "5. Remove first element" << endl;
    cout << "6. Remove given element" << endl;
    cout << "7. Print list" << endl;
    cout << "8. Exit" << endl;
}

/* user interface of the list + execution of exercises */
void executeLinkedListExercises() {
    List list;
    int exercise;

    cout << endl;
    printLinkedListExercises();

    while(true) {
        cout << endl << "Enter the number of the exercise:";
        cin >> exercise;
        switch (exercise) {
            case 1: {
                int value;
                cout << "Enter the value:";
                cin >> value;

                cout << "Your question: Is " << value << " in the list?" << endl << "Answer:";

                list.exists(value) ? cout << " YES." << endl : cout << " NO." << endl;
                break;
            }
            case 2: {
                cout << "Current size of the list: " << list.size() << endl;
                break;
            }
            case 3: {
                cout << "Question: Is the list empty?" << endl << "Answer:";
                list.empty() ? cout << " YES." << endl : cout << " NO." << endl;
                break;
            }
            case 4: {
                int value;
                cout << "Enter the value you want to insert:";
                cin >> value;

                cout << "List before insertion: ";
                list.print();

                list.insertFirst(value);

                cout << "List after insertion: ";
                list.print();

                break;
            }
            case 5: {
                cout << "List before removal: ";
                list.print();

                try {
                    list.removeFirst();
                    cout << "List after removal: ";
                    list.print();
                } catch (const exception &e) {
                    cout << e.what() << endl;
                }

                break;
            }
            case 6: {
                int value, delete_flag;

                cout << "Enter the value you want to remove:";
                cin >> value;

                cout << endl << "1. LESS" << endl << "2. EQUAL" << endl << "3. GREATER" << endl;
                cout << endl << "Enter the removal criteria:";
                cin >> delete_flag;

                cout << "List before removal: ";
                list.print();

                switch (delete_flag) {
                    case 1: {
                        list.remove(value, List::DeleteFlag::LESS);
                        break;
                    }
                    case 2: {
                        list.remove(value, List::DeleteFlag::EQUAL);
                        break;
                    }
                    case 3: {
                        list.remove(value, List::DeleteFlag::GREATER);
                        break;
                    }
                    default: {
                        cout << "No flag found! Please try again!";
                        break;
                    }
                }

                cout << "List after removal: ";
                list.print();
                cout << endl;

                break;
            }
            case 7: {
                cout << "List: ";
                list.print();
                break;
            }
            case 8: {
                return;
            }
            default: {
                cout << "Something went wrong! Please try again!" << endl;
                break;
            }
        }
    }
}

/* print all implemented tasks you can do with the stack */
void printStackExercises() {
    cout << "1. Insert element" << endl;
    cout << "2. Remove element" << endl;
    cout << "3. Check if the stack is empty" << endl;
    cout << "4. Print stack" << endl;
    cout << "5. Exit" << endl;
}

/* user interface of the stack + execution of exercises */
void executeStackExercises() {
    Stack stack;
    int exercise;

    cout << endl;
    printStackExercises();

    while(true) {
        cout << endl << "Enter the number of the exercise:";
        cin >> exercise;
        switch (exercise) {
            case 1: {
                int value;
                cout << "Enter the value you want to insert:";
                cin >> value;

                cout << "Stack before insertion: ";
                stack.print();

                stack.push(value);

                cout << "Stack after insertion: ";
                stack.print();

                break;
            }
            case 2: {
                cout << "Stack before removal: ";
                stack.print();

                try {
                    stack.pop();
                    cout << "Stack after removal: ";
                    stack.print();
                } catch (const exception& e) {
                    cout << e.what() << endl;
                }

                break;
            }
            case 3: {
                cout << "Question: Is the stack empty?" << endl << "Answer:";
                stack.isEmpty() ? cout << " YES." << endl : cout << " NO." << endl;
                break;
            }
            case 4: {
                cout << "Stack: ";
                stack.print();
                break;
            }
            case 5: { return; }
            default: { cout << "Something went wrong! Please try again!" << endl; break; }
        }
    }
}