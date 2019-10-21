//
// Created by Weizhuo Zhang on 2019/10/19.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.empty()) {
            return result;
        }//if
        int row = matrix.size();
        int col = matrix[0].size();
        int count = row * col;
        int index = 1;
        int beginX = 0, endX = row - 1;
        int beginY = 0, endY = col - 1;
        while(index <= count){
            // go right
            for(int i = beginY;i <= endY;++i){
                result.push_back(matrix[beginX][i]);
                ++index;
            }//for
            ++beginX;
            if(beginX > endX){
                break;
            }//if

            // go down
            for(int i = beginX;i <= endX;++i){
                result.push_back(matrix[i][endY]);
                ++index;
            }//for
            --endY;
            if(endY < beginY){
                break;
            }//if

            // go left
            for(int i = endY;i >= beginY;--i){
                result.push_back(matrix[endX][i]);
                ++index;
            }//for
            --endX;
            if(endX < beginX){
                break;
            }//if

            // go up
            for(int i = endX;i >= beginX;--i){
                result.push_back(matrix[i][beginY]);
                ++index;
            }
            ++beginY;
            if(beginX > endY){
                break;
            }//if
        }//while
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int> > matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result = s.spiralOrder(matrix);
    // output
    for(int i = 0;i < result.size();++i){
        cout<<result[i]<<"  ";
    }//for
    cout<<endl;
    return 0;
}
