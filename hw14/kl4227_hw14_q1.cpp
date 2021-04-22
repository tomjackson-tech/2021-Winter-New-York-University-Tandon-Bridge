#include <iostream>
#include <vector>

using namespace std;

vector<int> findMinMax(vector<int>& array, int start, int end);
int findMin(int& num1, int& num2);
int findMax(int& num1, int& num2);

int main() {
    cout << "Please enter the length of the sequence: ";
    int seqLen;
    cin >> seqLen;

    cout << "Please enter the sequence, separated by space: " << endl;
    vector<int> seq;
    int temp;
    for(int i = 0; i < seqLen; i++){
        cin >> temp;
        seq.push_back(temp);
    }

    vector<int> result;
    result = findMinMax(seq, 0, seq.size()-1);

    cout << endl;
    cout << "The minimum value in the sequence is: " << result[0] << endl;
    cout << "The maximum value in the sequence is: " << result[1] << endl;

    return 0;
}

vector<int> findMinMax(vector<int>& array, int start, int end){
    if ((end-start) <= 1)
        return {findMin(array[start], array[end]), findMax(array[start], array[end])};

    int midPoint = start + (end-start)/2;
    vector<int> firstPair = findMinMax(array, start, midPoint);
    vector<int> secondPair = findMinMax(array, midPoint+1, end);
    int minValue = findMin(firstPair[0], secondPair[0]);
    int maxValue = findMax(firstPair[1], secondPair[1]);
    return {minValue, maxValue};
}

int findMin(int& num1, int& num2){
    if (num1 < num2)
        return num1;
    else
        return num2;
}

int findMax(int& num1, int& num2){
    if (num1 > num2)
        return num1;
    else
        return num2;
}

