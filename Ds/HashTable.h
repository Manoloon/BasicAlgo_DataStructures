//
// Created by pablo on 9/11/2023.
//

#ifndef DATASTRUCTURE_HASHTABLE_H
#define DATASTRUCTURE_HASHTABLE_H

#include <vector>
#include <list>

template<typename T>
class HashTable {
    int NumElements = 0;
    double LoadFactor = 0.7;
    std::vector<std::list<std::pair<int, T>>> Table;

public:
    explicit HashTable(int InitSize) : Table(InitSize) {}

    void Insert(int Key, T Value) {
        int Index = Hash(Key);
        Table[Index].emplace_back(Key, Value);
        NumElements++;

        if (NumElements > Table.size() * LoadFactor) {
            Resize();
        }
    }

    void Remove(int Key) {
        int Index = Hash(Key);
        for (auto it = Table[Index].begin(); it != end(Table[Index]); ++it) {
            if (it->first == Key) {
                Table[Index].erase(it);
                NumElements--;
                return;
            }
        }
    }

    T Get(int Key) {
        int Index = Hash(Key);
        for (const auto &pair: Table[Index]) {
            if (pair.first == Key) {
                return pair.second;
            }
        }
        return T();
    }

    void Resize() {
        int NewSize = Table.size() * 2;
        std::vector<std::list<std::pair<int, T>>> TempTable(NewSize);
        for (const auto &list: Table) {
            for (const auto &pair: list) {
                const int NewKey = pair.first % NewSize;
                TempTable[NewKey].emplace_back(pair);
            }
        }
        Table = TempTable;
    }

private:

    [[nodiscard]]
    int Hash(int Key) const {
        return Key % Table.size();
    }
};

#endif //DATASTRUCTURE_HASHTABLE_H
