#include <set>

using namespace std;

/*********************************************/
/*     class STLBinaryTree interface      */
/*********************************************/
template <class T>
class STLBinaryTree {
public:
    STLBinaryTree() = default;
    ~STLBinaryTree() = default;
    void insert(T item);
    bool find(T item);

private:
    set<T> tree;
};

/*********************************************/
/*   class CustomBinaryTree implementation   */
/*********************************************/
template <class T>
void STLBinaryTree<T>::insert(T item) {
    tree.insert(item);
}

template <class T>
bool STLBinaryTree<T>::find(T item) {
    return tree.find(item) != tree.end();
}
