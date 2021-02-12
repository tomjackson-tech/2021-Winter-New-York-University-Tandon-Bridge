/* Date: 2021.1.11
 * Name: Lin, Kuan-You
 * ID: kl4227
 *
 * NYU Bridge Exam 1 q11
 */

#include <iostream>
using namespace std;

int main() {
    const int LOWERCASE_CODE = 96;
    const int UPPER_CODE = 64;

    cout << "Please enter a lower-case letter:" << endl;
    char in_letter{'a'};
    cin >> in_letter;

    int to_num = (int)(unsigned char)in_letter;
    int length = to_num - LOWERCASE_CODE;
    int bottom = (length * 2) - 1;

    for (int i = 1; i <= length; i++){
        int letter_print = (i * 2) - 1;
        int white_space = (bottom - letter_print) / 2;
        for (int n = 0; n < white_space; n++){
            cout << " ";
        }
        for (int n = 1; n <= letter_print; n++){
            if (i % 2 == 0){
                cout << (char)(i + UPPER_CODE);
            } else {
                cout << (char)(i + LOWERCASE_CODE);
            }
        }
        for (int n = 0; n < white_space; n++){
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
