/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 4 Question 6

Write a program that asks the user to input a positive integer n, and print all of the numbers from 1 to n that have more even digits than odd digits.

 For example, if n=30, the program should print:
2
4
6
8
20
22
24
26
28

*/

#include <iostream>

using namespace std;

int main() {
    cout << "Please input a positive integer" << endl;
    int n{0};
    cin >> n;
    for (int i = 0; i <= n; i++){
        int num{i};
        int even_vote{0};
        int odd_vote{0};
        while (num > 0){
            int curr_digit = num % 10;
            if (curr_digit % 2 == 0){
                even_vote++;
            } else {
                odd_vote++;
            }
            num /= 10;
        }
        if (even_vote > odd_vote){
            cout << i << endl;
        }

    }

    return 0;
}
