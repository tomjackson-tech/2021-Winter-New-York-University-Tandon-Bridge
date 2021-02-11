/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 5 Question 1

Write a program that reads a positive integer n from the user and prints out a nxn
multiplication table. The columns should be spaced by a tab.

Your program should interact with the user exactly as it shows in the following example:
Please enter a positive integer:

10
1 2 3 4 5 6 7 8 9 10
2 4 6 8 10 12 14 16 18 20
3 6 9 12 15 18 21 24 27 30
4 8 12 16 20 24 28 32 36 40
5 10 15 20 25 30 35 40 45 50
6 12 18 24 30 36 42 48 54 60
7 14 21 28 35 42 49 56 63 70
8 16 24 32 40 48 56 64 72 80
9 18 27 36 45 54 63 72 81 90
10 20 30 40 50 60 70 80 90 100

*/

#include <iostream>
using namespace std;

void multiplication_row(int num);

int main() {
    cout << "Please enter a positive integer:" << endl;
    int num{0};
    cin >> num;
    for (int t = 1; t <= num; t++){
        multiplication_row(t);
    }
    return 0;
}

void multiplication_row(int num){
    for (int i = 1; i <= 10; i++){
        if (i == 10){
            cout << i * num << endl;
        } else {
            cout << i * num << '\t';
        }
    }
}