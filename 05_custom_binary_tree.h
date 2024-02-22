using namespace std;

/*********************************************/
/*     class CustomBinaryTree interface      */
/*********************************************/
template <class T>
class CustomBinaryTree {
public:
    CustomBinaryTree();
    ~CustomBinaryTree() = default;
    void insert(T item);
    bool find(T item);

private:

    class Node {
    public:
        T       _value;
        Node*   _pLeft;
        Node*   _pRight;
        explicit Node(T _value0) {
            _value = _value0;
            _pLeft = nullptr;
            _pRight = nullptr;
        }
    };

    Node *root;

    Node* insertNode(Node* root0, T data0) {
        if (root0 == nullptr) {
            return new Node(data0);
        }

        if (data0 < root0->_value) {
            root0->_pLeft = insertNode(root0->_pLeft, data0);
        } else if (data0 > root0->_value) {
            root0->_pRight = insertNode(root0->_pRight, data0);
        }

        return root0;
    }

    void searchNode(Node* root1, T data1, bool& found) {
        if (root1 == nullptr) {
            found = false;
            return;
        }

        if (root1->_value == data1) {
            found = true;
            return;
        }

        if (data1 < root1->_value) {
            searchNode(root1->_pLeft, data1, found);
        } else {
            searchNode(root1->_pRight, data1, found);
        }
    }
};

/*********************************************/
/*   class CustomBinaryTree implementation   */
/*********************************************/
template <class T>
CustomBinaryTree<T>::CustomBinaryTree() {
    root = nullptr;
}

template <class T>
void CustomBinaryTree<T>::insert(T item) {
    root = insertNode(root, item);
}

template <class T>
bool CustomBinaryTree<T>::find(T item) {
    bool found;
    searchNode(root, item, found);
    return found;
}