#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void bucketSort(vector<int> & result, const vector<int> & src, const int bucketNum);
int getBucketIndex(int capacity, int min, int value);

int main() {
    vector<int> src = {4,1,7,2,9,3,0,6,5,8,11};
    vector<int> result(src.size());
    int bucketNum = 3;
    bucketSort(result, src, bucketNum);
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}

void bucketSort(vector<int> & result,
                const vector<int> & src,
                const int bucketNum) {
    if (src.size() < 2) {
        return;
    }

    int myBucketNum = (src.size() < bucketNum) ? src.size() : bucketNum;
    vector<vector<int>> buckets(myBucketNum);
    int max = *max_element(src.begin(), src.end());
    int min = *min_element(src.begin(), src.end());

    if (max == min) {
        return;
    }

    int capacity = ceil( (double)(max-min+1) / (double)myBucketNum );
    for (int value : src) {
        int bucketIndex = getBucketIndex(capacity, min, value);
        buckets[bucketIndex].push_back(value);
    }

    // merge bucket
    int index = 0;
    for (vector<int> singleBucket : buckets) {
        // sort each bucket
        sort(singleBucket.begin(), singleBucket.end());
        for (int value : singleBucket) {
            result[index++] = value;
        }
    }
}

int getBucketIndex(int capacity, int min, int value) {
    return (value - min) / capacity;
}
