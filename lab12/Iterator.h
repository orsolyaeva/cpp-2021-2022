//
// Created by David on 12/13/2021.
//

#ifndef LAB12_ITERATOR_H
#define LAB12_ITERATOR_H

#include "OrderedList.h"

template <class T, class LessComp, class Equal>
class Iterator {
    OrderedList<T, LessComp, Equal>& list;
    typename OrderedList<T, LessComp, Equal>::Node* act;
public:
    explicit Iterator(OrderedList<T, LessComp, Equal> &list) : list(list) {
        act = list.first;
    }
    bool hasNext();
    T next();
};

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
    return this->act->next != nullptr;
}

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
    auto temp = this->act;
    this->act = this->act->next;
    return temp->value;
}


#endif //LAB12_ITERATOR_H
