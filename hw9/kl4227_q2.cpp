/*
 * author: Lin, Kuan-You
 * date: 3/3/2021
 * 2021 NYU Tandon Bridge Homework 9 Question 2
 *
Two strings are anagrams if the letters can be rearranged to form each other.
For example, “Eleven plus two” is an anagram of “Twelve plus one”. Each string contains one ‘v’, three ‘e’s, two ‘l’s,
etc. Write a program that determines if two strings are anagrams.
The program should not be case sensitive and should disregard any punctuation or spaces.

 */


#include <iostream>
#include <string>

using namespace std;

const int upperAInAscii{65};
const int lowerAInAscii{97};
const int numberOfAlphabet{26};

void updateAlphabetCounter(char n, int arr[]);
bool compareTwoAlphabetCounter(int arr1[], int arr2[]);

int main() {
    cout << "Please enter the first string: " << endl;
    string str1;
    getline(cin, str1);

    cout << "Please enter the second string: " << endl;
    string str2;
    getline(cin, str2);

    int alphabetCounter1[numberOfAlphabet] = {};
    for (char n:str1){
        updateAlphabetCounter(n, alphabetCounter1);
    }
    int alphabetCounter2[numberOfAlphabet] = {};
    for (char n:str2){
        updateAlphabetCounter(n, alphabetCounter2);
    }

    bool anagrams = compareTwoAlphabetCounter(alphabetCounter1, alphabetCounter2);
    if (anagrams){
        cout << "The two strings are anagrams.";
    } else {
        cout << "The two strings are not anagrams.";
    }
    return 0;
}

void updateAlphabetCounter(char n, int arr[]){
    int characterInAscii = (int)(unsigned char)n;
    if ((characterInAscii >= lowerAInAscii) and (characterInAscii < lowerAInAscii + 26)){
        int characterNumberInArray = characterInAscii - lowerAInAscii;
        arr[characterNumberInArray]++;
    } else if ((characterInAscii >= upperAInAscii) and (characterInAscii < upperAInAscii + 26)){
        int characterNumberInArray = characterInAscii - upperAInAscii;
        arr[characterNumberInArray]++;
    }
}

bool compareTwoAlphabetCounter(int arr1[], int arr2[]){
    for (int i = 0; i < numberOfAlphabet; i++){
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}