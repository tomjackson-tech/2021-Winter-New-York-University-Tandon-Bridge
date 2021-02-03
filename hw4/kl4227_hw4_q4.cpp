/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 4 Question 4

Write two versions of a program that reads a sequence of positive integers from the user,
calculates their geometric, and prints the geometric mean.

Your two versions should read the integer sequence in two ways:
a) First read the length of the sequence.
For example, an execution would look like:
Please enter the length of the sequence: 3
Please enter your sequence:
1
2
3
The geometric mean is: 1.8171


b) Keep reading the numbers until -1 is entered.
For example, an execution would look like:
Please enter a non-empty sequence of positive integers, each one in a separate line. End your
sequence by typing -1:
1
2
3
-1
The geometric mean is: 1.8171

*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed;
    cout << setprecision(4);
    // section a
    cout << "section a" << endl;
    cout << "Please enter the length of the sequence: ";
    int len{0};
    cin >> len;

    double container{1.0};
    cout << "Please enter your sequence: " << endl;
    for (int temp = 0; temp < len; temp++){
        int num{0};
        cin >> num;
        container *= num;
    }
    container = pow(container, 1.0/len);
    cout << "The geometric mean is: " << container << endl;

    // section b
    cout << "section b" << endl;
    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1: "<< endl;
    double container_2{1.0};
    double counter{0.0};
    while (true){
        int num{0};
        cin >> num;
        if (num == -1){
            break;
        } else{
            container_2 *= num;
            counter++;
        }
    }
    container_2 = pow(container_2, 1.0/counter);
    cout << "The geometric mean is: " << container_2 << endl;

    return 0;
}
