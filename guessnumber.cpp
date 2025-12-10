#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {
    srand(time(0));

    int machinenumber = rand()% 100+1;
    int guessnumber;

    cout << "Number chossen between 1 to 100.\n";
    cout<< "can you guess it?\n";

    while (true) {
        cout <<"Enter your guess:";
        cin>> guessnumber;

        if (guessnumber > machinenumber) {
            cout << "Too high! Try again.\n";
        } else if (guessnumber < machinenumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You've guessed the number!\n";
            break;
        }
    }
}