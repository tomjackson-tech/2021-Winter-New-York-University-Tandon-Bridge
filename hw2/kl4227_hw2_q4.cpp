/*
 * author: Lin, Kuan-You
 * date: 1/22/2021
 * 2021 NYU Tandon Bridge Homework 2 Question 4

Write a program that reads from the user two positive integers, and prints the result of when we add,
 subtract multiply, divide, div and mod them.
Your program should interact with the user exactly as it shows in the following example:

Please enter two positive integers, separated by a space:
14 4
14 + 4 = 18
14 – 4 = 10
14 * 4 = 56
14 / 4 = 3.5
14 div 4 = 3
14 mod 4 = 2
 */

#include <iostream>
using namespace std;

int main() {
    int number_1{0}, number_2{0};

    cout << "Please enter two positive integers, separated by a space:\n";
    cin >> number_1 >> number_2;

    cout << number_1 << " + " << number_2 << " = " << (number_1 + number_2) << endl;
    cout << number_1 << " - " << number_2 << " = " << (number_1 - number_2) << endl;
    cout << number_1 << " * " << number_2 << " = " << (number_1 * number_2) << endl;
    cout << number_1 << " / " << number_2 << " = " << (double) number_1 / (double) number_2 << endl;
    cout << number_1 << " div " << number_2 << " = " << (number_1 / number_2) << endl;
    cout << number_1 << " mod " << number_2 << " = " << (number_1 % number_2);

    return 0;
}
