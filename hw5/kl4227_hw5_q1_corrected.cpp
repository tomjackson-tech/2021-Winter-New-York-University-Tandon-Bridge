/*
 * author: Lin, Kuan-You
 * date: 2/3/2021
 * 2021 NYU Tandon Bridge Homework 5 Question 2

Question 2:
Implement a number guessing game. The program should randomly choose an integer between 1 and 100 (inclusive), and have the user try to guess that number.

Implementations guidelines:
1. The user can guess at most 5 times.

2. Before each guess the program announces:
• An updated guessing-range, taking in to account previous guesses and responses.
• The number of guesses that the user has left.

3. If the user guessed correctly, the program should announce that, and also tell how many
guesses the user used.

4. If the user guessed wrong, and there are still guesses left, the program should tell the
user if the number (it chose) is bigger or smaller than the number that the user guessed.

5. If the user didn’t guess the number in all of the 5 tries, the program should reveal the
number it chose.

6. Follow the execution examples below for the exact format.
In order to generate random numbers (of type int), you should first call the srand function (one time) to initialize a seed for the random number generator. Then, you can call the rand function repeatedly to generate random integers.

Your program should interact with the user exactly as it shows in the following two examples:

Execution example 1:
I thought of a number between 1 and 100! Try to guess it.
Range: [1, 100], Number of guesses left: 5
Your guess: 15
Wrong! My number is bigger.
Range: [16, 100], Number of guesses left: 4
Your guess: 34
Wrong! My number is smaller.
Range: [16, 33], Number of guesses left: 3
Your guess: 23
Congrats! You guessed my number in 3 guesses.

Execution example 2:
I thought of a number between 1 and 100! Try to guess it.
Range: [1, 100], Number of guesses left: 5
Your guess: 15
Wrong! My number is bigger.
Range: [16, 100], Number of guesses left: 4
Your guess: 50
Wrong! My number is smaller.
Range: [16, 49], Number of guesses left: 3
Your guess: 3
Wrong! My number is bigger.
Range: [16, 49], Number of guesses left: 2
Your guess: 34
Wrong! My number is smaller.
Range: [16, 33], Number of guesses left: 1
Your guess: 20
Out of guesses! My number is 25

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int answer = (rand() % 100) + 1;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

    int upper = 100;
    int lower = 1;

    for (int i = 5; i > 0; i--){
        cout << "Range: [" << lower << ", " << upper << "], Number of guesses left: " << i << endl;
        cout << "Your guess: ";

        int attempt{0};
        cin >> attempt;

        if ((attempt != answer) and (i == 1)){
            cout << "Out of guesses! My number is " << answer << endl;
        } else if (attempt == answer){
            cout << "Congrats! You guessed my number in " << 6 - i  << " guesses." << endl;
            break;
        } else if (attempt > answer){
            cout << "Wrong! My number is smaller.\n" << endl;
            if (upper > attempt){
                upper = attempt - 1;
            }
        } else if (attempt < answer){
            cout << "Wrong! My number is bigger.\n" << endl;
            if (lower < attempt){
                lower = attempt + 1;
            }
        }
    }
    return 0;
}
