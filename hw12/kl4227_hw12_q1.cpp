/*
 * author: Lin, Kuan-You
 * date: 4/4/2021
 * 2021 NYU Tandon Bridge Homework 12 Question 1

Cheque Problem, Please refer to the documentation.
*/

#include <iostream>
#include <vector>

using namespace std;

class Money;
class Check;

class Money{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount2.

    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount1 minus amount2.

    friend Money operator -(const Money& amount);
    //Returns the negative of the value of amount.

    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.

    friend bool operator <(const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.

    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.

    explicit Money(long dollars);
    //Initializes the object so its value represents $dollars.00.

    Money();
    //Initializes the object so its value represents $0.00.

    double get_value() const;
    //Returns the amount of money recorded in the data portion of the calling object.

    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in − $100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.

    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.

private:
    long all_cents;
};

class Check{
public:
    Check();

    void set_number(int newNumber);
    int get_number() const;

    void set_amount(Money newAmount);
    Money get_amount() const;

    void set_cash_status(char newStatus);
    char get_cash_status() const;

    friend bool operator ==(const Check& cheque1, const Check& cheque2);
    friend bool operator <(const Check& cheque1, const Check& cheque2);

    friend ostream& operator <<(ostream& outs, const Check& cheque);



private:
    int number;
    Money amount;
    bool cash_status;
};

int digit_to_int(char c){
    return ( static_cast<int>(c) - static_cast<int>('0') );
}

// Money Overloading Constructors
Money::Money(): all_cents{0}{
    //Body intentionally blank.
}
Money::Money(long dollars): all_cents{dollars * 100}{
    //Body intentionally blank.
}
Money::Money(long dollars, int cents){
    if (dollars * cents < 0) { //If one is negative and one is positive
        cout << "Illegal values for dollars and cents.\n";
        exit(0);
    }
    all_cents = dollars * 100 + cents;
}

// Check Overloading Constructors
Check::Check(): number{0}, amount{Money()}, cash_status{true}{
    //Body intentionally blank.
}

// Money Method
double Money::get_value( ) const{
    return (all_cents * 0.01);
}

// Check Method
void Check::set_number(int newNumber){
    number = newNumber;
}
int Check::get_number() const{
    return number;
}
void Check::set_amount(Money newAmount){
    amount = newAmount;
}
Money Check::get_amount() const{
    return amount;
}
void Check::set_cash_status(char newStatus){
    if (newStatus == 'Y'){
        cash_status = true;
    } else if (newStatus == 'N'){
        cash_status = false;
    } else {
        cout << "Illegal input for cash status\n";
        exit(0);
    }
}
char Check::get_cash_status()  const{
    if (cash_status)
        return 'Y';
    else
        return 'N';
}



// Money Overloading Operator
Money operator +(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}
Money operator -(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}
Money operator -(const Money& amount){
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}
bool operator ==(const Money& amount1, const Money& amount2){
    return (amount1.all_cents == amount2.all_cents);
}
bool operator <(const Money& amount1, const Money& amount2){
    return (amount1.all_cents < amount2.all_cents);
}
istream& operator >>(istream& ins, Money& amount){
    char one_char, decimal_point,
    digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> one_char;
    if (one_char == '-'){
        negative = true;
        ins >> one_char; //read '$'
    } else {
        // if the input is legal, then one_char == '$'
        negative = false;
    }

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)){
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;

    if (negative)
        amount.all_cents = -amount.all_cents;

    return ins;
}
ostream& operator <<(ostream& outs, const Money& amount){
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0)
        outs << "- $" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';

    outs << cents;

    return outs;
}

// Check Overloading Operator
bool operator ==(const Check& cheque1, const Check& cheque2){
    return (cheque1.number == cheque2.number);
}
bool operator <(const Check& cheque1, const Check& cheque2){
    return (cheque1.number < cheque2.number);
}
ostream& operator <<(ostream& outs, const Check& cheque){
    outs << cheque.number << "\t" << cheque.get_amount() << "\t" << cheque.get_cash_status() << endl;
    return outs;
}

int main() {
    cout << "Welcome to the Bank!" << endl;
    cout << "Please enter your previous (old) bank balance (-$##.## or $##.##): " << endl;
    Money old_balance;
    cin >> old_balance;

    cout << "Please enter your current (new) bank balance (-$##.## or $##.##): " << endl;
    Money new_balance;
    cin >> new_balance;

    cout << "Please enter the number of deposits you have in the session (#): " << endl;
    int number_of_deposit;
    cin >> number_of_deposit;

    cout << "Please enter the deposits you have in the session ($##.##), each per line: " << endl;
    vector<Money> vector_deposit;
    for (int i = 0; i < number_of_deposit; i++){
        Money temp;
        cin >> temp;
        vector_deposit.push_back(temp);
    }

    cout << "Please enter the number of checks you have in the session (#): " << endl;
    int number_of_check;
    cin >> number_of_check;

    vector<Check> vector_check;
    cout << "Please enter the checks you have in the session\n";
    cout << "The check should have 3 elements, number, amount, and cashed or not \n";
    cout << "The format be like (# $##.## C) where each element is separated by a space, \n"
            "and (Y or N) indicates if the check is cashed or not"
            ", each check per line: \n";
    for (int i = 0; i < number_of_check; i++){
        Check temp;

        int number;
        Money amount;
        char cash_c;

        cin >> number >> amount >> cash_c;
        temp.set_number(number);
        temp.set_amount(amount);
        temp.set_cash_status(cash_c);

        vector_check.push_back(temp);
    }

    Money sum_check_cashed;
    for(Check n: vector_check){
        if (n.get_cash_status() == 'Y'){
            sum_check_cashed = sum_check_cashed + n.get_amount();
        }
    }

    Money sum_deposit;
    for(Money n: vector_deposit){
        sum_deposit = sum_deposit + n;
    }

    cout << endl << "Total value of your deposit in this session is " << sum_deposit;
    cout << endl << "Total value of your check cashed in this session is " << sum_check_cashed << endl;

    Money hypothetical_balance = old_balance + sum_deposit - sum_check_cashed;
    cout << endl << "The old balance is " << old_balance << endl
    << "The new balance by your calculation is " << hypothetical_balance << endl
    << "The new balance by the bank is " << new_balance << endl
    << "The difference is " << (hypothetical_balance - new_balance) << endl;

    cout << endl << "List of all cashed checks:" << endl;
    cout << "Number\tAmount\tCashed Status" << endl;
    for(Check n: vector_check){
        if (n.get_cash_status() == 'Y'){
            cout << n;
        }
    }

    cout << endl << "List of all non-cashed checks:" << endl;
    cout << "Number\tAmount\tCashed Status" << endl;
    for(Check n: vector_check){
        if (n.get_cash_status() == 'N'){
            cout << n;
        }
    }
    return 0;
}