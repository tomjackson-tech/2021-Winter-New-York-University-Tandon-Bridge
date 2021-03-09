/*
 * author: Lin, Kuan-You
 * date: 2/24/2021
 * 2021 NYU Tandon Bridge Homework 7 Question 1
 *
 * Year Calendar !!
 */

#include <iostream>

using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
int checkLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main() {
    int year{0}, start{0};
    cout << "Please enter the year: ";
    cin >> year;

    cout << "Please enter the weekday of the first day in the year: ";
    cin >> start;

    printYearCalender(year, start);

    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    /*      This function is to print the calendar of the month and return the last
     * weekday of the month.
     *
     * paras::
     * numOfDays, int, the number of the days in the month
     * startingDay, int, the weekday of the first day in the month
     *
     * return::
     * lastWeekDay, int, the weekday of the last day in the month
     */

    // print the calendar
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;
    for (int i = 1; i < startingDay; i++) {
        cout << "\t";
    }
    for (int i = 1; i <= numOfDays; i++) {
        cout << i;
        int weekDay = ((i + startingDay - 1) % 7);
        if ((weekDay == 0) and (i != numOfDays))  {
            cout << endl;
        } else {
            cout << "\t";
        }
    }
    cout << endl;

    // calculate last week day of the month
    int lastWeekDay = ((numOfDays + startingDay - 2) % 7) + 1;

    return lastWeekDay;
}

int checkLeapYear(int year){
    /* This function is to determine whether the year is a leap year.
     *
     * return::
     * leapYear, bool, True if the year is a leap year, False otherwise
     */

    bool leapYear = (((year % 4) == 0) and (((year % 100) != 0) or ((year % 400) != 0)));

    return leapYear;
}


void printYearCalender(int year, int startingDay){
    /* This function will print the calendar of the year.
     */
    bool leapYear = checkLeapYear(year);

    cout << endl;
    for (int i = 1; i <= 12; i++){
        // print month
        switch (i){
            case 1:
                cout << "January";
                break;
            case 2:
                cout << "February";
                break;
            case 3:
                cout << "March";
                break;
            case 4:
                cout << "April";
                break;
            case 5:
                cout << "May";
                break;
            case 6:
                cout << "June";
                break;
            case 7:
                cout << "July";
                break;
            case 8:
                cout << "August";
                break;
            case 9:
                cout << "September";
                break;
            case 10:
                cout << "October";
                break;
            case 11:
                cout << "November";
                break;
            default:
                cout << "December";
                break;
        }

        // print year
        cout << " " << year << endl;

        // determine the rule for month calendar
        int monthID{0};
        if (i == 2){
            if (leapYear) {
                monthID = 2;
            } else {
                monthID = 3;
            }
        } else {
            if (i <= 7) {
                monthID = ((i+1) % 2);
            } else {
                monthID = (i % 2);
            }
        }

        // print month calendar
        switch (monthID){
            case 0:
                startingDay = (printMonthCalender(31, startingDay) % 7) + 1;
                break;
            case 1:
                startingDay = (printMonthCalender(30, startingDay) % 7) + 1;
                break;
            case 2:
                startingDay = (printMonthCalender(29, startingDay) % 7) + 1;
                break;
            case 3:
                startingDay = (printMonthCalender(28, startingDay) % 7) + 1;
                break;
        }
        cout << endl;
    }
}

