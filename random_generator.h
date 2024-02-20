#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
class RandomGenerator {
public:
    RandomGenerator(T min0, T max0) {
        min = min0;
        max = max0;
    }

    T operator()() {
        T number;
        do {
            number = static_cast<T>(rand()) / static_cast<T>(RAND_MAX) * (max - min) + min;
        } while (find(numbers.begin(), numbers.end(), number) != numbers.end());
        numbers.push_back(number);
        return number;
    }

private:
    T min;
    T max;
    vector<T> numbers;
};