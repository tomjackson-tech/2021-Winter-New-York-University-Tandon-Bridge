/*
 * author: Lin, Kuan-You
 * date: 3/3/2021
 * 2021 NYU Tandon Bridge Homework 9 Question 3
 *
In this question, you will write four versions of a function getPosNums that gets an array of integers arr,
and its logical size. When called it creates a new array containing only the positive numbers from arr.
For example, if arr=[3, -1, -3, 0, 6, 4],
the functions should create an array containing the following 3 elements: [3, 6, 4],
 */

#include <iostream>

using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize,
                 int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize,
                 int** outPosArrPtr, int* outPosArrSizePtr);
void printArr(int* arr, int arrSize);

int main() {
    int arrSize{6};
    int arr[6] = {3, -1, -3, 0, 6, 4};
    cout << "- The original array" << endl;
    printArr(arr, arrSize);

    cout << "- Implement 1" << endl;
    int outPosArrSize1{0};
    int* posNum1 =  getPosNums1(arr, arrSize, outPosArrSize1);
    printArr(posNum1, outPosArrSize1);

    cout << "- Implement 2" << endl;
    int outPosArrSize2{0};
    int* posNum2 =  getPosNums2(arr, arrSize, &outPosArrSize2);
    printArr(posNum2, outPosArrSize2);

    cout << "- Implement 3" << endl;
    int outPosArrSize3{0};
    int* posNum3{nullptr};
    getPosNums3(arr, arrSize, posNum3, outPosArrSize3);
    printArr(posNum3, outPosArrSize3);

    cout << "- Implement 4" << endl;
    int outPosArrSize4{0};
    int* posNum4{nullptr};
    getPosNums4(arr, arrSize, &posNum4, &outPosArrSize4);
    printArr(posNum4, outPosArrSize4);


    cout << "- The original array remains unchanged" << endl;
    printArr(arr, arrSize);

    return 0;
}

void printArr(int* arr, int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int posArrSize{0};
    int* posArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++){
       if (arr[i] > 0){
           posArr[posArrSize] = arr[i];
           posArrSize++;
       }
    }
    outPosArrSize = posArrSize;
    return posArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int posArrSize{0};
    int* posArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            posArr[posArrSize] = arr[i];
            posArrSize++;
        }
    }
    *outPosArrSizePtr = posArrSize;
    return posArr;
}

void getPosNums3(int* arr, int arrSize,
                 int*& outPosArr, int& outPosArrSize){
    int posArrSize{0};
    int* posArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            posArr[posArrSize] = arr[i];
            posArrSize++;
        }
    }
    outPosArrSize = posArrSize;
    outPosArr = posArr;
}

void getPosNums4(int* arr, int arrSize,
                 int** outPosArrPtr, int* outPosArrSizePtr){
    int posArrSize{0};
    int* posArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            posArr[posArrSize] = arr[i];
            posArrSize++;
        }
    }
    *outPosArrSizePtr = posArrSize;
    *outPosArrPtr = posArr;
}