/*
 * author: Lin, Kuan-You
 * date: 1/22/2021
 * 2021 NYU Tandon Bridge Homework 2 Question 2

Write a program that asks the user to enter an amount of money in the format of dollars and
remaining cents. The program should calculate and print the minimum number of coins
(quarters, dimes, nickels and pennies) that are equivalent to the given amount.

Hint: In order to find the minimum number of coins, first find the maximum number of
quarters that fit in the given amount of money, then find the maximum number of dimes
that fit in the remaining amount, and so on.

Your program should interact with the user exactly as it shows in the following example:
Please enter your amount in the format of dollars and cents separated by a space:
4 37
4 dollars and 37 cents are:
17 quarters, 1 dimes, 0 nickels and 2 pennies
 */

#include <iostream>
using namespace std;

int main() {
    const int CENT_OF_QTR{25};
    const int CENT_OF_DIME{10};
    const int CENT_OF_NICK{5};
    const int CENT_OF_DOLLAR{100};

    int dollars{0}, cents{0};
    cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollars >> cents;

    int total_cents = dollars * CENT_OF_DOLLAR + cents;
    int quarters = total_cents / CENT_OF_QTR;
    int dimes = (total_cents % CENT_OF_QTR) / CENT_OF_DIME;
    int nickles = ((total_cents % CENT_OF_QTR) % CENT_OF_DIME) / CENT_OF_NICK;
    int pennies = ((total_cents % CENT_OF_QTR) % CENT_OF_DIME) % CENT_OF_NICK;

    cout << dollars << " dollars and " << cents << " cents are:" << endl;
    cout << quarters << " quarters, " << dimes << " dimes, " << nickles << " nickles and " << pennies << " pennies";

    return 0;
}
