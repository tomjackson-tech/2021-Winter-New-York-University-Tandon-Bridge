/*
 * author: Lin, Kuan-You
 * date: 3/3/2021
 * 2021 NYU Tandon Bridge Homework 8 Question 5
 *
User last name, first name, middle name.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Please enter your name in the order of first name; middle name; last name" << endl;
    string first;
    string middle;
    string last;

    cin >> first;
    cin >> middle;
    cin >> last;

    cout << last << ", " << first << " " << middle[0] << ".";

    return 0;
}
