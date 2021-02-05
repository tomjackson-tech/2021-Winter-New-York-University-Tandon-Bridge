/*
 * author: Lin, Kuan-You
 * date: 1/28/2021
 * 2021 NYU Tandon Bridge Homework 3 Question 3

Write a program that does the following:
• Ask user to input three Real numbers a, b and c. They represent the parameters of a
quadratic equation 𝑎𝑥^2 + 𝑏𝑥 + 𝑐 = 0
• Classify to one of the following:
- ’Infinite number of solutions’ (for example, 0𝑥^2 + 0𝑥 + 0 = 0 has infinite number of solutions)
- ’No solution’ (for example, 0𝑥^2 + 0𝑥 + 4 = 0 has no solution)
- ’No real solution’ (for example, 𝑥^2 + 4 = 0 has no real solutions)
- ’One real solution’
- ’Two real solutions’
• In cases there are 1 or 2 real solutions, also print the solutions.

Your program should interact with the user exactly as it shows in the following example:
Please enter value of a: 1
Please enter value of b: 4
Please enter value of c: 4
This equation has a single real solution x=-2.0

 */

#include <iostream>
#include <cmath>

using namespace std;

const double DISCRIMINANT_NUMERATOR{4};
const double DISCRIMINANT_DENOMINATOR{2};

int main() {
    cout << "Please enter value of a: ";
    double a{0};
    cin >> a;

    cout << "Please enter value of b: ";
    double b{0};
    cin >> b;

    cout << "Please enter value of c: ";
    double c{0};
    cin >> c;

//    discriminant
    if ((a == 0) and (b == 0) and (c != 0)){
        cout << "This equation has no solution";
    } else if ((a == 0) and (b == 0) and (c == 0)){
        cout << "This equation has infinite solutions";
    } else {
        double temp = pow(b, 2) - DISCRIMINANT_NUMERATOR * (a * c);
        if (temp < 0) {
            cout << "This equation has no real solution";
        } else if (temp == 0) {
            cout << "This equation has a single real solution x=" << -b / (DISCRIMINANT_DENOMINATOR * a);
        } else {
            double solution_1 = (-b + sqrt(temp)) / (DISCRIMINANT_DENOMINATOR * a);
            double solution_2 = (-b - sqrt(temp)) / (DISCRIMINANT_DENOMINATOR * a);
            cout << "This equation has two real solutions x=" << solution_1 << " & " << solution_2;
        }
    }

    return 0;
}
