/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 6 Question 1

1. Write a function int fib(int n) that returns the n-th element of the Fibonacci
sequence.

2. Write a program that prompts the user to enter a positive integer num, and then
prints the num’s elements in the Fibonacci sequence.

Your program should interact with the user exactly as it shows in the following example:
Please enter a positive integer: 7
13
 */



#include <iostream>
using namespace std;

long long fib(int n);

int main() {

    cout << "Please enter a positive integer: ";
    int index{0};
    cin >> index;

    cout << fib(index) << endl;
    return 0;
}

long long fib(int n){
    long long t{1};
    long long t_1{1};

    for (int i = 2; i < n; i++){
        long long temp = t;
        t = t + t_1;
        t_1 = temp;
    }

    return t;
}