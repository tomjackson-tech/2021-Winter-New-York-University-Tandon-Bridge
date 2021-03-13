/*
 * author: Lin, Kuan-You
 * date: 3/13/2021
 * 2021 NYU Tandon Bridge Homework 10 Question 3
 *
In this question,
 you will write two versions of a program that reads from the user a sequence of positive integers ending with -1,
 and another positive integer num that the user wishes to search for.

The program should then print all the line numbers in sequence entered by the user,
 that contain num, or a message saying that num does not show at all in the sequence.

a) The first version of the program, is not allowed to use the vector data structure.
b) The second version of the program, should use the vector data structure.

Please enter a sequence of positive integers, each in a separate line.
End you input by typing -1.
13
5
8
2
9
5
8
8
-1
Please enter a number you want to search.
5
5 shows in lines 2, 6.

 */

#include <iostream>
#include <vector>

using namespace std;

const int initialArrSize{5};

void main1();
void main2();
void doubleArrSize(int*& arr, int& arrSize);
int* searchNum1(const int arr[], int& arrSize, int target);
int* searchNum2(vector<int> sequence, int& arrSize, int target);
void outputResult(int target, const int* arr, const int& arrSize);

int main() {
    cout << "Executing Main1: " << endl;
    main1();
    cout << endl << "Executing Main2: " << endl;
    main2();
    return 0;
}

void main1(){
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    // input sequence
    int* arr = new int[initialArrSize];
    int arrSize{initialArrSize};
    int iterator{0};
    while (true){
        int element{0};
        cin >> element;
        if (element == -1){
            break;
        } else {
            arr[iterator] = element;
            iterator++;
            if (iterator == arrSize){
                doubleArrSize(arr, arrSize);
            }
        }
    }

    // input target
    cout << "Please enter a number you want to search." << endl;
    int target{0};
    cin >> target;

    // search target
    int locationArrSize{iterator};
    int* locationArr = searchNum1(arr, locationArrSize, target);

    // output
    outputResult(target, locationArr, locationArrSize);

    // free out the memory
    delete[] arr;
    delete[] locationArr;
}

void main2(){
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    // input sequence
    vector<int> sequence;
    int sequenceSize{0};
    while (true){
        int element{0};
        cin >> element;
        if (element == -1){
            break;
        } else {
            sequence.push_back(element);
            sequenceSize++;
        }
    }

    // input target
    cout << "Please enter a number you want to search." << endl;
    int target{0};
    cin >> target;

    // search target
    int locationArrSize{sequenceSize};
    int* locationArr = searchNum2(sequence, locationArrSize, target);

    // output
    outputResult(target, locationArr, locationArrSize);

    // free out the memory
    delete[] locationArr;
}

void outputResult(int target, const int* arr, const int& arrSize) {
    if (arrSize == 0) {
        cout << target << " does not show at all in the sequence." << endl;
    } else {
        cout << target << " shows in lines ";
        for (int i = 0; i < arrSize; i++) {
            cout << arr[i];
            if (i != (arrSize - 1)) {
                cout << ", ";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

int* searchNum1(const int arr[], int& arrSize, int target){
    int* newArr = new int[arrSize];
    int newArrSize{0};
    for(int i = 0; i < arrSize; i++){
        if(arr[i] == target){
            newArr[newArrSize] = i + 1;
            newArrSize++;
        }
    }
    arrSize = newArrSize;
    return newArr;
}

int* searchNum2(vector<int> sequence, int& arrSize, int target){
    int* newArr = new int[arrSize];
    int newArrSize{0};
    for(int i = 0; i < arrSize; i++){
        if(sequence[i] == target){
            newArr[newArrSize] = i + 1;
            newArrSize++;
        }
    }
    arrSize = newArrSize;
    return newArr;
}

void doubleArrSize(int*& arr, int& arrSize){
    int* newArr = new int[arrSize * 2]{0};
    for(int i = 0; i < arrSize; i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    arrSize *= 2;
}

