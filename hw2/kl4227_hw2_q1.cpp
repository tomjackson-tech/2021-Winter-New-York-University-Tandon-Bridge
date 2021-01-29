/*
 * author: Lin, Kuan-You
 * date: 1/22/2021
 * 2021 NYU Tandon Bridge Homework 2 Question 1

Write a program that asks the user to enter a number of quarters, dimes, nickels and
pennies and then outputs the monetary value of the coins in the format of dollars and
remaining cents.

Your program should interact with the user exactly as it shows in the following example:
Please enter number of coins:
# of quarters: 13
# of dimes: 4
# of nickels: 11
# of pennies: 17
The total is 4 dollars and 37 cents
 */

#include <iostream>
using namespace std;

int main() {
    const int CENT_OF_QTR{25};
    const int CENT_OF_DIME{10};
    const int CENT_OF_NICK{5};
    const int CENT_OF_DOLLAR{100};
    
    cout << "Please enter number of coins:" << endl;
//    25 cents
    int quarters{0};
    cout << "# of quarters: ";
    cin >> quarters;
    
//    10 cents
    int dimes{0};
    cout << "# of dimes: ";
    cin >> dimes;
    
//    5 cents
    int nickles{0};
    cout << "# of nickles: ";
    cin >> nickles;
    
//    1 cents
    int pennies{0};
    cout << "# of pennies: ";
    cin >> pennies;
    
    int dollars = (quarters * CENT_OF_QTR + dimes * CENT_OF_DIME + nickles * CENT_OF_NICK + pennies) / CENT_OF_DOLLAR;
    int cents = (quarters * CENT_OF_QTR + dimes * CENT_OF_DIME + nickles * CENT_OF_NICK + pennies) % CENT_OF_DOLLAR;

    cout << "The total is " << dollars << " dollars and " << cents << " cents";

    return 0;
}
