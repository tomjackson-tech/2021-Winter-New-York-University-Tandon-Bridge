/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 4 Question 5

Write a program that asks the user to input a positive integer n, and prints a textual image of an
hourglass made of 2n lines with asterisks.

For example if n=4, the program should print:

*******
 *****
  ***
   *
   *
  ***
 *****
*******


*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Please enter a positive integer: " << endl;
    int n{0};
    cin >> n;


    for (int temp = 0; temp < n * 2; temp++){
        string chart;
        if (temp < n){
            for (int blank = 1; blank <= temp; blank++){
                chart += " ";
            }
            for (int draw = 1; draw < (n - temp) * 2; draw++){
                chart += "*";
            }
            for (int blank = 1; blank < temp; blank++){
                chart += " ";
            }
        } else {
            for (int blank = 1; blank <= n * 2 - temp - 1; blank++){
                chart += " ";
            }
            for (int draw = 1; draw <= 2 * (temp - n ) + 1; draw++){
                chart += "*";
            }
            for (int blank = 1; blank <= n * 2 - temp - 1; blank++){
                chart += " ";
            }
        }
        cout << chart << endl;
    }

    return 0;
}
