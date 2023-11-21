//
// Created by Manoloon on 27/10/2023.
//

#ifndef ALGORITHMS_UNION_FIND_H
#define ALGORITHMS_UNION_FIND_H
#include <vector>
class UnionFind {
public:
    UnionFind() = default;

    explicit UnionFind(int N) : number(N) {};

    void Union(int p,int q)
    {
        int pID = id[p];
        int qID = id[q];
        for (auto i : id) {
            if (id[i] == pID) {
                id[i] = qID;
            }
        }
    }

    bool isConnected(int p, int q) {
        return id[p] == id[q];
    }

private:
    int number = 10;
    std::vector<int> id;
};

#endif //ALGORITHMS_UNION_FIND_H
