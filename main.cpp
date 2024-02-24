#include <iostream>
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
#include "random_generator.h"

#define RANDOM_MIN      0
#define RANDOM_MAX      100000
#define measureN        30

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
/* Others */
void extractJSON(const string& jsonData, int& dataType, int& arraySize, int& searchIndex);
template <typename T>
void displayVector(const vector<T>& Vector);
void displayMeasuredTimes(const timeData& dataStruct);
json createJSON(const int& dataType, const int& arraySize, const int& index);

/***************************/
/*          MAIN           */
/***************************/
int main() {
    /*********************/
    /*  SEEDING RANDOM:  */
    /*********************/
    srand(time(nullptr));

    /***********************/
    /*      VARIABLES      */
    /***********************/
    int datatype      =     2;      // 1: integer, 2: float, 3: double
    int testDataSize  =  1000;      // MIN: 100 MAX: 50,000
    int index         =   246;

    /**********************/
    /*    EXTRACT JSON    */
    /**********************/
#if 1
    string jsonString = "{\"dataType\":2,\"arraySize\":333,\"searchIndex\":125}"; //Example json string
    int dataType, arraySize, searchIndex;
    extractJSON(jsonString, dataType, arraySize, searchIndex);
    cout << "dataType: " << dataType << " arraySize: " << arraySize << " searchIndex: " << searchIndex << endl;
#endif

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

            break;

        case 2:
            cout << "---------------------------------------------------------------" << endl;
            cout << "----------------------      FLOAT      ------------------------" << endl;
            cout << "---------------------------------------------------------------" << endl;

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

            break;

        case 3:
            cout << "---------------------------------------------------------------" << endl;
            cout << "---------------------      DOUBLE      ------------------------" << endl;
            cout << "---------------------------------------------------------------" << endl;

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

            break;

        default:
            break;
    }

    /******************************/
    /*      CREATE JSON DATA      */
    /******************************/
    json jsonDataOUT = createJSON(datatype, testDataSize, index);
    cout << jsonDataOUT << endl;

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
        cout << "ARRAY LINEAR SEARCH:" << endl;
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
        cout << "ARRAY BINARY SEARCH:" << endl;
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
        cout << "CIRCULAR ARRAY LINEAR SEARCH:" << endl;
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
        cout << "CIRCULAR ARRAY BINARY SEARCH:" << endl;
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
        cout << "SINGLY LINKED LIST LINEAR SEARCH:" << endl;
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
        cout << "SINGLY LINKED LIST BINARY SEARCH:" << endl;
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
        cout << "DOUBLY LINKED LIST LINEAR SEARCH:" << endl;
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
        cout << "DOUBLY LINKED LIST BINARY SEARCH:" << endl;
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
    cout << "CUSTOM BINARY TREE SEARCH:" << endl;
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
    cout << "STL BINARY TREE SEARCH:" << endl;
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

void displayMeasuredTimes(const timeData& dataStruct) {
    cout << "Insertion time: " << fixed << setprecision(1) << dataStruct.insertionTime << " ns" << endl;
    cout << "Average exec time: " << fixed << setprecision(1) << dataStruct.mean << " ns" << endl;
    cout << "Overall time: " << fixed << setprecision(1) << dataStruct.insertionTime + dataStruct.mean << " ns" << endl;
    cout << "---------------------------------------------------------------" << endl;
}

json createJSON(const int& dataType, const int& arraySize, const int& index) {
    json jsonData;

    // Adding received parameters
    jsonData["data"]["params"] = {
            {"datatype", dataType},
            {"arraySize", arraySize},
            {"index", index}
    };

    // Adding measurements
    jsonData["data"]["values"] = {
            {"arrayLin_ins", arrayLin.insertionTime},
            {"arrayLin_mean", arrayLin.mean},
            {"arrayBin_ins", arrayBin.insertionTime},
            {"arrayBin_mean", arrayBin.mean},
            {"circLin_ins", circLin.insertionTime},
            {"circLin_mean", circLin.mean},
            {"circBin_ins", circBin.insertionTime},
            {"circBin_mean", circBin.mean},
            {"singlyLin_ins", singlyLin.insertionTime},
            {"singlyLin_mean", singlyLin.mean},
            {"singlyBin_ins", singlyBin.insertionTime},
            {"singlyBin_mean", singlyBin.mean},
            {"doublyLin_ins", doublyLin.insertionTime},
            {"doublyLin_mean", doublyLin.mean},
            {"doublyBin_ins", doublyBin.insertionTime},
            {"doublyBin_mean", doublyBin.mean},
            {"customBin_ins", customBin.insertionTime},
            {"customBin_mean", customBin.mean},
            {"STLBin_ins", STLBin.insertionTime},
            {"STLBin_mean", STLBin.mean}
    };

    return jsonData;
}