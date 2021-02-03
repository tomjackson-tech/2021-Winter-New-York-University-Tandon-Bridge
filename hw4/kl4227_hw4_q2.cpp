/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 4 Question 2

In this question we will use a simplified version of the Roman Numerals System to represent positive integers.

The digits in this system are I, V, X, L, C, D and M. Each digit corresponds to a decimal value,
as showed in the following table:

Roman digit:Decimal value;
I:1;
V:5;
10:X;
50:L;
100:C;
500:D;
1000:M;

A number in the simplified Roman numerals system is a sequence of Roman digits, which follow
these 2 rules:
1. The digits form a monotonically non-increasing sequence. That is the value of each digit is
less than or equal to the value of the digit that came before it.
For example, DLXXVI is a monotonically non-increasing sequence of Roman digits, but XIV is not.

2. There is no limit on the number of times that ‘M’ can appear in the number.
‘D’, ‘L’ and ‘V’ can each appear at most one time in the number.
‘C’, ‘X’ and ‘I’ can each appear at most four times in the number.
For example: IIII, XVII and MMMMMMDCCLXXXXVII are legal numbers in our simplified Roman
numeral system, but IIIII, XIV, VVI and CCXLIII are not.

Write a program that reads from the user a (decimal) number, and prints it’s representation in
the simplified Roman numerals system.

Your program should interact with the user exactly as it shows in the following example: Enter decimal number:

Enter decimal number:
147
147 is CXXXXVII

*/

#include <iostream>
#include <string>

using namespace std;

const int M{1000};
const int D{500};
const int C{100};
const int L{50};
const int X{10};
const int V{5};

int main() {

    cout << "Enter decimal number:" << endl;
    int original_num{0};
    cin >> original_num;
    int num = original_num;

    int m_number = num / M;
    num -= m_number * M;

    int d_number = num / D;
    num -= d_number * D;

    int c_number = num / C;
    num -= c_number * C;

    int l_number = num / L;
    num -= l_number * L;

    int x_number = num / X;
    num -= x_number * X;

    int v_number = num / V;

    int i_number = num - v_number * V;

    string roman_num;
    while (m_number != 0){
        roman_num += "M";
        m_number--;
    }
    while (d_number != 0){
        roman_num += "D";
        d_number--;
    }
    while (c_number != 0){
        roman_num += "C";
        c_number--;
    }
    while (l_number != 0){
        roman_num += "L";
        l_number--;
    }
    while (x_number != 0){
        roman_num += "X";
        x_number--;
    }
    while (v_number != 0){
        roman_num += "V";
        v_number--;
    }
    while (i_number != 0){
        roman_num += "I";
        i_number--;
    }

    cout << original_num << " is " << roman_num << endl;

    return 0;

}
