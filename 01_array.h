#include <iostream>
#include <stdexcept>

#define MAX 100

using namespace std;

template <class T>
class List {
public:
    List();
    ~List() = default;
    bool isEmpty();
    int sizeGetter();
    const T &operator[](const int& index) const;
    bool insertToEnd(T item);
    bool findIndex(T item, int& index);
    void printer();

private:
    int arrayCounter;
    T array[MAX];
};

template <class T>
List<T>::List() {
    arrayCounter = 0;
}

template <class T>
bool List<T>::isEmpty() {
    if (arrayCounter == 0) {
        return true;
    } else {
        return false;
    }
}

template <class T>
int List<T>::sizeGetter() {
    return arrayCounter;
}

template <class T>
const T &List<T>::operator[](const int& index) const {
    if (arrayCounter > 0 && index < arrayCounter) {
        return array[index];
    } else {
        throw range_error("Index error.");
    }
}

template <class T>
bool List<T>::insertToEnd(T item) {
    if (arrayCounter < MAX) {
        array[arrayCounter++] = item;
        return true;
    } else {
        return false;
    }
}

template <class T>
bool List<T>::findIndex(T item, int& index) {
    for (int i = 0; i < MAX; i++) {
        if (array[i] == item) {
            index = i;
            return true;
        }
    }
    return false;
}

template <class T>
void List<T>::printer() {
    for (int i = 0; i < arrayCounter; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}