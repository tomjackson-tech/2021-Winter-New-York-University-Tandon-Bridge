/*
 * author: Lin, Kuan-You
 * date: 3/13/2021
 * 2021 NYU Tandon Bridge Homework 10 Question 2
 *
Implement the function:

 int* findMissing(int arr[], int n, int& resArrSize)

This function gets an array of integers arr and its logical size n.

All elements in arr are in the range {0, 1, 2, ... , n}.

Note that since the array contains n numbers taken from a range of size n+1,
 there must be at least one number that is missing (could be more than one number missing,
 if there are duplicate values in arr).

When called, it should create and return a new array,
 that contains all the numbers in range {0, 1, 2, ... , n} that are not in arr.
 he function should also update the output parameter, resArrSize,
 with the logical size of the new array that was created.
 */

#include <iostream>

int* findMissing(const int arr[], int n, int& resArrSize);
void pruneArr(int* arr, int target, int& arrSize);
void printArr(const int arr[], const int& arrSize);

using namespace std;

int main() {
    int arr1[6]{3, 1, 3, 0, 6, 4};
    int arr2[6]{1, 2, 3, 4, 5, 6};
    int arr3[4]{2, 2, 2, 2};
    cout << "Testing the following arrays: " << endl;
    printArr(arr1, 6);
    printArr(arr2, 6);
    printArr(arr3, 4);

    int resArrSize1{0};
    int resArrSize2{0};
    int resArrSize3{0};

    int* resArr1 = findMissing(arr1, 6, resArrSize1);
    int* resArr2 = findMissing(arr2, 6, resArrSize2);
    int* resArr3 = findMissing(arr3, 4, resArrSize3);

    cout << "The results are: " << endl;
    printArr(resArr1, resArrSize1);
    printArr(resArr2, resArrSize2);
    printArr(resArr3, resArrSize3);
    return 0;
}

void printArr(const int arr[], const int& arrSize){
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}


int* findMissing(const int arr[], int n, int& resArrSize){
    int* lookupArr = new int[n + 1];
    int sequenceArr[n + 1];

    // initialize 2 arrays: one for sequence range, and another for marking position
    for(int i = 0; i < n + 1; i++){
        sequenceArr[i] = i + 1;
    }
    for(int i = 0; i < n + 1; i++){
        lookupArr[i] = 1;
    }

    // if we have such a number, mark the corresponding position as 0
    for(int i = 0; i < n; i++){
        lookupArr[arr[i]] = 0;
    }

    // get the remaining numbers by multiplying range sequence to the priorly marked array.
    for(int i = 0; i < n + 1; i++){
        lookupArr[i] *= sequenceArr[i];
    }

    // extract the remaining parts of the sequence
    int arrSize{n + 1};
    pruneArr(lookupArr, 0, arrSize);

    resArrSize = arrSize;
    return lookupArr;
}

void pruneArr(int* arr, int target, int& arrSize){
    // This function will reduce the array and drop the 0 element and reconnect other elements minus 1.
    int newArrSize{0};
    for(int i = 0; i < arrSize; i++){
        if(arr[i] != target){
            arr[newArrSize] = arr[i] - 1;
            newArrSize++;
        }
    }
    arrSize = newArrSize;
}