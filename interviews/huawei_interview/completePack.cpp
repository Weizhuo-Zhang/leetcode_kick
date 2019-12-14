#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ZeroOnePack(vector<int> & package, int cost, int weight);

int main() {
    int N = 7;
    int S = 15;
    vector<int> items {1, 4, 3, 4, 5, 2, 7}; // weight
    vector<int> package(S+1); //capacity

    for (int i = 1; i <= N; i++) {
        ZeroOnePack(package, items[i], items[i]);
    }
    cout << package[S] << endl;
    return 0;
}

void ZeroOnePack(vector<int> & package, int cost, int weight) {
    for (int j = package.size()-1; j >= cost; j--) {
        // max(f[v], f[v-cost]+weight)
        package[j] = max(package[j], package[j-cost] + weight);
    }
}
