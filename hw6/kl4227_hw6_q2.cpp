/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 6 Question 2

Write a program that, prints a ‘pine tree’ consisting of triangles of increasing sizes, filled
with a character (eg. ‘*’ or ’+’ or ‘$’ etc).

Your program should interact with the user to read the number of triangles in the tree
and the character filling the tree.

Your implementation should include the following functions:

a. void printShiftedTriangle(int n, int m, char symbol)
It prints an n-line triangle, filled with symbol characters, shifted m spaces from the left margin.

b. void printPineTree(int n, char symbol)
It prints a sequence of n triangles of increasing sizes (the smallest triangle is a 2-line triangle),
which form the shape of a pine tree. The triangles are filled with the symbol character.

 */


#include <iostream>
#include <string>

using namespace std;

void printPineTree(int n, char symbol);
void printShiftedTriangle(int n, int m, char symbol);

int main() {
    cout << "Please enter the number of triangles in the tree" << endl;

    int num_tri{0};
    cin >> num_tri;

    char symbol{'a'};
    cout << "Please enter the character filling the tree" << endl;
    cin >> symbol;

    printPineTree(num_tri, symbol);

    return 0;
}

void printPineTree(int n, char symbol){
    for (int i = 0; i < n; i++){
        printShiftedTriangle(i + 2, n - i - 1, symbol);
    }
}

void printShiftedTriangle(int n, int m, char symbol){
    for (int temp = n; temp > 0; temp--) {
        string chart;
        for (int i = 0; i < m; i++) {
            chart += " ";
        }
        for (int blank = 1; blank <= temp; blank++) {
            chart += " ";
        }
        for (int draw = 1; draw < (n - temp + 1) * 2; draw++) {
            chart += symbol;
        }
        for (int blank = 1; blank < temp; blank++) {
            chart += " ";
        }
        cout << chart << endl;
    }
}