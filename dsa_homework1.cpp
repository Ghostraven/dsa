/* 
 * File:   main.cpp
 * Author: Alex
 *
 * Created on March 5, 2015, 10:02 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

struct Polynomial {
    int coef;
    unsigned int exponent;
};

class Date {
public:
    int day;
    int month;
    int year;
    Date(int theDay, int theMonth, int theYear) {
        day = theDay;
        month = theMonth;
        year = theYear;
    }
    Date() {};
    
    bool isValid() {
        if (day > 0 && day < 32 && month > 0 && month < 13) {
            return true;
        } else {
            return false;
        }
    }
    
    void nextDate() {
       cout << day+1 << "/" << month << "/" << year << endl;
    }
    
    void previousDate() {
       cout << day-1 << "/" << month << "/" << year << endl;
    }
    
    void printDate() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

bool isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) return true;
    else return false;
}

void cab() {
    char input[4];
    char guess[4] = {'2', '4', '1', '3'};
    bool correct[4] = {false, false, false, false};
    bool succes = false;
    int check;
    while (succes == false) {
        check = 0;
        for (int i = 0; i < 4; i++) {
            if (correct[i] == true) {
                cout << guess[i];
            } else {
                cout << "*";
            }
        }
        cout << endl;
        cout << "Enter your guess!" << endl;
        cin >> input;
        for (int i = 0; i < 4; i++) {
            if (input[i] == guess[i]) {
                check++;
                correct[i] = true;
            }
        }
        if (check == 4) {
            succes = true;
            cout << "You win!" << endl;
        } else {
            cout << check << "/4 Correct." << endl;
        }
    }
}

void printPoly(Polynomial thePoly) {
    cout << thePoly.coef << "X^" << thePoly.exponent << endl;
}

void addPoly(Polynomial firstPoly, Polynomial secondPoly) {
    if (firstPoly.exponent != secondPoly.exponent) {
        cout << firstPoly.coef << "X^" << firstPoly.exponent << " + " << secondPoly.coef << "X^" << secondPoly.exponent << endl;
    } else {
        cout << firstPoly.coef + secondPoly.coef << "X^" << firstPoly.exponent << endl;
    }
}

void multiplyPoly(Polynomial firstPoly, Polynomial secondPoly) {
    cout << firstPoly.coef * secondPoly.coef << "X^" << firstPoly.exponent * secondPoly.exponent << endl;
}

int main() {
    //if (isPerfect(28) == true) cout << "It's perfect!" << endl;
    //else cout << "It's not perfect!" << endl;
    //cab();
    Date myDate;
    myDate.day = 3;
    myDate.month = 5;
    myDate.year = 2015;
    if (myDate.isValid()) cout << "It's valid!" << endl;
    myDate.nextDate();
    myDate.previousDate();
    Polynomial myFirstPoly;
    myFirstPoly.coef = 5;
    myFirstPoly.exponent = 8;
    Polynomial mySecondPoly;
    mySecondPoly.coef = 3;
    mySecondPoly.exponent = 5;
    printPoly(myFirstPoly);
    addPoly(myFirstPoly, mySecondPoly);
    multiplyPoly(myFirstPoly, mySecondPoly);
    return 0;
}
