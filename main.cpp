#include <iostream>
#include <vector>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <numeric>
#include <cmath>
#include <iomanip>

#include "json.hpp"
#include "01_array.h"
#include "02_circular_array.h"
#include "03_linked_list.h"
#include "04_double_linked_list.h"
#include "05_custom_binary_tree.h"
#include "06_STL_binary_tree.h"
#include "07_hash_table.h"
#include "random_generator.h"

#define RANDOM_MIN      0
#define RANDOM_MAX      100000
#define measureN        30

using namespace std;
                            /***************************/
                            /*       APPLICATION       */
                            /***************************/

/***************************/
/*  FUNCTION DECLARATIONS  */
/***************************/
/* For searching elements */
template <typename T>
void arraySearch(const vector<T>&, const T&, const int&);
template <typename T>
void circArraySearch(const vector<T>&, const T&, const int&);
template <typename T>
void linkedListSearch(const vector<T>&, const T&, const int&);
template <typename T>
void doubleLinkedListSearch(const vector<T>&, const T&, const int&);
template <typename T>
void customBinarySearch(const vector<T>&, const T&);
template <typename T>
void STLBinarySearch(const vector<T>&, const T&);
/* Others */
template <typename T>
void displayVector(const vector<T>&);
void displayMeasuredTimes(const double&, const double&);


/***************************/
/*          MAIN           */
/***************************/
int main() {
    /*********************/
    /*  SEEDING RANDOM:  */
    /*********************/
    srand(time(nullptr));

    /***********************/
    /*  SET DYNAMIC VALUE  */
    /***********************/
    int testDataSize = 50000;   // MIN: 100 MAX: 50,000
    int datatype = 3;  // 1: integer, 2: float, 3: double
    int index = 24690;

    /*******************************/
    /*  GENERATE RANDOM TEST DATA  */
    /*******************************/
#if 0
    vector<int> IntRandData(testDataSize);
    generate(IntRandData.begin(), IntRandData.end(), RandomGenerator<float>(RANDOM_MIN, RANDOM_MAX));
    copy(IntRandData.begin(), IntRandData.end(), ostream_iterator<float> (cout, " "));

    int searchedValue = IntRandData[index];

    vector<float> FloatRandData(testDataSize);
    generate(FloatRandData.begin(), FloatRandData.end(), RandomGenerator<float>(RANDOM_MIN, RANDOM_MAX));
    copy(FloatRandData.begin(), FloatRandData.end(), ostream_iterator<float> (cout, " "));
    cout << endl;

    float floatSearchValue = FloatRandData[index];

    vector<double> DoubleRandData(testDataSize);
    generate(DoubleRandData.begin(), DoubleRandData.end(), RandomGenerator<float>(RANDOM_MIN, RANDOM_MAX));
    copy(DoubleRandData.begin(), DoubleRandData.end(), ostream_iterator<float> (cout, " "));
    cout << endl;

    double doubleSearchValue = DoubleRandData[index];
#endif

    /****************************/
    /*   GENERATING TEST DATA   */
    /****************************/
#if 1
    vector<int> IntRandData(testDataSize);
    for (int i = testDataSize - 1; i >= 0; i--) { // creates descending array
        IntRandData[testDataSize - i - 1] = i;
    }
    int searchedValue = IntRandData[15];

    vector<float> FloatRandData(testDataSize);
    for (int i = testDataSize - 1; i >= 0; i--) { // creates descending array
        FloatRandData[testDataSize - i - 1] = static_cast<float>(i);
    }
    float floatSearchValue = FloatRandData[15];

    vector<double> DoubleRandData(testDataSize);
    for (int i = testDataSize - 1; i >= 0; i--) { // creates descending array
        DoubleRandData[testDataSize - i - 1] = i;
    }
    double doubleSearchValue = DoubleRandData[15];
#endif

    /*****************************/
    /*      DATATYPE SWITCH      */
    /*****************************/
    switch(datatype) {
        case 1:
            cout << "---------------------------------------------------------------" << endl;
            cout << "---------------------      INTEGER      -----------------------" << endl;
            cout << "---------------------------------------------------------------" << endl;

            /*       ARRAY       */
            arraySearch(IntRandData, searchedValue, 1);
            arraySearch(IntRandData, searchedValue, 2);

            /*  CIRCULAR ARRAY  */
            circArraySearch(IntRandData, searchedValue, 1);
            circArraySearch(IntRandData, searchedValue, 2);

            /*    LINKED LIST    */
            linkedListSearch(IntRandData, searchedValue, 1);
            linkedListSearch(IntRandData, searchedValue, 2);

            /* DOUBLE LINKED LIST */
            doubleLinkedListSearch(IntRandData, searchedValue, 1);
            doubleLinkedListSearch(IntRandData, searchedValue, 2);

            /* CUSTOM BINARY SEARCH TREE */
            customBinarySearch(IntRandData, searchedValue);

            /* STL BINARY SEARCH TREE */
            STLBinarySearch(IntRandData, searchedValue);

            /* HASH TABLE */

            break;

        case 2:
            cout << "---------------------------------------------------------------" << endl;
            cout << "----------------------      FLOAT      ------------------------" << endl;
            cout << "---------------------------------------------------------------" << endl;

            /*       ARRAY       */
            arraySearch(FloatRandData, floatSearchValue, 1);
            arraySearch(FloatRandData, floatSearchValue, 2);

            /*  CIRCULAR ARRAY  */
            circArraySearch(FloatRandData, floatSearchValue, 1);
            circArraySearch(FloatRandData, floatSearchValue, 2);

            /*    LINKED LIST    */
            linkedListSearch(FloatRandData, floatSearchValue, 1);
            linkedListSearch(FloatRandData, floatSearchValue, 2);

            /* DOUBLE LINKED LIST */
            doubleLinkedListSearch(FloatRandData, floatSearchValue, 1);
            doubleLinkedListSearch(FloatRandData, floatSearchValue, 2);

            /* CUSTOM BINARY SEARCH TREE */
            customBinarySearch(FloatRandData, floatSearchValue);

            /* STL BINARY SEARCH TREE */
            STLBinarySearch(FloatRandData, floatSearchValue);

            /* HASH TABLE */

            break;

        case 3:
            cout << "---------------------------------------------------------------" << endl;
            cout << "---------------------      DOUBLE      ------------------------" << endl;
            cout << "---------------------------------------------------------------" << endl;

            /*       ARRAY       */
            arraySearch(DoubleRandData, doubleSearchValue, 1);
            arraySearch(DoubleRandData, doubleSearchValue, 2);

            /*  CIRCULAR ARRAY  */
            circArraySearch(DoubleRandData, doubleSearchValue, 1);
            circArraySearch(DoubleRandData, doubleSearchValue, 2);

            /*    LINKED LIST    */
            linkedListSearch(DoubleRandData, doubleSearchValue, 1);
            linkedListSearch(DoubleRandData, doubleSearchValue, 2);

            /* DOUBLE LINKED LIST */
            doubleLinkedListSearch(DoubleRandData, doubleSearchValue, 1);
            doubleLinkedListSearch(DoubleRandData, doubleSearchValue, 2);

            /* CUSTOM BINARY SEARCH TREE */
            customBinarySearch(DoubleRandData, doubleSearchValue);

            /* STL BINARY SEARCH TREE */
            STLBinarySearch(DoubleRandData, doubleSearchValue);

            /* HASH TABLE */

            break;

        default:
            break;
    }

    return 0;
}

/******************************/
/*  FUNCTION IMPLEMENTATIONS  */
/******************************/
template <typename T>
void arraySearch(const vector<T>& Data, const T& searchValue, const int& mode) {
    vector<double>  execTimes;
    List<T>         array;
    double          insertTime;
    double          mean;
    int             index;

    /* Display header, Initialize array and Measure execution times */
    if (mode == 1) {
        /* Display header */
        cout << "ARRAY LINEAR SEARCH:" << endl;
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each : Data) {
            array.insertToEnd(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        insertTime = static_cast<double>(duration.count());
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
    } else if (mode == 2) {
        /* Display header */
        cout << "ARRAY BINARY SEARCH:" << endl;
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each : Data) {
            array.insertOrdered(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        insertTime = static_cast<double>(duration.count());
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
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    displayMeasuredTimes(insertTime, mean);
}

template <typename T>
void circArraySearch(const vector<T>& Data, const T& searchValue, const int& mode) {
    vector<double>      execTimes;
    CircList<T>         circArray;
    double              insertTime;
    double              mean;
    int                 index;

    /* Display header, Initialize array and Measure execution times */
    if (mode == 1) {
        /* Display header */
        cout << "CIRCULAR ARRAY LINEAR SEARCH:" << endl;
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each : Data) {
            circArray.insertToEnd(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        insertTime = static_cast<double>(duration.count());
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
    } else if (mode == 2){
        /* Display header */
        cout << "CIRCULAR ARRAY BINARY SEARCH:" << endl;
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each : Data) {
            circArray.insertOrdered(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        insertTime = static_cast<double>(duration.count());
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
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    displayMeasuredTimes(insertTime, mean);
}

template <typename T>
void linkedListSearch(const vector<T>& Data, const T& searchValue, const int& mode) {
    vector<double>      execTimes;
    LinkedList<T>       linkedList;
    double              insertTime;
    double              mean;
    int                 index;

    /* Display header, Initialize array and Measure execution times */
    if (mode == 1) {
        /* Display header */
        cout << "SINGLY LINKED LIST LINEAR SEARCH:" << endl;
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each : Data) {
            linkedList.insertToEnd(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        insertTime = static_cast<double>(duration.count());
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
    } else if (mode == 2) {
        /* Display header */
        cout << "SINGLY LINKED LIST BINARY SEARCH:" << endl;
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each: Data) {
            linkedList.insertOrdered(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        insertTime = static_cast<double>(duration.count());
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
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    displayMeasuredTimes(insertTime, mean);
}

template <typename T>
void doubleLinkedListSearch(const vector<T>& Data, const T& searchValue, const int& mode) {
    vector<double>          execTimes;
    DoubleLinkedList<T>     doubleLinkedList;
    double                  insertTime;
    double                  mean;
    int                     index;

    /* Display header, Initialize array and Measure execution times */
    if (mode == 1) {
        /* Display header */
        cout << "DOUBLY LINKED LIST LINEAR SEARCH:" << endl;
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each: Data) {
            doubleLinkedList.insertToEnd(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        insertTime = static_cast<double>(duration.count());
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
    } else if (mode == 2) {
        /* Display header */
        cout << "DOUBLY LINKED LIST BINARY SEARCH:" << endl;
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each: Data) {
            doubleLinkedList.insertOrdered(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        insertTime = static_cast<double>(duration.count());
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
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double) execTimes.size();
    displayMeasuredTimes(insertTime, mean);
}

template <typename T>
void customBinarySearch(const vector<T>& Data, const T& searchValue){
    vector<double>          execTimes;
    CustomBinaryTree<T>     binaryTree;
    double                  insertTime;
    double                  mean;

    /* Display header */
    cout << "CUSTOM BINARY TREE SEARCH:" << endl;
    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each: Data) {
        binaryTree.insert(each);
    }
    auto end = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    insertTime = static_cast<double>(duration.count());
    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = binaryTree.find(searchValue);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        if (retval) {
            execTimes.push_back(static_cast<double>(duration.count()));
        }
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double) execTimes.size();
    displayMeasuredTimes(insertTime, mean);
}

template <typename T>
void STLBinarySearch(const vector<T>& Data, const T& searchValue) {
    vector<double>          execTimes;
    STLBinaryTree<T>        binaryTree;
    double                  insertTime;
    double                  mean;

    /* Display header */
    cout << "STL BINARY TREE SEARCH:" << endl;
    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each: Data) {
        binaryTree.insert(each);
    }
    auto end = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    insertTime = static_cast<double>(duration.count());
    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = binaryTree.find(searchValue);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        if (retval) {
            execTimes.push_back(static_cast<double>(duration.count()));
        }
    }

    /* Sort and discard largest 1/3 */
    sort(execTimes.begin(), execTimes.end());
    execTimes.erase(execTimes.end() - static_cast<int>(measureN / 3), execTimes.end());

    /* Calculate and display mean */
    mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double) execTimes.size();
    displayMeasuredTimes(insertTime, mean);
}

template <typename T>
void displayVector(const vector<T>& Vector) {
    for (int i = 0; i < Vector.size(); i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << fixed << setprecision(1) << Vector[i] << "\t";
    }
    cout << endl;
}

void displayMeasuredTimes(const double& insertTime, const double& mean) {
    cout << "Insertion time: " << fixed << setprecision(1) << insertTime << " ns" << endl;
    cout << "Average exec time: " << fixed << setprecision(1) << mean << " ns" << endl;
    cout << "Overall time: " << fixed << setprecision(1) << insertTime + mean << " ns" << endl;
    cout << "---------------------------------------------------------------" << endl;
}