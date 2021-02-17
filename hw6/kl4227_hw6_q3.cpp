/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 6 Question 3

The number e is an important mathematical constant that is the base of the natural logarithm.
e also arises in the study of compound interest, and in many other applications.

The value of e is approximately equal to 2.71828. We can get an approximate value of e,
by calculating only a partial sum of the infinite sum above (the more addends we add, the better approximation we get).

Implement the function:

double eApprox(int n)

This function is given a positive integer n, and returns an approximation of e,
calculated by the sum of the first (n+1) addends of the infinite sum above.

To test your function use the following main:

 */

#include <iostream>
using namespace std;

double eApprox(int n);

int main() {

    cout.precision(30);
    for (int n = 1; n <= 15; n++){
        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }

    return 0;
}

double eApprox(int n){
    double accumulate{1};
    double addends{1};

    for (int i = 1; i <= n; i++){
        addends /= i;
        accumulate += addends;
    }
    return accumulate;
}

