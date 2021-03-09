/*
 * author: Lin, Kuan-You
 * date: 3/3/2021
 * 2021 NYU Tandon Bridge Homework 9 Question 1
 *
Write a program that will read in a line of text and output the number of words in the line and
the number of occurrences of each letter.
Define a word to be any string of letters that is delimited at each end by either whitespace, a
period, a comma, or the beginning or end of the line.
You can assume that the input consists entirely of letters, whitespace, commas, and periods.
When outputting the number of letters that occur in a line, be sure to count upper and
lowercase versions of a letter as the same letter.
Output the letters in alphabetical order and list only those letters that do occur in the input line.

Your program should interact with the user exactly as it shows in the following example:
Please enter a line of text:
I say Hi.
3 words
1 a
1 h
2 i
1 s
1 y
 */

#include <iostream>
#include <string>

using namespace std;

const int upperAInAscii{65};
const int lowerAInAscii{97};
const int numberOfAlphabet{26};

void countWordNumber(char n, int& wordNumber);
void updateAlphabetCounter(char n, int arr[]);

int main() {
    cout << "Please enter a line of text: " << endl;
    string str;
    getline(cin, str);

    int alphabetCounter[numberOfAlphabet] = {};
    int wordNumber{0};

    for (char n:str){
        countWordNumber(n, wordNumber);
        updateAlphabetCounter(n, alphabetCounter);
    }
    cout << wordNumber << " words" << endl;
    for (int i = 0; i < numberOfAlphabet; i++){
        if (alphabetCounter[i] != 0){
            cout << alphabetCounter[i] << " " << (char)(i + lowerAInAscii) << endl;
        }
    }
    return 0;
}

void countWordNumber(char n, int& wordNumber){
    // This will work only under the condition that each word is either separated by
    // a commas, a period, or a whitespace. For example: Hello, My name is Jack. is an illegal input.
    // Instead, the user should enter Hello.My name is Jack. or Hello,my name is Jack.
        switch(n){
            case ' ':
                wordNumber++;
                break;
            case '.':
                wordNumber++;
                break;
            case ',':
                wordNumber++;
                break;
            default:
                break;
        }
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


