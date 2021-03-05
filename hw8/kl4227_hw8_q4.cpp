/*
 * author: Lin, Kuan-You
 * date: 3/3/2021
 * 2021 NYU Tandon Bridge Homework 8 Question 4
 *
Encrypted pin code
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// set up predefined encrypting sequence length and actual pin
const int SEQUENCE_LEN{10};
const int PIN_LEN{5};
const int ACTUAL_PIN[PIN_LEN] = {1, 2, 3, 4, 5};

int encryptingPin(int map_arr[]);

int main() {
    // some user friendly message
    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN:\t0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "NUM:\t";

    // generate randomized mapping sequence for this execution
    srand(time(nullptr)); // can be better implemented but let's not focus on that
    int arr[SEQUENCE_LEN] = {};
    for (int i = 0; i < SEQUENCE_LEN; i++){
        arr[i] = rand() % 3 + 1;
    }
    for (int i: arr){
        cout << i << " ";
    }
    cout << endl;


    // receive user enter pin
    int user_enter_pin{0};
    cin >> user_enter_pin;

    // determine if the pin match and response
    int encrypted_actual_pin =  encryptingPin(arr);
    if (user_enter_pin == encrypted_actual_pin){
        cout << "Your PIN is correct" << endl;
    } else {
        cout << "Your PIN is not correct" << endl;
    }

    return 0;
}

int encryptingPin(int map_arr[]){
    // This is to encrypt the actual pin using the given randomized mapping sequence
    int base = (int)pow(10, PIN_LEN - 1);
    int encrypted{0};
    for (int i: ACTUAL_PIN){
        encrypted += map_arr[i] * base;
        base /= 10;
    }
    return encrypted;
}
