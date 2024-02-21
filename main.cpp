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

    /*********************/
    /*  TESTING RANDOM:  */
    /*********************/
#if 1
    vector<int> testData(testDataSize);
    generate(testData.begin(), testData.end(), RandomGenerator<float>(RANDOM_MIN, RANDOM_MAX));
    copy(testData.begin(), testData.end(), ostream_iterator<float> (cout, " "));
    cout << endl;

    int index, searchedValue;
    cout << "index: ";
    cin >> index;
    searchedValue = testData[index];
    cout << searchedValue << endl;
#endif

#if 0
    vector<double> testData2(testDataSize);
    generate(testData2.begin(), testData2.end(), RandomGenerator<float>(RANDOM_MIN, RANDOM_MAX));
    copy(testData2.begin(), testData2.end(), ostream_iterator<float> (cout, " "));
    cout << endl;

    double sV;
    cout << "sV: ";
    cin >> sV;
#endif

    /*****************************/
    /*   GENERATING TEST DATA:   */
    /*****************************/
#if 0
    vector<int> testData(testDataSize);
    for (int i = testDataSize - 1; i >= 0; i--) { // creates descending array1
        testData[testDataSize - i - 1] = i;
    }

    vector<double> testData2(testDataSize);
    for (int i = testDataSize - 1; i >= 0; i--) { // creates descending array1
        testData2[testDataSize - i - 1] = i;
    }

    const int searchedValue = 4848; //Search for value
    const double sV = 4848.00;
#endif


    /*********************/
    /*       ARRAY       */
    /*********************/
#if 1
    arrayLinear(testData, searchedValue);
    //arrayLinear(testData2, sV);
    arrayBinary(testData, searchedValue);
    //arrayBinary(testData2, sV);
#endif

    /********************/
    /*  CIRCULAR ARRAY  */
    /********************/
#if 1
    circArrayLinear(testData, searchedValue);
    //circArrayLinear(testData2, sV);
    circArrayBinary(testData, searchedValue);
    //circArrayBinary(testData2, sV);
#endif

    /*********************/
    /*    LINKED LIST    */
    /*********************/
#if 1
    linkedListLinear(testData, searchedValue);
    //linkedListLinear(testData2, sV);
    linkedListBinary(testData, searchedValue);
    //linkedListBinary(testData2, sV);
#endif

    /**********************/
    /* DOUBLE LINKED LIST */
    /**********************/
#if 1
    doubleLinkedListLinear(testData, searchedValue);
    //doubleLinkedListLinear(testData2, sV);
    doubleLinkedListBinary(testData, searchedValue);
    //doubleLinkedListBinary(testData2, sV);
#endif

    /**********************/
    /* BINARY SEARCH TREE */
    /**********************/
#if 1

#endif

    /**************/
    /* HASH TABLE */
    /**************/
#if 1

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
void arrayBinary(const vector<T>& Data, const T& searchValue) {
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
    for (const auto &each : Data) {
        array.insertOrdered(each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    insertTime = static_cast<double>(duration.count());
    cout << "Insertion time: " << insertTime << " ns" << endl;

    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = array.findIndexBinary(searchValue, index);
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