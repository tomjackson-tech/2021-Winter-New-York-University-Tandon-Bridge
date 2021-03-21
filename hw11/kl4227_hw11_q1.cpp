/*
 * author: Lin, Kuan-You
 * date: 3/19/2021
 * 2021 NYU Tandon Bridge Homework 11 Question 1

Recursive problem. Please refer to the document.

 */

#include <iostream>

using namespace std;

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main() {
    for (int i = 1; i < 6; i++){
        cout << "INPUT: n =  " << i << endl;
        cout << "Function: printTriangle" << endl;
        printTriangle(i);
        cout << "Function: printOppositeTriangles" << endl;
        printOppositeTriangles(i);
        cout << "Function: printRuler" << endl;
        printRuler(i);
        cout << endl;
    }
    return 0;
}


void printTriangle(int n){
    if (n == 1){
        cout << '*' << endl;
    } else {
        printTriangle(n - 1);
        for (int i = 0; i < n; i++){
            cout << '*';
        }
        cout << endl;
    }
}

void printOppositeTriangles(int n){
    if (n != 0) {
        for (int i = 0; i < n; i++){
            cout << '*';
        }
        cout << endl;
        printOppositeTriangles(n - 1);
        for (int i = 0; i < n; i++){
            cout << '*';
        }
        cout << endl;
    }
}

void printRuler(int n){
    if (n != 0){
        printRuler(n - 1);
        for (int i = 0; i < n; i++){
            cout << '-';
        }
        cout << endl;
        printRuler(n - 1);
    }
}