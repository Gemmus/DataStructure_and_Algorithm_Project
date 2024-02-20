using namespace std;

template <class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList<T>& insertToEnd(T data);
    bool findIndex(T item, int& index);
    void printer();
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
};

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
    cout << "Deleted linked list" << endl;
}

template <class T>
LinkedList<T>& LinkedList<T>::insertToEnd(T data) {
    Node *newNode = new Node(data);
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
bool LinkedList<T>::findIndex(T item, int& index) {
    Node *aux = first;
    int i = 0;
    while (llCounter > 0 && aux != nullptr) {
        i++;
        if (aux->_value == item) {
            index = i;
            return true;
        }
        aux = aux->_pNext;
    }
    return false;
}

template <class T>
void LinkedList<T>::printer() {
    Node *aux = first;
    while (aux != nullptr) {
        cout << aux->_value << " ";
        aux = aux->_pNext;
    }
    cout << endl << endl;
}