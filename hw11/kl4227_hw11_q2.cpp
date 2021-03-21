/*
 * author: Lin, Kuan-You
 * date: 3/19/2021
 * 2021 NYU Tandon Bridge Homework 11 Question 2

Recursive problem. Please refer to the document.

 */

#include <iostream>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
void printArr(const int arr[], int arrSize);

int main() {
    cout << boolalpha;

    int arr1[4]{2, -1, 3, 10};
    int arrSize1{4};
    cout << "Test Array1: " << endl;
    printArr(arr1, arrSize1);
    cout << "Result: " << endl;
    cout << sumOfSquares(arr1, arrSize1) << endl;
    cout << isSorted(arr1, arrSize1) << endl;
    cout << endl;

    int arr2[2]{1, -1};
    int arrSize2{2};
    cout << "Test Array2: " << endl;
    printArr(arr2, arrSize2);
    cout << "Result: " << endl;
    cout << sumOfSquares(arr2, arrSize2) << endl;
    cout << isSorted(arr2, arrSize2) << endl;
    cout << endl;

    int arr3[5]{1, 2, 3, 4, 5};
    int arrSize3{5};
    cout << "Test Array3: " << endl;
    printArr(arr3, arrSize3);
    cout << "Result: " << endl;
    cout << sumOfSquares(arr3, arrSize3) << endl;
    cout << isSorted(arr3, arrSize3) << endl;
    cout << endl;

    int arr4[5]{1, 1, 2};
    int arrSize4{3};
    cout << "Test Array4: " << endl;
    printArr(arr4, arrSize4);
    cout << "Result: " << endl;
    cout << sumOfSquares(arr4, arrSize4) << endl;
    cout << isSorted(arr4, arrSize4) << endl;
    cout << endl;

    int arr5[1]{1};
    int arrSize5{1};
    cout << "Test Array5: " << endl;
    printArr(arr5, arrSize5);
    cout << "Result: " << endl;
    cout << sumOfSquares(arr5, arrSize5) << endl;
    cout << isSorted(arr5, arrSize5) << endl;
    cout << endl;

    int arr6[2]{-6, -4};
    int arrSize6{2};
    cout << "Test Array6: " << endl;
    printArr(arr6, arrSize6);
    cout << "Result: " << endl;
    cout << sumOfSquares(arr6, arrSize6) << endl;
    cout << isSorted(arr6, arrSize6) << endl;
    cout << endl;

    return 0;
}

void printArr(const int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int sumOfSquares(int arr[], int arrSize){
    if (arrSize == 0){
        return 0;
    } else {
        return sumOfSquares(arr, arrSize - 1) + arr[arrSize - 1]*arr[arrSize - 1];
    }
}

bool isSorted(int arr[], int arrSize){
    // strictly ascending instead of non-decreasing
    if (arrSize == 1){
        return true; // if the array contains only one element, it is considered sorted
    } else {
        if (isSorted(arr, arrSize - 1)){
            return arr[arrSize - 2] < arr[arrSize - 1];  // strictly ascending
        } else {
            return false;
        }
    }
}