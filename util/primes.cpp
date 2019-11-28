// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> getPrimes(int n) {
    int multiple;
    int maxNum = 3 * n * (log(n) + log(log(n)) - 1);
    vector<int> primes;
    for (int i = 0; i <= n; i++) {
        primes.push_back(1);
    }
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i <= sqrt(maxNum); i++) {
        if (1 == primes[i]) {
            for (multiple = 2; multiple*i <= n; multiple++) {
                primes[multiple*i] = 0;
            }
        }
    }
    for (int i = 2; i <= n+1; i++) {
        if (primes[i] == 1)
            cout << i << endl;
    }
    return primes;
}

int main(){
    //freopen("1.in","r",stdin);
    int n,ans = 0;
    cin >> n;
    // vector<int> vlist(n);
    // for(int i = 0; i < n; i++){
    //     cin >> vlist[i];
    // }
    vector<int> primes = getPrimes(n);
    // for (int v : primes) {
    //     cout << v << endl;
    // }
    // cout << ans << endl;
    return 0;
}
