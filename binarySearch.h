//
// Created by hanes on 11/29/2024.
//

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>
using namespace std;

class binarySearchAlg {
    public:
    int binarySearch(int arr[], int low, int high, int x)
    {
        if (high >= low) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                return mid;
            }

            if (arr[mid] > x) {
                return binarySearch(arr, low, mid - 1, x);

            }
            return binarySearch(arr, mid + 1, high, x);
        }
        return -1;
    }
};

#endif //BINARYSEARCH_H
