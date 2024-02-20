#include <iostream>
#include <vector>
#include <chrono>
#include <iostream>

#include "json.hpp"
#include "01_array.h"
#include "02_linked_list.h"
#include "03_double_linked_list.h"
#include "04_ring_linked_list.h"
#include "05_binary_tree.h"
#include "06_hash_table.h"

#define testDataSize 100

using namespace std;

int main() {

    /*********************/
    /*     TEST DATA:    */
    /*********************/
    vector<int> testData(testDataSize);
    for (int i = testDataSize - 1; i >= 0; i--) { // creates descending array1
        testData[testDataSize - i - 1] = i;
    }

    /***********************************/
    /* VARIABLES USED BY ALL CLASSES:  */
    /***********************************/
    int     index;
    int     searchedValue = 84; //Search for value

    /*********************/
    /*       ARRAY       */
    /*********************/
#if 0
    cout << "Array:" << endl;

    /* Linear search: */
    List<int> array1;
    for (const auto &each : testData) {
        array1.insertToEnd(each);
    }

    //array1.printer(); // works
    auto start01 = chrono::high_resolution_clock ::now();

    bool retval01 = array1.findIndexLinear(searchedValue, index);
    if (retval01) {
        cout << searchedValue << " found at index: " << index << endl;
    }

    auto end01 = chrono::high_resolution_clock::now();
    auto duration01 = chrono::duration_cast<chrono::microseconds>(end01 - start01);
    cout << "Array linear search time: " << duration01.count() << " ms" << endl;

    /* Sort: */
    //array1.sort();
    //cout << "Sort:" << endl;
    //array1.printer();

    /* Binary search: */
    List<int> array2;
    for (const auto &each : testData) {
        array2.insertOrdered(each);
    }

    start01 = chrono::high_resolution_clock ::now();

    retval01 = array2.findIndexBinary(searchedValue, index);
    if (retval01) {
        cout << searchedValue << " found at index: " << index << endl;
    }

    end01 = chrono::high_resolution_clock::now();
    duration01 = chrono::duration_cast<chrono::microseconds>(end01 - start01);
    cout << "Array binary search time: " << duration01.count() << " ms" << endl << endl;
#endif

    /*********************/
    /*    LINKED LIST    */
    /*********************/
#if 0
    cout << "Singly linked list:" << endl;

    /* Linear search: */
    LinkedList<int> linkedList1;

    for (const auto &each : testData) {
        linkedList1.insertToEnd(each);
    }

    //linkedList1.printer(); // works

    auto start02 = chrono::high_resolution_clock ::now();

    bool retval02 = linkedList1.findIndexLinear(searchedValue, index);
    if (retval02) {
        cout << searchedValue << " found at index: " << index << endl;
    }

    auto end02 = chrono::high_resolution_clock::now();
    auto duration02 = chrono::duration_cast<chrono::microseconds>(end02 - start02);
    cout << "Singly linked list linear search time: " << duration02.count() << " ms" << endl;

    /* Sort: */
    //linkedList1.sort();
    //cout << "Sort:" << endl;
    //linkedList1.printer();

    /* Binary search: */
    LinkedList<int> linkedList2;

    for (const auto &each : testData) {
        linkedList2.insertOrdered(each);
    }
    //linkedList2.printer(); // works
    start02 = chrono::high_resolution_clock ::now();

    retval02 = linkedList2.findIndexBinary(searchedValue, index);
    if (retval02) {
        cout << searchedValue << " found at index: " << index << endl;
    }

    end02 = chrono::high_resolution_clock::now();
    duration02 = chrono::duration_cast<chrono::microseconds>(end02 - start02);
    cout << "Singly linked list binary search time: " << duration02.count() << " ms" << endl;
#endif

    /**********************/
    /* DOUBLE LINKED LIST */
    /**********************/
#if 1
    cout << "Doubly linked list:" << endl;

    /* Linear search: */
    DoubleLinkedList<int> doubleLinkedList1;

    for (const auto &each : testData) {
        doubleLinkedList1.insertToEnd(each);
    }

    //doubleLinkedList1.printer(); // works
    //doubleLinkedList1.printReverse(); // works

    auto start03 = chrono::high_resolution_clock ::now();

    bool retval03 = doubleLinkedList1.findIndexLinear(searchedValue, index);
    if (retval03) {
        cout << searchedValue << " found at index: " << index << endl;
    }

    auto end03 = chrono::high_resolution_clock::now();
    auto duration03 = chrono::duration_cast<chrono::microseconds>(end03 - start03);
    cout << "Doubly linked list linear search time: " << duration03.count() << " ms" << endl;

    /* Sort: */
    //doubleLinkedList1.sort();
    //cout << "Sort:" << endl;
    //doubleLinkedList1.printer();

    /* Binary search: */
    DoubleLinkedList<int> doubleLinkedList2;

    for (const auto &each : testData) {
        doubleLinkedList2.insertOrdered(each);
    }
    //linkedList2.printer(); // works
    start03 = chrono::high_resolution_clock ::now();

    retval03 = doubleLinkedList2.findIndexBinary(searchedValue, index);
    if (retval03) {
        cout << searchedValue << " found at index: " << index << endl;
    }

    end03 = chrono::high_resolution_clock::now();
    duration03 = chrono::duration_cast<chrono::microseconds>(end03 - start03);
    cout << "Doubly linked list binary search time: " << duration03.count() << " ms" << endl;
#endif

    /********************/
    /* RING LINKED LIST */
    /********************/
#if 0

#endif

    /**********************/
    /* BINARY SEARCH TREE */
    /**********************/
#if 0

#endif

    /**************/
    /* HASH TABLE */
    /**************/
#if 0

#endif

    return 0;
}
