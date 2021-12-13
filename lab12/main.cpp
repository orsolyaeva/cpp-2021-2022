#include "OrderedList.h"

int main(int argc, char** argv) {
    OrderedList<int> list;
    for(int i = 0; i < 10; i++) {
        int v = rand() % 10;
        cout << v << " ";
        list.insert( v );
    }

    cout << endl;
    list.listItems(std::cout);

        int item;
        cout << "Enter item to remove: ";
        cin >> item;
        list.remove(item);
        list.listItems(std::cout);
}

