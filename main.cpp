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
    for (int i = 0; i < testDataSize; i++) {
        testData[i] = i;
    }

    // VARIABLES USED BY ALL CLASSES:
    int index;
    int searchedValue = 1; //Search for value

    /* ARRAY */
    List<int> array;

    for (const auto &each : testData) {
        array.insertToEnd(each);
    }

    cout << "Array:" << endl;
    //array.printer();

    auto start01 = chrono::high_resolution_clock ::now();

    bool retval01 = array.findIndex(searchedValue, index);
    cout << searchedValue << " found at index: " << retval01 << endl;

    auto end01 = chrono::high_resolution_clock::now();
    auto duration01 = chrono::duration_cast<chrono::microseconds>(end01 - start01);
    cout << "Array search time: " << duration01.count() << " ms" << endl << endl;

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
