/*
 * author: Lin, Kuan-You
 * date: 3/3/2021
 * 2021 NYU Tandon Bridge Homework 8 Question 6
 *
Cover digits with X
 */

#include <iostream>
#include <string>

using namespace std;

int determineDigit(char ch);
void outputString(string& output_str, string& output_x, int& counter, int& digit_count);

int main() {
    cout << "Please enter a line of text:" << endl;
    string str;
    getline(cin, str);

    int counter{0};
    int digit_count{0};
    string output_x;
    string output_str;

    for (char i: str){
        if (i == ' '){
            outputString(output_str, output_x, counter, digit_count);
        } else {
            digit_count += determineDigit(i);
            counter += 1;
            output_str += i;
            output_x += 'x';
        }
    }
    outputString(output_str, output_x, counter, digit_count);
    return 0;
}


int determineDigit(char ch){
    int ascii = (int)(unsigned char) ch;
    if ((ascii >= 48) & (ascii <= 57)) {
        return 1;
    } else {
        return 0;
    }
}

void outputString(string& output_str, string& output_x, int& counter, int& digit_count){
    if (digit_count == counter) {
        cout << output_x;
    } else {
        cout << output_str;
    }
    // reset condition
    output_str = ' ';
    output_x = ' ';
    counter = 0;
    digit_count = 0;
}

