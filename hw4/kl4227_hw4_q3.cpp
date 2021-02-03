/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 4 Question 3

Write a program that reads from the user a positive integer (in a decimal representation),
and prints its binary (base 2) representation.

 Your program should interact with the user exactly as it shows in the following example:
Enter decimal number:
76
The binary representation of 76 is 1001100

*/

#include <iostream>
using namespace std;

int main() {
    cout << "Enter decimal number: " << endl;
    int decimal{0};
    cin >> decimal;

    // Because we're storing the binary number in an unsigned long long type,
    // it is possible that an overflow would occur if the user enter a super large
    // decimal integer.
    unsigned long long binary{0};
    unsigned long long base{1};

    // using the method similar to the synthetic division
    while (decimal > 0){
        unsigned long long temp = decimal % 2;
        temp *= base;
        binary += temp;
        base *= 10;
        decimal /= 2;
    }
    binary %= base;

    cout << binary;
    return 0;
}
