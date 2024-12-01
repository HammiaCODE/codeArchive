//
// Created by hanes on 11/29/2024.
//

#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>
using namespace std;

class mergeSortAlg {
    public:
    void merge(vector<int>& leftArray,vector<int>& rightArray,vector<int>& arr){
        int leftSize=leftArray.size();
        int rightSize=rightArray.size();

        //indices
        int i=0;
        int l=0;
        int r=0;

        //main while
        while(l<leftSize && r<rightSize){
            if(leftArray[l]<rightArray[r]){
                arr[i]=leftArray[l];
                l++;
            }
            else{
                arr[i]=rightArray[r];
                r++;
            }
            i++;
        }

        //leftovers whiles
        while(l<leftSize){
            arr[i]=leftArray[l];
            i++;
            l++;
        }
        while(r<rightSize){
            arr[i]=rightArray[r];
            i++;
            r++;
        }
    }

    void mergeSort(std::vector<int>& arr){
        int n=arr.size();
        if(n<=1) return;
        int center=n/2;
        vector<int> leftArray(center);
        vector<int> rightArray(n-center);
        for(int i=0;i<n;i++){
            if(i<center){
                leftArray[i]=arr[i];
            }
            else{
                rightArray[i-center]=arr[i];
            }
        }

        //divide
        mergeSort(leftArray);
        mergeSort(rightArray);

        //conquer
        merge(leftArray,rightArray,arr);
    }

};

#endif //MERGESORT_H
