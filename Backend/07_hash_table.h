#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/*****************************************/
/*       class HashTable interface       */
/*****************************************/
template <class K, class V>
class HashTable {
public:
    HashTable(int tableSize0);
    ~HashTable();
    void insert(const K& key, const V& value); // For linear probing insertion
    bool find(const K& key, V& value) const;   // For linear probing search

private:
    class HashNode {
    public:
        K key;
        V value;
        HashNode(const K& key0, const V& value0) : key(key0), value(value0) {}
    };

    int tableSize;
    std::vector<HashNode*> table;

    int hash(const K& key) const;
};

/********************************************/
/*      class HashTable implementation      */
/********************************************/
template <class K, class V>
HashTable<K, V>::HashTable(int tableSize0) {
    tableSize = tableSize0;
    table.resize(tableSize, nullptr);
}

template <class K, class V>
HashTable<K, V>::~HashTable() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != nullptr) {
            delete table[i];
        }
    }
}

template <class K, class V>
void HashTable<K, V>::insert(const K& key, const V& value) {
    int index = hash(key) % tableSize;
    while (table[index] != nullptr) {
        // Linear probing: move to the next index
        index = (index + 1) % tableSize;
    }
    table[index] = new HashNode(key, value);
}

template <class K, class V>
bool HashTable<K, V>::find(const K& key, V& value) const {
    int index = hash(key) % tableSize;
    int originalIndex = index;
    while (table[index] != nullptr) {
        if (table[index]->key == key) {
            value = table[index]->value;
            return true;
        }
        // Linear probing: move to the next index
        index = (index + 1) % tableSize;
        // If we've cycled back to the original index, key doesn't exist
        if (index == originalIndex) {
            break;
        }
    }
    return false;
}

template <class K, class V>
int HashTable<K, V>::hash(const K& key) const {
    // Example hash function: simple modulo hashing
    return std::hash<K>{}(key);
}
