/*
 * author: Lin, Kuan-You
 * date: 5/7/2021
 * 2021 NYU Tandon Bridge Homework 16 Question 1

Pascal Programming Balance Check, Please refer to the documentation.
*/

#include <iostream>
#include <stack>
#include <string>
#include <fstream>

void openInputFile(std::ifstream& inFile);
bool checkBalance(std::ifstream& file);

int main() {
    std::ifstream file;
    openInputFile(file);
    std::cout << std::boolalpha;
    std::cout << checkBalance(file);

    return 0;
}


void openInputFile(std::ifstream& inFile){
    std::string filename;
    std::cout << "Please enter the file name: ";
    std::cin >> filename;
    inFile.open(filename);
    while (!inFile) {
        std::cout << "Error in the file name" << std::endl;
        std::cout << "Please enter the file name again: ";
        std::cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

bool checkBalance(std::ifstream& file){
    std::string temp;
    std::stack<char> record;
    bool toggle = false;

    while(file >> temp){
        if (temp == "begin") toggle = true;
        if (toggle) {
            if ((temp == "end") && (record.empty())) return true;
            for (char t : temp){
                if ((t == '(') || (t == '{') || (t == '[')) record.push(t);
                else if ((t == ')') || (t == '}') || (t == ']')) {
                    if (((record.top() == '(') && (t == ')')) ||
                        ((record.top() == '[') && (t == ']')) ||
                        ((record.top() == '{') && (t == '}'))) {
                        record.pop();
                    }
                    else return false;
                }
                
            }
        }
    }
    return false;
}


