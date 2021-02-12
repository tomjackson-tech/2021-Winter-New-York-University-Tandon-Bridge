/* Date: 2021.1.11
 * Name: Lin, Kuan-You
 * ID: kl4227
 *
 * NYU Bridge Exam 1 q12
 */

#include <iostream>
using namespace std;

int main() {
    //      I am implementing this program using int, assuming the user only enter int.

    //      Also, the total sum of the snail traveled is implementing using long long;
    // potential overflow might occur if the snail travel too far.

    const int FOOT_INCHES_CONVERSION{12};
    const int YARD_FEET_CONVERSION{3};
    const int YARD_INCHES_CONVERSION = FOOT_INCHES_CONVERSION * YARD_FEET_CONVERSION;

    int days{0};
    long long addition{0};
    long long temp{0};

    do {
        days++;
        cout << "Enter the number of inches the snail traveled in day #" << days << ", " << endl;
        cout << "or type -1 if they reached their destination: " << endl;
        cin >> addition;
        temp += addition;
    } while (addition != -1);

    days--;
    temp++;

    long long yards = temp / YARD_INCHES_CONVERSION;
    temp %= YARD_INCHES_CONVERSION;
    long long feet = temp / FOOT_INCHES_CONVERSION;
    long long inches = temp % FOOT_INCHES_CONVERSION;

    cout << "In " << days << " days, the snail traveled " << yards << " yards, " << feet;
    cout << " feet and " << inches << " inches." << endl;

    return 0;
}
