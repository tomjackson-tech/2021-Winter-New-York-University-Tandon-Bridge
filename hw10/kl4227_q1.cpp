/*
 * author: Lin, Kuan-You
 * date: 3/13/2021
 * 2021 NYU Tandon Bridge Homework 10 Question 1
 *
Implement the function:
string* createWordsArray(string sentence, int& outWordsArrSize)

This function gets a string sentence containing a sentence.
When called, it should create and return a new array (of strings), that contains all the words in sentence.
The function should also update the output parameter, outWordsArrSize,
with the logical size of the new array that was created.

 */

#include <iostream>
#include <string>

using namespace std;

void printArray(const string* arr, int wordsArrSize);
string* createWordsArray(const string& sentence, int& outWordsArrSize);

int main() {
    string test1 = "You can do it";
    string test2 = "We think in generalities but we live in details";
    string test3 = "1 plus 1 equals 2";
    cout << "Testing Strings are: " << endl;
    cout << test1 << endl << test2 << endl << test3 << endl << endl;

    int wordsArrSize1{0};
    int wordsArrSize2{0};
    int wordsArrSize3{0};
    string* arr1 = createWordsArray(test1, wordsArrSize1);
    string* arr2 = createWordsArray(test2, wordsArrSize2);
    string* arr3 = createWordsArray(test3, wordsArrSize3);

    cout << "The results are: " << endl;
    printArray(arr1, wordsArrSize1);
    printArray(arr2, wordsArrSize2);
    printArray(arr3, wordsArrSize3);

    return 0;
}

void printArray(const string* arr, int wordsArrSize){
    for(int i = 0; i < wordsArrSize; i++){
        cout << "[\"" << arr[i] << "\"]";
        if (i != wordsArrSize - 1){
            cout << ", ";
        }
    }
    cout << endl;
}

string* createWordsArray(const string& sentence, int& outWordsArrSize){
    auto* wordsArr = new string[sentence.size()];
    int wordsArrSize{0};
    int iterator{0};

    for(int i = 0; i < sentence.size(); i++){
        if (sentence[i] == ' '){
            wordsArr[wordsArrSize] = sentence.substr(iterator, i - iterator) ;
            wordsArrSize++;
            iterator = i + 1;
        }
    }
    wordsArr[wordsArrSize] = sentence.substr(iterator);
    wordsArrSize++;
    outWordsArrSize = wordsArrSize;

    return wordsArr;
}