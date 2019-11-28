// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //freopen("1.in","r",stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int ans = 0;
        int length = 0;
        cin >> length;
        vector<int> vlist(length);
        for(int j = 0; j < length; j++){
            cin >> vlist[j];
        }
        sort(vlist.begin(), vlist.end());
        // for (int v : vlist) {
        //     cout << v << endl;
        // }

        int maxNum = vlist.back();
        for(int j = 0; j < length-1; j++){
            int doubleNum = vlist[j] * 2;
            if (doubleNum > maxNum) {
                break;
            }
            // cout << "doubleNum: " << doubleNum << endl;
            for (int k = j+1; k < length; k++) {
                // cout << "vlist[k]: " << vlist[k] << endl;
                if (doubleNum == vlist[k]) {
                    ans += 1;
                } else if (doubleNum < vlist[k]) {
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
