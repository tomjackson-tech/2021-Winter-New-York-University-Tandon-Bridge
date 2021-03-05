/*
 * author: Lin, Kuan-You
 * date: 3/3/2021
 * 2021 NYU Tandon Bridge Homework 8 Question 2
 *
A palindrome is a word, which reads the same backward or forward. For example, noon, civic,
radar, level, rotor, kayak, reviver, racecar, redder, madam, and refer are all palindromes.

Your program should interact with the user exactly as it shows in the following example:
Please enter a word: level
level is a palindrome
 */

#include <iostream>
#include <string>

using namespace std;

string reverseStr(string str);
bool isPalindrome(string str);

int main() {
    cout << "Please enter a word: ";
    string str;
    cin >> str;

    bool palindrome = isPalindrome(str);
    if (palindrome){
        cout << str << " is a palindrome";
    } else {
        cout << str << " is not a palindrome";
    }
    return 0;
}

bool isPalindrome(string str){
    return str == reverseStr(str);
}

string reverseStr(string str){
    string new_string;
    for(unsigned long i = str.length() - 1; i > 0; i--){
        new_string += str[i];
    }
    new_string += str[0];
    return new_string;
}