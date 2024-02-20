using namespace std;

/*********************************************/
/*         class LinkedList interface        */
/*********************************************/
template <class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void printer() const;
    void sort();
    LinkedList<T>& insertToEnd(T item);                 // For linear search
    bool findIndexLinear(T item, int& index) const;     // For linear search
    LinkedList<T>& insertOrdered(T item);               // For binary search
    bool findIndexBinary(T item, int& index) const;     // For binary search

private:
    class Node {
    public:
        T       _value;
        Node    *_pNext;
        Node() : _pNext(nullptr) {}
        Node(T _value0) : _value(_value0), _pNext(nullptr){}
        Node(T _value0, Node *_pNext0) : _value(_value0), _pNext(_pNext0) {}
    };

    int llCounter;
    Node *first;
    Node *last;

    typename LinkedList<T>::Node* quickSort(Node* start, Node *end);
    typename LinkedList<T>::Node* partition(Node* start, Node* end);
};

/*********************************************/
/*      class LinkedList implementation      */
/*********************************************/
template <class T>
LinkedList<T>::LinkedList() {
    llCounter = 0;
    first = nullptr;
    last = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node *aux;

    while (first != nullptr) {
        aux = first->_pNext;
        delete first;
        first = aux;
    }
    llCounter = 0;
    //cout << "Deleted linked list" << endl;
}

template <class T>
void LinkedList<T>::printer() const {
    Node *aux = first;
    while (aux != nullptr) {
        cout << aux->_value << " ";
        aux = aux->_pNext;
    }
    cout << endl << endl;
}

template <class T>
void LinkedList<T>::sort() {
    if (llCounter > 1)  {
        quickSort(first, last);
    }
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::quickSort(Node* start, Node* end) {
    if (start == nullptr || start == end || start == end->_pNext)
        return start;

    Node* pivot = partition(start, end);

    if (pivot != start) {
        Node* temp = start;
        while (temp->_pNext != pivot) {
            temp = temp->_pNext;
        }
        temp->_pNext = nullptr;
        start = quickSort(start, temp);
        temp = start;
        while (temp->_pNext != nullptr) {
            temp = temp->_pNext;
        }
        temp->_pNext = pivot;
    }

    pivot->_pNext = quickSort(pivot->_pNext, end);
    return start;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::partition(Node* start, Node* end) {
    T pivot = end->_value;
    Node* i = start;
    Node* j = start;
    while (j != end) {
        if (j->_value <= pivot) {
            swap(i->_value, j->_value);
            i = i->_pNext;
        }
        j = j->_pNext;
    }
    swap(i->_value, end->_value);
    return i;
}

template <class T>
LinkedList<T>& LinkedList<T>::insertToEnd(T item) {
    Node *newNode = new Node(item);
    if (first == nullptr) {
        first = newNode;
    } else {
        last->_pNext = newNode;
    }
    last = newNode;
    llCounter++;
    return *this;
}

template <class T>
bool LinkedList<T>::findIndexLinear(T item, int& index) const {
    Node *aux = first;
    int i = 0;
    while (llCounter > 0 && aux != nullptr) {
        if (aux->_value == item) {
            index = i;
            return true;
        }
        aux = aux->_pNext;
        i++;
    }
    return false;
}

template <class T>
LinkedList<T>& LinkedList<T>::insertOrdered(T item) {
    Node *newNode = new Node(item);

    if (first == nullptr || item < first->_value) {
        newNode->_pNext = first;
        first = newNode;
        if (last == nullptr) {
            last = newNode;
        }
        llCounter++;
        return *this;
    }

    Node *current = first;
    while (current->_pNext != nullptr && current->_pNext->_value < item) {
        current = current->_pNext;
    }

    newNode->_pNext = current->_pNext;
    current->_pNext = newNode;
    if (newNode->_pNext == nullptr) {
        last = newNode;
    }
    llCounter++;
    return *this;
}

template <class T>
bool LinkedList<T>::findIndexBinary(T item, int& index) const {
    /* Ensure singly linked list is sorted */
    // sort();

    int low = 0;
    int high = llCounter - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        Node *current = first;
        for (int i = 0; i < mid; i++) {
            current = current->_pNext;
        }
        if (current->_value == item) {
            index = mid;
            return true;
        } else if (current->_value < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}