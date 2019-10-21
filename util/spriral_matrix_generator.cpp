//
// Created by Weizhuo Zhang on 2019/10/19.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n,vector<int>(n,0));
        if(n <= 0){
            return matrix;
        }//if
        int count = n * n;
        int index = 1;
        int x = 0,y = -1;
        while(index <= count){
            // go right
            ++y;
            while(y < n && matrix[x][y] == 0){
                matrix[x][y++] = index;
                ++index;
            }//while
            --y;

            // go down
            ++x;
            while(x < n && matrix[x][y] == 0){
                matrix[x++][y] = index;
                ++index;
            }//while
            --x;

            // go left
            --y;
            while(y >= 0 && matrix[x][y] == 0){
                matrix[x][y--] = index;
                ++index;
            }//while
            ++y;

            // go up
            --x;
            while(x >= 0 && matrix[x][y] == 0){
                matrix[x--][y] = index;
                ++index;
            }//while
            ++x;
        }//while
        return matrix;
    }
};

int main(){
    Solution s;
    int n = 5;
    vector<vector<int> > matrix = s.generateMatrix(n);
    // 输出
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            cout<<matrix[i][j]<<"  ";
        }//for
        cout<<endl;
    }//for
    return 0;
}
