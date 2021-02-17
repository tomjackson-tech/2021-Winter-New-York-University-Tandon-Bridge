/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 6 Question 3

Implement a function:
void printDivisors(int num)
This function is given a positive integer num, and prints all of num’s divisors in an ascending
order, separated by a space.
For Example, if we call printDivisors(100), the expected output is:
1 2 4 5 10 20 25 50 100

Implementation requirement: Pay attention to the running time of your function. An
efficient implementation would run in Θ(num^(1/2)).

Use the function above when implementing a program that reads from the user a positive
integer (≥2), and prints all it’s divisors.

Your program should interact with the user exactly as it shows in the following example:
Please enter a positive integer >= 2: 100
1 2 4 5 10 20 25 50 100

 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void printDivisors(int num);

int main() {
    cout << "Please enter a positive integer >= ";

    int num{0};
    cin >> num;

    printDivisors(num);

    return 0;
}

void printDivisors(int num){
    string first_section;
    string second_section;

    int upper_limit = pow(num, 0.5);
    for (int i = 1; i <= upper_limit; i++){
        if ((num % i == 0) & (i != (num / i))){
            first_section += to_string(i) + " ";
            second_section = to_string((num / i)) + " " + second_section;
        }
    }

    cout << first_section + second_section << endl;

}
