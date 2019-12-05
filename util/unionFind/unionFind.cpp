#include <iostream>
using namespace std;

class UnionFind {
private:
    int arraySize;
    int* father;
    int* rank;

public:
    UnionFind(int n) {
        arraySize = n;
        father = new int[n+1];
        rank = new int[n+1];
        init();
    }

    ~UnionFind() {
        delete [] father;
        delete [] rank;
    }

    void init() {
        for (int i = 1; i <= arraySize; i++) {
            father[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find(father[x]);
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rank[x] < rank[y]) {
                father[x] = y;
            } else {
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
                father[y] = x;
            }
        }
    }
};

int main() {
    const int pairSize = 8;
    const int testSize = 6;
    int pairArray[pairSize][2] =
        {{1, 2},
         {1, 3},
         {2, 4},
         {5, 6},
         {5, 7},
         {6, 8},
         {7, 9},
         {10, 11}};
    int testArray[testSize][2] =
        {{4, 6},
         {3, 9},
         {5, 9},
         {11, 6},
         {7, 8},
         {3, 4}};

    UnionFind unionFind(11);
    for (int i = 0; i < pairSize; i++) {
        unionFind.unionSet(pairArray[i][0], pairArray[i][1]);
    }
    for (int i = 0; i < testSize; i++) {
        if (unionFind.find(testArray[i][0]) == unionFind.find(testArray[i][1])) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
