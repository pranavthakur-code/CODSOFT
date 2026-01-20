#include <iostream>
using namespace std;

int main () {
    int number1, number2;
    char operation;

    cout << "Enter first number: ";
    cin >> number1;

    cout <<"Enter second number: ";
    cin >> number2;

    cout <<"enter operation (+, -, *, /): ";
    cin >> operation;

    if (operation == '+') {
        cout << "Result: " << number1 + number2 << endl;
    } else if (operation == '-') {
        cout << "Result: " << number1 - number2 << endl;
    } else if (operation == '*') {
        cout << "Result: " << number1 * number2 << endl;
    } else if (operation == '/') {
        if (number2 != 0) {
            cout << "Result: " << number1 / number2 << endl;
        } else {
            cout << "Error: Division by zero!" << endl;
        }
    } else {
        cout << "Invalid operation!" << endl;
    }
}
