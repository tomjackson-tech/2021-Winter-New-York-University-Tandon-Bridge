/*
 * author: Lin, Kuan-You
 * date: 1/28/2021
 * 2021 NYU Tandon Bridge Homework 3 Question 1

Write a program that computes how much a customer has to pay after purchasing two items. The price is calculated according to the following rules:
• Buy one get one half off promotion: the lower price item is half price.
• If the customer is club card member, additional 10% off.
• Tax is added.

Inputs to the program include:
• Two items’ prices
• Have club card or not (User enters ‘Y’ or ‘y’ for “yes”; ‘N’ or ‘n’ for “no”)
• Tax rate (User enters the percentage as a number; for example they enter 8.25 if the tax
rate is 8.25%)

Program displays:
• Base price - the price before the discounts and taxes
• Price after discounts - the price after the buy one get one half off promotion and the
member’s discount, if applicable
• Total price – the amount of money the customer has to pay (after tax).

Your program should interact with the user exactly as it shows in the following example:
Enter price of first item: 10
Enter price of second item: 20
Does customer have a club card? (Y/N): y
Enter tax rate, e.g. 5.5 for 5.5% tax: 8.25
Base price: 30.0
Price after discounts: 22.5
Total price: 24.35625
 */



#include <iostream>
#include <iomanip>

using namespace std;

const double HALF_DISCOUNT{0.5};
const double MEMBERSHIP_DISCOUNT{0.9};
const double PERCENTAGE{100};

int main() {

    // input parameters
    cout << "Enter price of first item: ";
    double price_1{0};
    cin >> price_1;
    cout << "Enter price of second item: ";
    double price_2{0};
    cin >> price_2;
    cout << "Does customer have a club card? (Y/N): ";
    char discount{'G'};
    cin >> discount;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    double tax_rate{0};
    cin >> tax_rate;

    // output results
    cout << fixed;
    cout << setprecision(2);
    cout << "Base price: " << price_1 + price_2 << endl;

    // execute promotion discount
    if (price_1 > price_2){
        price_2 = price_2 * HALF_DISCOUNT;
    } else {
        price_1 = price_1 * HALF_DISCOUNT;
    }
    double after_discount_total = (price_1 + price_2);

    // execute member discount
    if ((discount == 'Y') or (discount == 'y')) {
        after_discount_total = after_discount_total * MEMBERSHIP_DISCOUNT;
    }
    cout << "Price after discounts: " << after_discount_total << endl;

    // add tax cost
    cout << "Total price: " << after_discount_total * (PERCENTAGE + tax_rate) / PERCENTAGE << endl;

    return 0;
}
