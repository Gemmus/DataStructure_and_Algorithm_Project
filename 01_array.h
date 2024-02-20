#include <iostream>
#include <stdexcept>

#define MAX 100

using namespace std;

/***************************************/
/*        class List interface         */
/***************************************/
template <class T>
class List {
public:
    List();
    ~List() = default;
    const T &operator[](const int& index) const;
    void printer() const;
    void sort();
    bool insertToEnd(T item);                           // For linear search
    bool findIndexLinear(T item, int& index) const;     // For linear search
    bool insertOrdered(T item);                         // For binary search
    bool findIndexBinary(T item, int& index) const ;    // For binary search

private:
    int     arrayCounter;
    T       array[MAX];

    void quickSort(int low, int high);
    int partition(int low, int high);
};

/***************************************/
/*      class List implementation      */
/***************************************/
template <class T>
List<T>::List() {
    arrayCounter = 0;
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
void List<T>::printer() const {
    for (int i = 0; i < arrayCounter; i++) {
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

template <class T>
void List<T>::sort() {
    quickSort(0, arrayCounter - 1);
}

template <class T>
void List<T>::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

template <class T>
int List<T>::partition(int low, int high) {
    T pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
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
bool List<T>::findIndexLinear(T item, int &index) const {
    if (arrayCounter > 0) {
        for (int i = 0; i < arrayCounter; i++) {
            if (array[i] == item) {
                index = i;
                return true;
            }
        }
    }
    return false;
}

template <class T>
bool List<T>::insertOrdered(T item) {
    if (arrayCounter >= MAX) {
        return false;
    }

    int i = arrayCounter - 1;
    while (i >= 0 && array[i] > item) {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = item;
    arrayCounter++;
    return true;
}

template <class T>
bool List<T>::findIndexBinary(T item, int& index) const {
    /* Ensure array is sorted */
    //sort();

    int low = 0;
    int high = arrayCounter - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == item) {
            index = mid;
            return true;
        }
        if (array[mid] < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}
