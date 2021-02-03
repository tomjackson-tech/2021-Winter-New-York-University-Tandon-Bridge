/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 4 Question 1

Write two versions of a program that reads a positive integer n, and prints the first n even numbers.
a) In the first, use a while loop.
b) In the second, use a for loop.

Each section should interact with the user exactly as it shows in the following example:

Please enter a positive integer: 3
2
4
6

*/

#include <iostream>
using namespace std;

int main() {


    // using the while loop
    cout << "section a" << endl;
    cout << "Please enter a positive integer: ";
    int time{0};
    cin >> time;

    int even_numbers{2};
    while (time > 0){
        cout << even_numbers << endl;
        even_numbers += 2;
        time--;
    }

    // using the for loop
    cout << "section b" << endl;
    cout << "Please enter a positive integer: ";
    int time_2{0};
    cin >> time_2;

    int even_numbers_2{2};
    for (int temp = 0; temp < time_2; temp++){
        cout << even_numbers_2 << endl;
        even_numbers_2 += 2;
    }

    return 0;
}