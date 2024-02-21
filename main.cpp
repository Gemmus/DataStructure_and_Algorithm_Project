#include <iostream>
#include <vector>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <numeric>
#include <cmath>

#include "json.hpp"
#include "01_array.h"
#include "03_linked_list.h"
#include "04_double_linked_list.h"
#include "02_circular_array.h"
#include "05_binary_tree.h"
#include "06_hash_table.h"
#include "random_generator.h"

#define testDataSize 100
#define RANDOM_MIN 0
#define RANDOM_MAX 10000
#define measureN 30

using namespace std;
                            /***************************/
                            /*       APPLICATION       */
                            /***************************/

/***************************/
/*  FUNCTION DECLARATIONS  */
/***************************/
template <typename T>
void arrayLinear(const vector<T>& testData, const T& searchedValue);
template <typename T>
void arrayBinary(const vector<T>& testData, const T& searchedValue);
template <typename T>
void circArrayLinear(const vector<T>& testData, const T& searchedValue);
template <typename T>
void circArrayBinary(const vector<T>& testData, const T& searchedValue);
template <typename T>
void linkedListLinear(const vector<T>& testData, const T& searchedValue);
template <typename T>
void linkedListBinary(const vector<T>& testData, const T& searchedValue);
template <typename T>
void doubleLinkedListLinear(const vector<T>& testData, const T& searchedValue);
template <typename T>
void doubleLinkedListBinary(const vector<T>& testData, const T& searchedValue);

/***************************/
/*          MAIN           */
/***************************/
int main() {
    /*********************/
    /*  SEEDING RANDOM:  */
    /*********************/
    srand(time(nullptr));

    /**********************/
    /*  GENERATE RANDOM:  */
    /**********************/
#if 0
    vector<int> IntRandData(testDataSize);
    generate(IntRandData.begin(), IntRandData.end(), RandomGenerator<float>(RANDOM_MIN, RANDOM_MAX));
    copy(IntRandData.begin(), IntRandData.end(), ostream_iterator<float> (cout, " "));

    int index, searchedValue;
    cout << "\nEnter index: ";
    cin >> index;
    searchedValue = IntRandData[index];
    cout << searchedValue << endl;
#endif

#if 0
    vector<float> FloatRandData(testDataSize);
    generate(FloatRandData.begin(), FloatRandData.end(), RandomGenerator<float>(RANDOM_MIN, RANDOM_MAX));
    copy(FloatRandData.begin(), FloatRandData.end(), ostream_iterator<float> (cout, " "));
    cout << endl;

    int floatIndex;
    float floatSearchValue;
    cout << "\nEnter float index: ";
    cin >> floatIndex;
    floatSearchValue = FloatRandData[floatIndex];
#endif

#if 0
    vector<double> DoubleRandData(testDataSize);
    generate(DoubleRandData.begin(), DoubleRandData.end(), RandomGenerator<float>(RANDOM_MIN, RANDOM_MAX));
    copy(DoubleRandData.begin(), DoubleRandData.end(), ostream_iterator<float> (cout, " "));
    cout << endl;

    int doubleIndex;
    double doubleSearchValue;
    cout << "\nEnter double index: ";
    cin >> doubleIndex;
    doubleSearchValue = DoubleRandData[doubleIndex];
#endif

    /*****************************/
    /*   GENERATING TEST DATA:   */
    /*****************************/
#if 1
    vector<int> IntRandData(testDataSize);
    for (int i = testDataSize - 1; i >= 0; i--) { // creates descending array1
        IntRandData[testDataSize - i - 1] = i;
    }

    vector<float> FloatRandData(testDataSize);
    for (int i = testDataSize - 1; i >= 0; i--) { // creates descending array1
        FloatRandData[testDataSize - i - 1] = static_cast<float>(i);
    }

    vector<double> DoubleRandData(testDataSize);
    for (int i = testDataSize - 1; i >= 0; i--) { // creates descending array1
        DoubleRandData[testDataSize - i - 1] = i;
    }

    int searchedValue = IntRandData[15]; //Search for value
    float floatSearchValue = FloatRandData[15];
    double doubleSearchValue = DoubleRandData[15];
#endif

#if 0   // INTEGERS
    /*********************/
    /*       ARRAY       */
    /*********************/

    arrayLinear(IntRandData, searchedValue);
    arrayBinary(IntRandData, searchedValue);

    /********************/
    /*  CIRCULAR ARRAY  */
    /********************/

    circArrayLinear(IntRandData, searchedValue);
    circArrayBinary(IntRandData, searchedValue);

    /*********************/
    /*    LINKED LIST    */
    /*********************/

    linkedListLinear(IntRandData, searchedValue);
    linkedListBinary(IntRandData, searchedValue);

    /**********************/
    /* DOUBLE LINKED LIST */
    /**********************/

    doubleLinkedListLinear(IntRandData, searchedValue);
    doubleLinkedListBinary(IntRandData, searchedValue);

    /**********************/
    /* BINARY SEARCH TREE */
    /**********************/


    /**************/
    /* HASH TABLE */
    /**************/

#endif

#if 1  // FLOAT
    /*********************/
    /*       ARRAY       */
    /*********************/

    arrayLinear(FloatRandData, floatSearchValue);
    arrayBinary(FloatRandData, floatSearchValue);

    /********************/
    /*  CIRCULAR ARRAY  */
    /********************/

    circArrayLinear(FloatRandData, floatSearchValue);
    circArrayBinary(FloatRandData, floatSearchValue);

    /*********************/
    /*    LINKED LIST    */
    /*********************/

    linkedListLinear(FloatRandData, floatSearchValue);
    linkedListBinary(FloatRandData, floatSearchValue);

    /**********************/
    /* DOUBLE LINKED LIST */
    /**********************/

    doubleLinkedListLinear(FloatRandData, floatSearchValue);
    doubleLinkedListBinary(FloatRandData, floatSearchValue);


    /**********************/
    /* BINARY SEARCH TREE */
    /**********************/


    /**************/
    /* HASH TABLE */
    /**************/
#endif

#if 0  // DOUBLE
    /*********************/
    /*       ARRAY       */
    /*********************/

    arrayLinear(DoubleRandData, doubleSearchValue);
    arrayBinary(DoubleRandData, doubleSearchValue);

    /********************/
    /*  CIRCULAR ARRAY  */
    /********************/

    circArrayLinear(DoubleRandData, doubleSearchValue);
    circArrayBinary(DoubleRandData, doubleSearchValue);

    /*********************/
    /*    LINKED LIST    */
    /*********************/

    linkedListLinear(DoubleRandData, doubleSearchValue);
    linkedListBinary(DoubleRandData, doubleSearchValue);

    /**********************/
    /* DOUBLE LINKED LIST */
    /**********************/

    doubleLinkedListLinear(DoubleRandData, doubleSearchValue);
    doubleLinkedListBinary(DoubleRandData, doubleSearchValue);


    /**********************/
    /* BINARY SEARCH TREE */
    /**********************/


    /**************/
    /* HASH TABLE */
    /**************/
#endif


    return 0;
}

template <typename T>
void arrayLinear(const vector<T>& Data, const T& searchValue) {
    cout << "ARRAY LINEAR SEARCH:" << endl;

    /******************/
    /* Linear search: */
    /******************/
    vector<double>  execTimes;
    List<T>         array;
    double          insertTime;
    double          mean;
    int             index;

    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each : Data) {
        array.insertToEnd(each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    insertTime = static_cast<double>(duration.count());
    cout << "Insertion time: " << insertTime << " ns" << endl;

    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = array.findIndexLinear(searchValue, index);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        if (retval) {
            execTimes.push_back(static_cast<double>(duration.count()));
        }
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Display values */
    /*
    cout << "Execution times after sorting and disregarding the largest values: ";
    for (int i = 0; i < execTimes.size(); i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << execTimes[i] << "\t";
    }
    cout << endl; */

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    cout << "Average exec time: " << mean << " ns" << endl;
    cout << "Overall time: " << insertTime + mean << " ns" << endl;
    cout << "---------------------------------------------------------------" << endl;

    /*********/
    /* Sort: */
    /*********/
    //array.sort();
    //cout << "Sort:" << endl;
    //array.printer();
}

template<typename T>
void arrayBinary(const vector<T>& testData, const T& searchedValue) {
    cout << "ARRAY BINARY SEARCH:" << endl;

    /******************/
    /* Binary search: */
    /******************/
    vector<double>  execTimes;
    List<T>         array;
    double          insertTime;
    double          mean;
    int             index;

    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each : testData) {
        array.insertOrdered(each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    insertTime = static_cast<double>(duration.count());
    cout << "Insertion time: " << insertTime << " ns" << endl;

    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = array.findIndexBinary(searchedValue, index);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        if (retval) {
            execTimes.push_back(static_cast<double>(duration.count()));
        }
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Display values */
    /*
    cout << "Execution times after sorting and disregarding the largest values: ";
    for (int i = 0; i < execTimes.size(); i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << execTimes[i] << "\t";
    }
    cout << endl; */

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    cout << "Average exec time: " << mean << " ns" << endl;
    cout << "Overall time: " << insertTime + mean << " ns" << endl;
    cout << "---------------------------------------------------------------" << endl;
}

template <typename T>
void circArrayLinear(const vector<T>& Data, const T& searchValue) {
    cout << "CIRCULAR ARRAY LINEAR SEARCH:" << endl;

    /******************/
    /* Linear search: */
    /******************/

    vector<double>  execTimes;
    CircList<T>     circArray;
    double          insertTime;
    double          mean;
    int             index;

    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each : Data) {
        circArray.insertToEnd(each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    insertTime = static_cast<double>(duration.count());
    cout << "Insertion time: " << insertTime << " ns" << endl;

    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = circArray.findIndexLinear(static_cast<float>(searchValue), index);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        if (retval) {
            execTimes.push_back(static_cast<double>(duration.count()));
        }
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Display values */
    /*
    cout << "Execution times after sorting and disregarding the largest values: ";
    for (int i = 0; i < execTimes.size(); i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << execTimes[i] << "\t";
    }
    cout << endl; */

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    cout << "Average exec time: " << mean << " ns" << endl;
    cout << "Overall time: " << insertTime + mean << " ns" << endl;
    cout << "---------------------------------------------------------------" << endl;

    /*********/
    /* Sort: */
    /*********/
    //circArray.sort();
    //cout << "Sort:" << endl;
    //circArray.printer();
}

template <typename T>
void circArrayBinary(const vector<T>& Data, const T& searchValue) {
    cout << "CIRCULAR ARRAY BINARY SEARCH:" << endl;

    /******************/
    /* Linear search: */
    /******************/
    vector<double>  execTimes;
    CircList<T>     circArray;
    double          insertTime;
    double          mean;
    int             index;

    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each : Data) {
        circArray.insertOrdered(each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    insertTime = static_cast<double>(duration.count());
    cout << "Insertion time: " << insertTime << " ns" << endl;

    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = circArray.findIndexBinary(static_cast<float>(searchValue), index);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        if (retval) {
            execTimes.push_back(static_cast<double>(duration.count()));
        }
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Display values */
    /*
    cout << "Execution times after sorting and disregarding the largest values: ";
    for (int i = 0; i < execTimes.size(); i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << execTimes[i] << "\t";
    }
    cout << endl; */

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    cout << "Average exec time: " << mean << " ns" << endl;
    cout << "Overall time: " << insertTime + mean << " ns" << endl;
    cout << "---------------------------------------------------------------" << endl;
}

template <typename T>
void linkedListLinear(const vector<T>& Data, const T& searchValue) {
    cout << "SINGLY LINKED LIST LINEAR SEARCH:" << endl;

    /******************/
    /* Linear search: */
    /******************/
    vector<double>  execTimes;
    LinkedList<T>   linkedList;
    double          insertTime;
    double          mean;
    int             index;

    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each : Data) {
        linkedList.insertToEnd(each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    insertTime = static_cast<double>(duration.count());
    cout << "Insertion time: " << insertTime << " ns" << endl;

    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = linkedList.findIndexLinear(searchValue, index);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        if (retval) {
            execTimes.push_back(static_cast<double>(duration.count()));
        }
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Display values */
    /*
    cout << "Execution times after sorting and disregarding the largest values: ";
    for (int i = 0; i < execTimes.size(); i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << execTimes[i] << "\t";
    }
    cout << endl; */

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    cout << "Average exec time: " << mean << " ns" << endl;
    cout << "Overall time: " << insertTime + mean << " ns" << endl;
    cout << "---------------------------------------------------------------" << endl;

    /*********/
    /* Sort: */
    /*********/
    //linkedList.sort();
    //cout << "Sort:" << endl;
    //linkedList.printer();
}

template <typename T>
void linkedListBinary(const vector<T>& Data, const T& searchValue) {
    cout << "SINGLY LINKED LIST BINARY SEARCH:" << endl;

    /******************/
    /* Binary search: */
    /******************/
    vector<double>  execTimes;
    LinkedList<T>   linkedList;
    double          insertTime;
    double          mean;
    int             index;

    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each : Data) {
        linkedList.insertOrdered(each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    insertTime = static_cast<double>(duration.count());
    cout << "Insertion time: " << insertTime << " ns" << endl;

    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = linkedList.findIndexBinary(searchValue, index);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        if (retval) {
            execTimes.push_back(static_cast<double>(duration.count()));
        }
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Display values */
    /*
    cout << "Execution times after sorting and disregarding the largest values: ";
    for (int i = 0; i < execTimes.size(); i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << execTimes[i] << "\t";
    }
    cout << endl; */

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    cout << "Average exec time: " << mean << " ns" << endl;
    cout << "Overall time: " << insertTime + mean << " ns" << endl;
    cout << "---------------------------------------------------------------" << endl;
}

template <typename T>
void doubleLinkedListLinear(const vector<T>& Data, const T& searchValue) {
    cout << "DOUBLY LINKED LIST LINEAR SEARCH:" << endl;

    /******************/
    /* Linear search: */
    /******************/
    vector<double> execTimes;
    DoubleLinkedList<T> doubleLinkedList;
    double insertTime;
    double mean;
    int index;

    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each: Data) {
        doubleLinkedList.insertToEnd(each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    insertTime = static_cast<double>(duration.count());
    cout << "Insertion time: " << insertTime << " ns" << endl;

    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = doubleLinkedList.findIndexLinear(searchValue, index);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        if (retval) {
            execTimes.push_back(static_cast<double>(duration.count()));
        }
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Display values */
    /*
    cout << "Execution times after sorting and disregarding the largest values: ";
    for (int i = 0; i < execTimes.size(); i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << execTimes[i] << "\t";
    }
    cout << endl; */

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double) execTimes.size();
    cout << "Average exec time: " << mean << " ns" << endl;
    cout << "Overall time: " << insertTime + mean << " ns" << endl;
    cout << "---------------------------------------------------------------" << endl;

    /*********/
    /* Sort: */
    /*********/
    //doubleLinkedList.sort();
    //cout << "Sort:" << endl;
    //doubleLinkedList.printer();
}

template <typename T>
void doubleLinkedListBinary(const vector<T>& Data, const T& searchValue) {
    cout << "DOUBLY LINKED LIST BINARY SEARCH:" << endl;

    /******************/
    /* Binary search: */
    /******************/
    vector<double>  execTimes;
    DoubleLinkedList<T>   doubleLinkedList;
    double          insertTime;
    double          mean;
    int             index;

    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each : Data) {
        doubleLinkedList.insertOrdered(each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    insertTime = static_cast<double>(duration.count());
    cout << "Insertion time: " << insertTime << " ns" << endl;

    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = doubleLinkedList.findIndexBinary(searchValue, index);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        if (retval) {
            execTimes.push_back(static_cast<double>(duration.count()));
        }
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Display values */
    /*
    cout << "Execution times after sorting and disregarding the largest values: ";
    for (int i = 0; i < execTimes.size(); i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << execTimes[i] << "\t";
    }
    cout << endl; */

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    cout << "Average exec time: " << mean << " ns" << endl;
    cout << "Overall time: " << insertTime + mean << " ns" << endl;
    cout << "---------------------------------------------------------------" << endl;
}