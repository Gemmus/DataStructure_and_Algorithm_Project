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

    // TEST DATA:
    vector<int> testData(testDataSize);
    for (int i = testDataSize - 1; i >= 0; i--) { // creates descending array1
        testData[testDataSize - i - 1] = i;
    }

    // VARIABLES USED BY ALL CLASSES:
    int index;
    int searchedValue = 84; //Search for value

    /* ARRAY */
    cout << "Array:" << endl;

    // Linear search:
    List<int> array1;
    for (const auto &each : testData) {
        array1.insertToEnd(each);
    }

    //array1.printer();
    auto start01 = chrono::high_resolution_clock ::now();

    bool retval01 = array1.findIndexLinear(searchedValue, index);
    if (retval01 == 1) {
        cout << searchedValue << " found at index: " << index << endl;
    }

    auto end01 = chrono::high_resolution_clock::now();
    auto duration01 = chrono::duration_cast<chrono::microseconds>(end01 - start01);
    cout << "Array linear search time: " << duration01.count() << " ms" << endl;

    // Binary search:
    List<int> array2;
    for (const auto &each : testData) {
        array2.insertOrdered(each);
    }

    start01 = chrono::high_resolution_clock ::now();

    retval01 = array2.findIndexBinary(searchedValue, index);
    if (retval01 == 1) {
        cout << searchedValue << " found at index: " << index << endl;
    }

    end01 = chrono::high_resolution_clock::now();
    duration01 = chrono::duration_cast<chrono::microseconds>(end01 - start01);
    cout << "Array binary search time: " << duration01.count() << " ms" << endl << endl;

    /* LINKED LIST */
    LinkedList<int> linkedList;

    for (const auto &each : testData) {
        linkedList.insertToEnd(each);
    }

    cout << "Linked list:" << endl;
    //linkedList.printer();

    auto start02 = chrono::high_resolution_clock ::now();

    bool retval02 = linkedList.findIndex(searchedValue, index);
    cout << searchedValue << " found at index: " << retval02 << endl;

    auto end02 = chrono::high_resolution_clock::now();
    auto duration02 = chrono::duration_cast<chrono::microseconds>(end02 - start02);
    cout << "Linked list search time: " << duration02.count() << " ms" << endl;

    /* DOUBLE LINKED LIST */


    /* RING LINKED LIST */
    /* BINARY SEARCH TREE */
    /* HASH TABLE */

    return 0;
}
