//
// Created by hanes on 11/29/2024.
//

#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <iostream>
using namespace std;

class linearSearchAlg {
public:
    int linearSearch(vector <int> linear, int search){
        for(int num : linear) {
            if(num > search) {
                return num;
            }
        }
        return -1;
    };
};

#endif //LINEARSEARCH_H
