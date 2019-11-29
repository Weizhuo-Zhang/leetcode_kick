#include <iostream>
#include <vector>
using namespace std;

bool isPrime(const vector<int> primes, int num) {
    for (int prime : primes) {
        if (0 == num % prime) {
            return false;
        }
    }
    return true;
}

vector<int> getPrimes(int n) {
    vector<int> primes;
    primes.push_back(2);
    int num = 3;
    while (n != primes.size()) {
        if (isPrime(primes, num)) {
            primes.push_back(num);
        }
        num++;
    }
    return primes;
}

int main(){
    int n,ans = 0;
    cin >> n;
    vector<int> primes = getPrimes(n);
    cout << "primes list: " << endl;
    for (int v : primes) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
