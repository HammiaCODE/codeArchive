//
// Created by hanes on 11/29/2024.
//

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <vector>
using namespace std;

class BubbleSortAlg {
    public:
    void bubbleSort(vector<int>& vec) {
        int n = vec.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (vec[j] > vec[j + 1]) {
                    int temp = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = temp;
                }
            }
        }
    }
};

#endif //BUBBLESORT_H
