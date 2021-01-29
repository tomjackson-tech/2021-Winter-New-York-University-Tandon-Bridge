/*
 * author: Lin, Kuan-You
 * date: 1/28/2021
 * 2021 NYU Tandon Bridge Homework 3 Question 4

Define the following constants:

    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

Write a program that asks the user to enter a Real number,
then it asks the user to enter the method by which they want to round that number
(floor, ceiling or to the nearest integer). The program will then print the rounded result.

Your program should interact with the user exactly as it shows in the following example:
Please enter a Real number:
4.78
Choose your rounding method:
1. Floor round
2. Ceiling round
3. Round to the nearest whole number
2
5

Implementation requirements:
1. Use a switch statement.
2. You are not allowed to include and use the math library.


 */

#include <iostream>

using namespace std;

const int FLOOR_ROUND{1};
const int CEILING_ROUND{2};
const int ROUND{3};

int main() {
    cout << "Please enter a Real number: " << endl;
    double num{0};
    cin >> num;

    cout << "Choose your rounding method: " << endl;
    cout << "1. Floor round" << endl;
    cout << "2. Ceiling round" << endl;
    cout << "3. Round to the nearest whole number" << endl;
    int method{0};
    cin >> method;

    switch(method) {
        case FLOOR_ROUND:
            if (num >= 0){
                cout << (int) num;
            } else if (num - (int) num < 0){
                cout << (int) num - 1;
            } else {
                cout << (int) num;
            }
            break;

        case CEILING_ROUND:
            if (num <= 0){
                cout << (int) num;
            } else if (num - (int) num > 0){
                cout << (int) num + 1;
            } else {
                cout << (int) num;
            }
            break;

        case ROUND:
            if (num - (int) num >= 0.5) {
                cout << (int) num + 1;
            } else if (num - (int) num <= -0.5){
                cout << (int) num - 1;
            } else {
                cout << (int) num;
            }
            break;

        default:
            break;
    }

    return 0;
}
