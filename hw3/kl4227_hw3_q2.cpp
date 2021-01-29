/*
 * author: Lin, Kuan-You
 * date: 1/28/2021
 * 2021 NYU Tandon Bridge Homework 3 Question 2

Write a program that:
• Asks the user for their name.
• Asks the user to input their graduation year.
• Asks the user to input the current year.

Assume the student is in a four-year undergraduate program. Display the current status the student is in.
Possible status include: not in college yet, freshman, sophomore, junior, senior, graduated.

Note: If graduation year equals to current year, status is ‘Graduated’;
if graduation year is four years after current year, status is ‘Freshman’, etc.

Your program should interact with the user exactly as it shows in the following example:

Please enter your name: Jessica
Please enter your graduation year: 2019
Please enter current year: 2015
Jessica, you are a Freshman
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string name{"Noting"};
    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your graduation year: ";
    int graduation_year{0};
    cin >> graduation_year;

    cout << "Please enter current year: ";
    int current_year{0};
    cin >> current_year;

    int diff = graduation_year - current_year;
    if (diff == 1){
        cout << name + ", you are a Senior" << endl;
    } else if (diff == 2){
        cout << name + ", you are a Junior" << endl;
    } else if (diff == 3){
        cout << name + ", you are a Sophomore" << endl;
    } else if (diff == 4){
        cout << name + ", you are a Freshman" << endl;
    } else if (diff > 4){
        cout << name + ", you are Not in college yet" << endl;
    } else {
        cout << name + ", you are Graduated" << endl;
    }

    return 0;
}
