/*
 * author: Lin, Kuan-You
 * date: 3/3/2021
 * 2021 NYU Tandon Bridge Homework 9 Question 4
 *
Implement the function:
void oddsKeepEvensFlip(int arr[], int arrSize)

This function gets an array of integers arr and its logical size arrSize.
When called, it should reorder the elements of arr so that:
1. All the odd numbers come before all the even numbers
2. The odd numbers will keep their original relative order
3. The even numbers will be placed in a reversed order (relative to their original order).

For example, if arr = [5, 2, 11, 7, 6, 4],
after calling oddsKeepEvensFlip(arr, 6), arr will be: [5, 11, 7, 4, 6, 2]
 */


#include <iostream>

using namespace std;

const int arrSize{6};

void printArr(int* arr, int arrSize);
void oddsKeepEvensFlip(int arr[], int arrSize);


int main() {
    int arr1[arrSize] = {5, 2, 11, 7, 6, 4};
    int arr2[arrSize] = {5, 3, 4, 5, -1, -3};
    int arr3[arrSize] = {4, 2, 6, 10, 22, 2};
    int arr4[arrSize] = {4, 2, 6, 7, 9, 10};
    int arr5[arrSize] = {7, 9, 10, 4, 2, 6};

    cout << "The original array " << endl;
    printArr(arr1, arrSize);
    printArr(arr2, arrSize);
    printArr(arr3, arrSize);
    printArr(arr4, arrSize);
    printArr(arr5, arrSize);

    oddsKeepEvensFlip(arr1, arrSize);
    oddsKeepEvensFlip(arr2, arrSize);
    oddsKeepEvensFlip(arr3, arrSize);
    oddsKeepEvensFlip(arr4, arrSize);
    oddsKeepEvensFlip(arr5, arrSize);

    cout << "The array1 after the function-call" << endl;
    printArr(arr1, arrSize);
    printArr(arr2, arrSize);
    printArr(arr3, arrSize);
    printArr(arr4, arrSize);
    printArr(arr5, arrSize);

    return 0;
}

void printArr(int* arr, int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void oddsKeepEvensFlip(int arr[], int arrSize){
    // function can be easier if we implement it using reference to array (pointer); int*& arr;
    int* newArr = new int[arrSize];
    int newArrSize{0};
    for (int i = 0; i < arrSize; i++){
        if ((arr[i] % 2 == 1) or (arr[i] % 2 == -1)) {
            newArr[newArrSize] = arr[i];
            newArrSize++;
        }
    }
    for (int i = arrSize - 1; i >= 0; i--){
        if (arr[i] % 2 == 0){
            newArr[newArrSize] = arr[i];
            newArrSize++;
        }
    }
    for (int i = 0; i < arrSize; i++){
        arr[i] = newArr[i];
    }
    delete[] newArr;
}