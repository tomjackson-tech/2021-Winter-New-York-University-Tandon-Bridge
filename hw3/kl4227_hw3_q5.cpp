/*
 * author: Lin, Kuan-You
 * date: 1/28/2021
 * 2021 NYU Tandon Bridge Homework 3 Question 5

Body mass index (BMI) is a number calculated from a person’s weight and height using the following formula: 𝑤𝑒𝑖𝑔h𝑡/h𝑒𝑖𝑔h𝑡^2.
Where 𝑤𝑒𝑖𝑔h𝑡 is in kilograms and h𝑒𝑖𝑔h𝑡 is in meters. According to the Centers for Disease Control and Prevention,
the BMI is a fairly reliable indicator of body fatness for most people. BMI does not measure body fat directly,
but research has shown that BMI correlates to direct measures of body fat,
such as underwater weighing and dual-energy X-ray absorptiometry.

The following table gives the weight status in respect to the BMI value:

    BMI Range: Weight Status
    Below 18.5: Underweight
    [18.5, 25): Normal
    [25, 30): Overweight
    30 and above: Obese

Write a program that prompts for weight (in pounds) and height (in inches) of a person,
and prints the weight status of that person.

Your program should interact with the user exactly as it shows in the following example:
Please enter weight (in pounds): 135
Please enter height (in inches): 71
The weight status is: Normal

Note: 1 pound is 0.453592 kilograms and 1 inch is 0.0254 meters.

*/
#include <iostream>
#include <cmath>

using namespace std;

const double pound_to_kilogram{0.453592};
const double inch_to_meter{0.0254};

const double UNDERWEIGHT{18.5};
const double NORMAL{25};
const double OVERWEIGHT{30};

int main() {

    cout << "Please enter weight (in pounds): ";
    double weight{0};
    cin >> weight;
    weight = weight * pound_to_kilogram;

    cout << "Please enter height (in inches): ";
    double height{0};
    cin >> height;
    height = height * inch_to_meter;

    double bmi = weight / pow(height, 2);

    if (bmi < UNDERWEIGHT){
        cout << "The weight status is: Underweight";
    } else if ((bmi >= UNDERWEIGHT) and (bmi < NORMAL)){
        cout << "The weight status is: Normal";
    } else if ((bmi >= NORMAL) and (bmi < OVERWEIGHT)){
        cout << "The weight status is: Overweight";
    } else {
        cout << "The weight status is: Obese";
    }

    return 0;
}
