#include <iostream>
#include <cstdio>
#include <vector>
#include <chrono>
#include <algorithm>
#include <ctime>
#include <numeric>
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
#define RANDOM_MAX      50000
#define measureN        30
#define ArgBufMax       1024

using namespace std;
using json = nlohmann::json;

/***************************/
/*       APPLICATION       */
/***************************/

/*********************************************/
/*  STRUCT TO STORE EACH MEASUREMENT VALUES  */
/*********************************************/
typedef struct time_data {
    double insertionTime;
    double mean;
} timeData;

/****************************/
/*    MEASUREMENT VALUES    */
/****************************/
static timeData         arrayLin;
static timeData         arrayBin;
static timeData          circLin;
static timeData          circBin;
static timeData        singlyLin;
static timeData        singlyBin;
static timeData        doublyLin;
static timeData        doublyBin;
static timeData        customBin;
static timeData           STLBin;
static timeData          hashLin;

/***************************/
/*  FUNCTION DECLARATIONS  */
/***************************/
/* For searching elements */
template <typename T>
void arraySearch(const vector<T>& Data, const T& searchValue, const int& mode, timeData& dataStruct);
template <typename T>
void circArraySearch(const vector<T>& Data, const T& searchValue, const int& mode, timeData& dataStruct);
template <typename T>
void linkedListSearch(const vector<T>& Data, const T& searchValue, const int& mode, timeData& dataStruct);
template <typename T>
void doubleLinkedListSearch(const vector<T>& Data, const T& searchValue, const int& mode, timeData& dataStruct);
template <typename T>
void customBinarySearch(const vector<T>& Data, const T& searchValue, timeData& dataStruct);
template <typename T>
void STLBinarySearch(const vector<T>& Data, const T& searchValue, timeData& dataStruct);
template <typename T>
void hashTableSearch(const vector<T>& Data, const T& searchValue, timeData& dataStruct, const int& arraySize);
/* Others */
void extractJSON(const string& jsonData, int& dataType, int& arraySize, int& searchIndex);
void displayMeasuredTimes(const timeData& dataStruct);
void headerPrinter(const int& dataType, const int& arraySize, const int& searchIndex);

/***************************/
/*          MAIN           */
/***************************/
int main(int argc, char **argv) {

    /********************/
    /*  SEEDING RANDOM  */
    /********************/
    srand(time(nullptr));

    /***********************/
    /*      VARIABLES      */
    /***********************/
    int dataType;      // 1: integer, 2: float, 3: double
    int arraySize;      // MIN: 100 MAX: 10,000
    int searchIndex;

    /**********************/
    /*    EXTRACT JSON    */
    /**********************/

    if (argc >= 2) {
        FILE *argfile = fopen(argv[1], "rb");
        if (argfile != nullptr) {
            char argbuf[ArgBufMax];
            size_t readcount = fread(argbuf, sizeof(argbuf[0]), sizeof(argbuf)-1, argfile);
            if (readcount > 0) {
                argbuf[readcount] = 0;
                extractJSON(argbuf, dataType, arraySize, searchIndex);
                //cout << "Datatype: " << dataType << " , array size: " << arraySize << " ,index to search for: " << searchIndex << endl;
            }
            fclose(argfile);
        }
    }

    /******************************/
    /*  ACTION BASED ON DATATYPE  */
    /******************************/
    if (dataType == 1) {
        /* PRINT HEADER */
        headerPrinter(dataType, arraySize, searchIndex);

        /*  GENERATE RANDOM TEST DATA  */
        vector<int> IntRandData(arraySize);
        generate(IntRandData.begin(), IntRandData.end(), RandomGenerator<float>(RANDOM_MIN, RANDOM_MAX));
        //copy(IntRandData.begin(), IntRandData.end(), ostream_iterator<float> (cout, " "));
        int searchedValue = IntRandData[searchIndex];

        /*       ARRAY       */
        arraySearch(IntRandData, searchedValue, 1, arrayLin);
        arraySearch(IntRandData, searchedValue, 2, arrayBin);

        /*  CIRCULAR ARRAY  */
        circArraySearch(IntRandData, searchedValue, 1, circLin);
        circArraySearch(IntRandData, searchedValue, 2, circBin);

        /*    LINKED LIST    */
        linkedListSearch(IntRandData, searchedValue, 1, singlyLin);
        linkedListSearch(IntRandData, searchedValue, 2, singlyBin);

        /* DOUBLE LINKED LIST */
        doubleLinkedListSearch(IntRandData, searchedValue, 1, doublyLin);
        doubleLinkedListSearch(IntRandData, searchedValue, 2, doublyBin);

        /* CUSTOM BINARY SEARCH TREE */
        customBinarySearch(IntRandData, searchedValue, customBin);

        /* STL BINARY SEARCH TREE */
        STLBinarySearch(IntRandData, searchedValue, STLBin);
        
        /* HASH TABLE */
        hashTableSearch(IntRandData, searchedValue, hashLin, arraySize);
        
    } else if (dataType == 2) {
        /* PRINT HEADER */
        headerPrinter(dataType, arraySize, searchIndex);

        /*  GENERATE RANDOM TEST DATA  */
        vector<float> FloatRandData(arraySize);
        generate(FloatRandData.begin(), FloatRandData.end(), RandomGenerator<float>(RANDOM_MIN, RANDOM_MAX));
        //copy(FloatRandData.begin(), FloatRandData.end(), ostream_iterator<float> (cout, " "));
        float floatSearchValue = FloatRandData[searchIndex];

        /*       ARRAY       */
        arraySearch(FloatRandData, floatSearchValue, 1, arrayLin);
        arraySearch(FloatRandData, floatSearchValue, 2, arrayBin);

        /*  CIRCULAR ARRAY  */
        circArraySearch(FloatRandData, floatSearchValue, 1, circLin);
        circArraySearch(FloatRandData, floatSearchValue, 2, circBin);

        /*    LINKED LIST    */
        linkedListSearch(FloatRandData, floatSearchValue, 1, singlyLin);
        linkedListSearch(FloatRandData, floatSearchValue, 2, singlyBin);

        /* DOUBLE LINKED LIST */
        doubleLinkedListSearch(FloatRandData, floatSearchValue, 1, doublyLin);
        doubleLinkedListSearch(FloatRandData, floatSearchValue, 2, doublyBin);

        /* CUSTOM BINARY SEARCH TREE */
        customBinarySearch(FloatRandData, floatSearchValue, customBin);

        /* STL BINARY SEARCH TREE */
        STLBinarySearch(FloatRandData, floatSearchValue, STLBin);
        
        /* HASH TABLE */
        hashTableSearch(FloatRandData, floatSearchValue, hashLin, arraySize);
        
    } else if (dataType == 3) {
        /* PRINT HEADER */
        headerPrinter(dataType, arraySize, searchIndex);

        /*  GENERATE RANDOM TEST DATA  */
        vector<double> DoubleRandData(arraySize);
        generate(DoubleRandData.begin(), DoubleRandData.end(), RandomGenerator<float>(RANDOM_MIN, RANDOM_MAX));
        //copy(DoubleRandData.begin(), DoubleRandData.end(), ostream_iterator<float> (cout, " "));
        double doubleSearchValue = DoubleRandData[searchIndex];

        /*       ARRAY       */
        arraySearch(DoubleRandData, doubleSearchValue, 1, arrayLin);
        arraySearch(DoubleRandData, doubleSearchValue, 2, arrayBin);

        /*  CIRCULAR ARRAY  */
        circArraySearch(DoubleRandData, doubleSearchValue, 1, circLin);
        circArraySearch(DoubleRandData, doubleSearchValue, 2, circBin);

        /*    LINKED LIST    */
        linkedListSearch(DoubleRandData, doubleSearchValue, 1, singlyLin);
        linkedListSearch(DoubleRandData, doubleSearchValue, 2, singlyBin);

        /* DOUBLE LINKED LIST */
        doubleLinkedListSearch(DoubleRandData, doubleSearchValue, 1, doublyLin);
        doubleLinkedListSearch(DoubleRandData, doubleSearchValue, 2, doublyBin);

        /* CUSTOM BINARY SEARCH TREE */
        customBinarySearch(DoubleRandData, doubleSearchValue, customBin);

        /* STL BINARY SEARCH TREE */
        STLBinarySearch(DoubleRandData, doubleSearchValue, STLBin);
        
        /* HASH TABLE */
        hashTableSearch(DoubleRandData, doubleSearchValue, hashLin, arraySize);
    }

    return 0;
}

/******************************/
/*  FUNCTION IMPLEMENTATIONS  */
/******************************/
template <typename T>
void arraySearch(const vector<T>& Data, const T& searchValue, const int& mode, timeData& dataStruct) {
    vector<double>  execTimes;
    List<T>         array;
    int             index;

    /* Display header, Initialize array and Measure execution times */
    if (mode == 1) {
        /* Display header */
        cout << setw(20) << right << "array |" << setw(9) << right << "linear |";
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each : Data) {
            array.insertToEnd(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        dataStruct.insertionTime = static_cast<double>(duration.count());
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
        cout << setw(20) << right << "array |" << setw(9) << right << "binary |";
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each : Data) {
            array.insertOrdered(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        dataStruct.insertionTime = static_cast<double>(duration.count());
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
    dataStruct.mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    displayMeasuredTimes(dataStruct);
}

template <typename T>
void circArraySearch(const vector<T>& Data, const T& searchValue, const int& mode, timeData& dataStruct) {
    vector<double>      execTimes;
    CircList<T>         circArray;
    int                 index;

    /* Display header, Initialize array and Measure execution times */
    if (mode == 1) {
        /* Display header */
        cout << setw(20) << right << "circular array |" << setw(9) << right << "linear |";
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each : Data) {
            circArray.insertToEnd(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        dataStruct.insertionTime = static_cast<double>(duration.count());
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
        cout << setw(20) << right << "circular array |" << setw(9) << right << "binary |";
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each : Data) {
            circArray.insertOrdered(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        dataStruct.insertionTime = static_cast<double>(duration.count());
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
    dataStruct.mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    displayMeasuredTimes(dataStruct);
}

template <typename T>
void linkedListSearch(const vector<T>& Data, const T& searchValue, const int& mode, timeData& dataStruct) {
    vector<double>      execTimes;
    LinkedList<T>       linkedList;
    int                 index;

    /* Display header, Initialize array and Measure execution times */
    if (mode == 1) {
        /* Display header */
        cout << setw(20) << right << "singly linked list |" << setw(9) << right << "linear |";
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each : Data) {
            linkedList.insertToEnd(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        dataStruct.insertionTime = static_cast<double>(duration.count());
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
        cout << setw(20) << right << "singly linked list |" << setw(9) << right << "binary |";
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each: Data) {
            linkedList.insertOrdered(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        dataStruct.insertionTime = static_cast<double>(duration.count());
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
    dataStruct.mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double)execTimes.size();
    displayMeasuredTimes(dataStruct);
}

template <typename T>
void doubleLinkedListSearch(const vector<T>& Data, const T& searchValue, const int& mode, timeData& dataStruct) {
    vector<double>          execTimes;
    DoubleLinkedList<T>     doubleLinkedList;
    int                     index;

    /* Display header, Initialize array and Measure execution times */
    if (mode == 1) {
        /* Display header */
        cout << setw(20) << right << "doubly linked list |" << setw(9) << right << "linear |";
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each: Data) {
            doubleLinkedList.insertToEnd(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        dataStruct.insertionTime = static_cast<double>(duration.count());
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
        cout << setw(20) << right << "doubly linked list |" << setw(9) << right << "binary |";
        /* Initialize array */
        auto start = chrono::high_resolution_clock::now();
        for (const auto &each: Data) {
            doubleLinkedList.insertOrdered(each);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        dataStruct.insertionTime = static_cast<double>(duration.count());
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
    dataStruct.mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double) execTimes.size();
    displayMeasuredTimes(dataStruct);
}

template <typename T>
void customBinarySearch(const vector<T>& Data, const T& searchValue, timeData& dataStruct){
    vector<double>          execTimes;
    CustomBinaryTree<T>     binaryTree;

    /* Display header */
    cout << setw(20) << right << "custom binary tree |" << setw(9) << right << "binary |";
    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each : Data) {
        binaryTree.insert(each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    dataStruct.insertionTime = static_cast<double>(duration.count());
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
    dataStruct.mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double) execTimes.size();
    displayMeasuredTimes(dataStruct);
}

template <typename T>
void STLBinarySearch(const vector<T>& Data, const T& searchValue, timeData& dataStruct) {
    vector<double>          execTimes;
    STLBinaryTree<T>        binaryTree;

    /* Display header */
    cout << setw(20) << right << "STL binary tree |" << setw(9) << right << "binary |";
    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each : Data) {
        binaryTree.insert(each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    dataStruct.insertionTime = static_cast<double>(duration.count());
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
    dataStruct.mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double) execTimes.size();
    displayMeasuredTimes(dataStruct);
}

template <typename T>
void hashTableSearch(const vector<T>& Data, const T& searchValue, timeData& dataStruct, const int& arraySize) {
    vector<double>          execTimes;
    HashTable<T, T>         hashTable(arraySize*2);
    T                       value;

    /* Display header */
    cout << setw(20) << right << "hash table |" << setw(9) << right << "linear |";
    /* Initialize array */
    auto start = chrono::high_resolution_clock::now();
    for (const auto &each : Data) {
        hashTable.insert(each, each);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    dataStruct.insertionTime = static_cast<double>(duration.count());
    /* Measure execution times */
    for (int i = 0; i < measureN; i++) {
        start = chrono::high_resolution_clock::now();
        bool retval = hashTable.find(searchValue, value);
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
    dataStruct.mean = accumulate(execTimes.begin(), execTimes.end(), 0.0) / (double) execTimes.size();
    displayMeasuredTimes(dataStruct);
}

void extractJSON(const string& jsonData, int& dataType, int& arraySize, int& searchIndex) {
    json j = json::parse(jsonData); // Parse the JSON string

    if (j.find("dataType") != j.end() && j["dataType"].is_number_integer()) {
        dataType = j["dataType"];
    }

    if (j.find("arraySize") != j.end() && j["arraySize"].is_number_integer()) {
        arraySize = j["arraySize"];
    }

    if (j.find("searchIndex") != j.end() && j["searchIndex"].is_number_integer()) {
        searchIndex = j["searchIndex"];
    }
}

void displayMeasuredTimes(const timeData& dataStruct) {
    cout << setw(12)<< right << fixed << setprecision(1) << dataStruct.insertionTime << " ns |";
    cout << setw(10)<< right << fixed << setprecision(1) << dataStruct.mean << " ns |";
    cout << setw(12) << right << fixed << setprecision(1) << dataStruct.insertionTime + dataStruct.mean << " ns" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
}

void headerPrinter(const int& dataType, const int& arraySize, const int& searchIndex) {
    if (dataType == 1) {
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-------   INTEGER, MAX ARRAY SIZE: " << setw(5) << left << arraySize << ", INDEX TO SEARCH FOR: " << setw(5) << left << searchIndex << " --------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;

    } else if (dataType == 2) {
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "--------   FLOAT, MAX ARRAY SIZE: " << setw(5) << left << arraySize << ", INDEX TO SEARCH FOR: " << setw(5) << left << searchIndex << "   -------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
    } else if (dataType == 3) {
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "--------   DOUBLE, MAX ARRAY SIZE: " << setw(5) << left << arraySize << ", INDEX TO SEARCH FOR: " << setw(5) << left << searchIndex << "  -------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
    }
    cout << setw(20) << right << "Data Structure |" << setw(9) << right << " Search |" <<
    setw(12) << right << " Insertion Time |" << setw(10) << right << "  Search Time |" << setw(12) << right << "   Overall Time" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
}
