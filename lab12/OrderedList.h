//
// Created by David on 12/13/2021.
//

#ifndef LAB12_ORDEREDLIST_H
#define LAB12_ORDEREDLIST_H

#include <iostream>
#include <functional>
using namespace std;

//class Iterator<T, LessComp, Equal>;
template <class T, class LessComp = less<T>, class Equal = equal_to<T>>
class OrderedList {
    int numElements{0};
    struct Node {
        T value;
        Node * next;
        Node(T v, Node * n):value(v), next(n) {}
    };
    Node * first;
//    friend class Iterator<T, LessComp, Equal>;
public:
    OrderedList() { this->first = nullptr; };
    ~OrderedList();
    bool isEmpty() const { return this->numElements == 0; };
    void insert(const T& value);
    void remove(T& value);
    int size() const {  return this->numElements; };
    bool find(T& value);
    void listItems(ostream&);
};

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
    while(this->first != nullptr) {
        auto prev = this->first;
        this->first = this->first->next;
        delete prev;
    }
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(const T& value) {
    Node * current;
    if(this->first == nullptr || !(LessComp()(this->first->value, value))) {
        this->first = new Node(value, this->first);
        this->numElements += 1;
    } else {
        current = this->first;
        while(current->next != nullptr && LessComp()(current->next->value, value)) {
            current = current->next;
        }
        current->next = new Node(value, current->next);
        this->numElements += 1;
    }
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(T &value) {
    Node * temp = this->first;
    Node * prev = this->first;

    while(temp != nullptr) {
        if(Equal()(temp->value, value)) {
            if(temp == this->first) {
                this->first = temp->next;
                prev = this->first;
                delete temp;
                temp = this->first;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(T &value) {
    if(this->isEmpty()) {
        return false;
    }
    for(auto temp = this->first; temp != nullptr || temp->value <= value; temp = temp->next) {
        if(temp->value == value) {
            return true;
        }
    }

    return false;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream & os) {
    if(isEmpty()) {
        os << "The list is empty!" << endl;
        return;
    }

    os << "List: ";
    for(auto temp = this->first; temp != nullptr; temp = temp->next) {
        os << temp->value << " ";
    }
    os << endl;
}




#endif //LAB12_ORDEREDLIST_H
