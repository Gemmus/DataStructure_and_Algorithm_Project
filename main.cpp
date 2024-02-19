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

    vector<int> testData(testDataSize);
    for (int i = 0; i < testDataSize; i++) {
        testData[i] = i;
    }

    List<int> array;
    int index;

    for (const auto &each : testData) {
        array.insertToEnd(each);
    }

    array.printer();

    auto start01 = chrono::steady_clock::now();

    bool retval = array.findIndex(89, index);
    cout << retval << endl;

    auto end01 = chrono::steady_clock::now();
    auto duration01 = chrono::duration_cast<chrono::microseconds>(end01 - start01);
    cout << duration01.count() << " ms" << endl;

    return 0;
}
