/*
 * author: Lin, Kuan-You
 * date: 2/24/2021
 * 2021 NYU Tandon Bridge Homework 7 Question 1
 *
 * Perfect Numbers & Amicable Pairs !!
 */

#include <iostream>
#include <cmath>

using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num, int& outCountDivs, int& outSumDivs);

int main() {
    int num{0};
    cout << "Please enter a positive integer that is greater than 2: ";
    cin >> num;

    int arrayProperDivisors[num - 1];
    cout << "All the perfect numbers between 2 and " << num << ". (separated by ;)" << endl;
    for (int i = 2; i <= num; i++){
        int countDivs{0}, sumDivs{0};
        bool perfect = isPerfect(i, countDivs, sumDivs);
        if (perfect){
            cout << i << "; ";
        }
        arrayProperDivisors[i - 2] = sumDivs;
    }

    cout << endl;
    cout << "All pairs of amicable numbers that are between 2 and " << num << " (inclusive)." << endl;
    for (int i = 0; i < num - 2; i++){
        for (int n = i + 1; n < num - 1; n++){
            if ((arrayProperDivisors[i] == n + 2) & (arrayProperDivisors[n] == i + 2)){
                cout << "(" << i + 2 << ", " << n + 2 << ")" << endl;
            }
        }
    }

    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){
    int countDivs{0}, sumDivs{0};
    for (int i = 1; i <= pow(num, 0.5); i++){
        if ((num % i) == 0){

            sumDivs += num / i;

            if ((num / i) != i){
                sumDivs += i;
                countDivs += 2;
            } else {
                countDivs += 1;
            }

        }
    }
    sumDivs -= num;
    countDivs--;
    outSumDivs = sumDivs;
    outCountDivs = countDivs;
}

bool isPerfect(int num, int& outCountDivs, int& outSumDivs){
    analyzeDividors(num, outCountDivs, outSumDivs);

    return (outSumDivs == num);
}

