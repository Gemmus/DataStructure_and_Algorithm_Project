#include <iostream>
#include <stdexcept>

#define MAX 100000

using namespace std;

/***************************************/
/*       class CircList interface      */
/***************************************/
template <class T>
class CircList {
public:
    CircList();
    ~CircList() = default;
    const T &operator[](const int& index) const;
    void printer() const;
    void sort();
    bool insertToEnd(T item);                           // For linear search
    bool findIndexLinear(T item, int& index) const;     // For linear search
    bool insertOrdered(T item);                         // For binary search
    bool findIndexBinary(T item, int& index) const ;    // For binary search

private:
    int first;
    int last;
    int clCounter;
    T array[MAX];

    void quickSort(int low, int high);
    int partition(int low, int high);
};

/***************************************/
/*      class List implementation      */
/***************************************/
template <class T>
CircList<T>::CircList() {
    first = 0;
    last = -1;
    clCounter = 0;
}

template <class T>
const T &CircList<T>::operator[](const int& index) const {
    if (clCounter > 0 && index < clCounter) {
        return array[index];
    } else {
        throw range_error("Index error.");
    }
}

template <class T>
void CircList<T>::printer() const {
    for (int i = 0; i < clCounter; i++) {
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

template <class T>
void CircList<T>::sort() {
    quickSort(0, clCounter - 1);
}

template <class T>
void CircList<T>::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

template <class T>
int CircList<T>::partition(int low, int high) {
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
bool CircList<T>::insertToEnd(T item) {
    if (clCounter < MAX) {
        if (++last > MAX - 1) {
            last = 0;
        }
        array[last] = item;
        clCounter++;
        return true;
    } else {
        return false;
    }
}

template <class T>
bool CircList<T>::findIndexLinear(T item, int &index) const {
    if (clCounter > 0) {
        for (int i = 0; i < clCounter; i++) {
            if (array[i] == item) {
                index = i;
                return true;
            }
        }
    }
    return false;
}

template <class T>
bool CircList<T>::insertOrdered(T item) {
    if (clCounter >= MAX) {
        return false;
    }

    if (clCounter == 0) {
        array[first] = item;
        last = first;
        clCounter++;
        return true;
    }

    int i = last - 1;
    while (i >= 0 && array[i] > item) {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = item;
    if (++last > MAX - 1) {
        last = 0;
    } else {
        last = clCounter;
    }
    clCounter++;
    return true;
}

template <class T>
bool CircList<T>::findIndexBinary(T item, int& index) const {
    /* Ensure array is sorted */
    //sort();

    int low = 0;
    int high = clCounter - 1;
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
