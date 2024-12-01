//
// Created by hanes on 11/29/2024.
//

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
using namespace std;

class selectSortAlg {
    public:

    void mySwap(int & a, int & b) {
        int temp =a;
        a=b;
        b=temp;
    }

    void selectionSort(vector<int>& vec) {
        int n= vec.size();

        for(int i=0 ; i<n ; i++) {
            int minVal = i;
            for(int j= i+1; j<n; j++) {
                if(vec[j] < vec[minVal]) {
                    minVal= j;
                }
            }
            if(minVal != i) {
                mySwap(vec[i], vec[minVal]);
            }
        }
    }
};

#endif //SELECTIONSORT_H
