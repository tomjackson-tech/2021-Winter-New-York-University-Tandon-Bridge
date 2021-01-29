/*
 * author: Lin, Kuan-You
 * date: 1/28/2021
 * 2021 NYU Tandon Bridge Homework 3 Question 6

Write a program that computes the cost of a long-distance call.
The cost of the call is determined according to the following rate schedule:

    • Any call started between 8:00 A.M. and 6:00 P.M., Monday through Friday,
    is billed at a rate of $0.40 per minute.
    • Any call starting before 8:00 A.M. or after 6:00 P.M., Monday through Friday,
    is charged at a rate of $0.25 per minute.
    • Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.

The input will consist of the day of the week, the time the call started, and the length of the call in minutes.
The output will be the cost of the call.

Notes:
1. The time is to be input in 24-hour notation, so the time 1:30 P.M. is input as 13:30
2. The day of the week will be read as one of the following two character string: Mo Tu
We Th Fr Sa Su
3. The number of minutes will be input as a positive integer.


*/

#include <iostream>
#include <string>

using namespace std;

const double WEEKEND_RATE{0.15};
const double AFTER_HOUR{0.25};
const double WORKING_HOUR{0.40};

int main() {
    cout << "Please enter the time in 24-hour notation; eg. 01:30, 13:30: " << endl;
    int hour{0};
    char temp{'0'};
    int min{0};
    cin >> hour >> temp >> min;

    cout << "Please enter the weekday: " << endl;
    string weekday{"Unspecified"};
    cin >> weekday;

    cout << "Please enter the duration in minutes: " << endl;
    int duration;
    cin >> duration;

    if ((weekday == "Sa") or (weekday == "Su")){
        cout << "The total cost is $" << duration * WEEKEND_RATE;
    } else if ((hour < 8) or (hour > 18)){
        cout << "The total cost is $" << duration * AFTER_HOUR;
    } else {
        cout << "The total cost is $" << duration * WORKING_HOUR;
    }

    return 0;
}
