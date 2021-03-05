/*
 * author: Lin, Kuan-You
 * date: 3/3/2021
 * 2021 NYU Tandon Bridge Homework 8 Question 1
 *
Write a program that reads from the user a sequence of 20 integers (unnecessarily different
from one another) into an array, and outputs the minimum value, and all the indices it
appears in the array.

Your program should interact with the user exactly as it shows in the following example:

Please enter 20 integers separated by a space:
14 5 12 5 6 14 5 12 14 12 14 6 8 7 5 136 9 2189 10 6

The minimum value is 5, and it is located in the following indices: 1 3 6 14
 */

#include <iostream>

using namespace std;

int minInArray(int arr[], int arrSize);

void matchIndices(int arr[], int& arrSize, int target);

int main() {
    int arrSize{20};
    int arr[arrSize];
    cout << "Please enter " << arrSize << " integers separated by a space:" << endl;
    for (int i = 0; i < arrSize; i++){
        cin >> arr[i];
    }

    int target = minInArray(arr, arrSize);

    cout << "The minimum value is " << target << ", and it is located in the following indices: ";

    matchIndices(arr, arrSize, target);

    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

int minInArray(int arr[], int arrSize){
    int smallest{arr[0]};
    for (int i = 0; i < arrSize; i++){
        if (smallest > arr[i]){
            smallest = arr[i];
        }
    }
    return smallest;
}

void matchIndices(int arr[], int& arrSize, int target){
    int counter{0};
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == target) {
            arr[counter] = i;
            counter++;
        }
    }
    arrSize = counter;
}

