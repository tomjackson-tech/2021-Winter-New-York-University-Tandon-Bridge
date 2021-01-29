/*
 * author: Lin, Kuan-You
 * date: 1/22/2021
 * 2021 NYU Tandon Bridge Homework 2 Question 3

Suppose John and Bill worked for some time and we want to calculate the total time both of
them worked. Write a program that reads number of days, hours, minutes each of them
worked, and prints the total time both of them worked together as days, hours, minutes.

Hint: Try to adapt the elementary method for addition of numbers to this use.

Your program should interact with the user exactly as it shows in the following example:
Please enter the number of days John has worked: 2
Please enter the number of hours John has worked: 12
Please enter the number of minutes John has worked: 15

Please enter the number of days Bill has worked: 3
Please enter the number of hours Bill has worked: 15
Please enter the number of minutes Bill has worked: 20
The total time both of them worked together is: 6 days, 3 hours and 35 minutes.
 */

#include <iostream>
using namespace std;

int main() {
    const int MIN_OF_HOUR{60};
    const int HOUR_OF_DAY{24};

    int john_d{0}, john_h{0}, john_m{0};
    cout << "Please enter the number of days John has worked: ";
    cin >> john_d;
    cout << "Please enter the number of hours John has worked: ";
    cin >> john_h;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> john_m;

    int bill_d{0}, bill_h{0}, bill_m{0};
    cout << endl << "Please enter the number of days Bill has worked: ";
    cin >> bill_d;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> bill_h;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> bill_m;

    int total_m = (john_m + bill_m) % MIN_OF_HOUR;
    int total_h = ((john_h + bill_h) + ((john_m + bill_m) / MIN_OF_HOUR)) % HOUR_OF_DAY;
    int total_d = (john_d + bill_d) + (((john_h + bill_h) + ((john_m + bill_m) / MIN_OF_HOUR)) / HOUR_OF_DAY);
    cout << "The total time both of them worked together is: " << total_d << " days, " 
        << total_h << " hours and " << total_m << " minutes.";

    return 0;
}
