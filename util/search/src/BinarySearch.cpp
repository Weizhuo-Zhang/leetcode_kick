//
// Created by weizhuozhang on 21/10/19.
//

#include <stdio.h>
#include "../header/BinarySearch.h"

int BinarySearch::rank(int key, int *a, int arraySize) {
    int lo = 0;
    int hi = arraySize - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (key < a[mid])
            hi = mid - 1;
        else if (key > a[mid])
            lo = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main(int argc, char **args) {
    printf("%c");
    return  0;
}