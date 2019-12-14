#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParenthese(int left, int right, string output, vector<string> & results);

int main() {
    int n = 3;
    vector<string> results;
    generateParenthese(n, n, "", results);
    for (string result : results) {
        cout << result << endl;
    }
    return 0;
}

void generateParenthese(
        int left,
        int right,
        string output,
        vector<string> & results) {
    if (left > right) {
        return;
    }

    if (left == 0 && right == 0) {
        results.push_back(output);
    } else {
        if (left > 0) {
            generateParenthese(left-1, right, output+'(', results);
        }
        if (right > 0) {
            generateParenthese(left, right-1, output+')', results);
        }
    }
}
