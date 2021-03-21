/*
 * author: Lin, Kuan-You
 * date: 3/19/2021
 * 2021 NYU Tandon Bridge Homework 11 Question 4

Recursive problem. Please refer to the document.

 */

#include <iostream>

using namespace std;

int optimizeJumpGame(int arr[], int arrSize);

int main() {

    int arr1[]{0, 3, 80, 6, 57, 10};
    int arrSize1{6};
    cout << optimizeJumpGame(arr1, arrSize1) << endl;

    int arr2[]{0, 1, 100, -1, 1, 50, 60, -200};
    int arrSize2{8};
    cout << optimizeJumpGame(arr2, arrSize2) << endl;

    int arr3[]{0, 1, 100, 1, 100, 1, 1, 100, 1};
    int arrSize3{9};
    cout << optimizeJumpGame(arr3, arrSize3) << endl;
    return 0;
}

int optimizeJumpGame(int arr[], int arrSize) {
    // with the brute force to find the lowest cost
    // can be optimized using dynamic programming technique
    if (arrSize == 1){
        return arr[0];
    } else if (arrSize == 2){
        return arr[0] + arr[1];
    } else {
        int one_step = optimizeJumpGame(arr + 1, arrSize - 1);
        int two_step = optimizeJumpGame(arr + 2, arrSize - 2);
        if (one_step < two_step){
            return arr[0] + one_step;
        } else {
            return arr[0] + two_step;
        }
    }
}