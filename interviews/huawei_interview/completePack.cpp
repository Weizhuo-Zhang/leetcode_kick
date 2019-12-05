#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N = 7;
    int S = 15;
    vector<int> items {1, 4, 3, 4, 5, 2, 7};
    sort(items.begin(), items.end());
    vector<int> package(N);

    for (int i = 1; i < N; i++) {
        int counter = 0;
        for (int j = N-1; j >= 0; j--) {
            package[i] = package[i-1];
            if (S - package[i] <= items[j]) {
                counter++;
                package[i] += items[j];
            }
            if (counter == i) {
                break;
            }
        }
    }
    return 0;
}
