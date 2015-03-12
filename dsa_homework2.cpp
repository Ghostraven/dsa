#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */

//*Overloading exists in C++. In works in similar way to Java. A function with the 
//same name can have a different return type and/or different arguments.
//*Abstract classes also exist in C++. They are meant to be used as the most 
//general superclass. Abstract classes contain the signature of functions that
//are meant to be overridden in subclasses. They also contain constant variables.
//It's better to use templates when the concrete type is know at compile time.
//If the choice of type is made at run-time as result of an action (i.e. user input)
//then abstract classes are a better choice.
//"Static class" doesn't mean anything in C++. You could call a class "static"
//if it only has static variables and functions, but in doesn't have any special
//meaning.

class BankAccount {
private:
    string owner;
    double balance;
public:
    BankAccount(string owner) {
        this -> owner = owner;
        this -> balance = 0;
    }
    void deposit(double amount) {
        balance += amount;
    }
    
    void withdraw(double amount) {
        if (balance - amount >= 0) {
            balance -= amount;
        } else {
            cout << "There are not enough money to withdraw." << endl;
        }
    }
    void dispayOwner() {
        cout << "The owner of the account is " << owner << "." << endl;
    }
    void displayBalance() {
        cout << "The account has a balance of " << balance << "." << endl;
    }
};

class PointClass {
public:
        int coord_x, coord_y, n;
    void reset() {
        coord_x = coord_y = 0;
    }
    void moveX(int x) {
        if (coord_x + x < 0 || coord_x + x > 1) {
            cout << "Can't move that way." << endl;
        } else {
            this -> coord_x = coord_x + x;
        }
    };
    void moveY(int y) {
        if (coord_y + y < 0 || coord_y + y > n) {
            cout << "Can't move that way." << endl;
        } else {
            this -> coord_y = coord_y + y;
        }
    };
    void moveXY(int x, int y) {
        if (coord_x + x < 0 || coord_x + x > 1) {
            cout << "Can't move that way." << endl;
        } else {
            this -> coord_x = coord_x + x;
        }
        if (coord_y + y < 0 || coord_y + y > n) {
            cout << "Can't move that way." << endl;
        } else {
            this -> coord_y = coord_y + y;
        }
    };
    void pointPos() {
        cout << "The point is at position x: " << coord_x << " and y: " << coord_y << "." << endl;
    }
};

struct Point {
public:
    int coord_x, coord_y, n;
    void reset() {
        coord_x = coord_y = 0;
    }
    void moveX(int x) {
        if (coord_x + x < 0 || coord_x + x > 1) {
            cout << "Can't move that way." << endl;
        } else {
            this -> coord_x = coord_x + x;
        }
    };
    void moveY(int y) {
        if (coord_y + y < 0 || coord_y + y > n) {
            cout << "Can't move that way." << endl;
        } else {
            this -> coord_y = coord_y + y;
        }
    };
    void moveXY(int x, int y) {
        if (coord_x + x < 0 || coord_x + x > 1) {
            cout << "Can't move that way." << endl;
        } else {
            this -> coord_x = coord_x + x;
        }
        if (coord_y + y < 0 || coord_y + y > n) {
            cout << "Can't move that way." << endl;
        } else {
            this -> coord_y = coord_y + y;
        }
    };
    void pointPos() {
        cout << "The point is at position x: " << coord_x << " and y: " << coord_y << "." << endl;
    }
    double getDistance() {
        return sqrt(coord_x * coord_x + coord_y * coord_y);
    }
};

static void change(Point &a, Point &b) {
    int x = a.coord_x;
    a.coord_x = b.coord_x;
    b.coord_x = x;
        
    int y = a.coord_y;
    a.coord_y = b.coord_y;
    b.coord_y = y;
}
    
static void sortPoints(Point (&pointArray)[5]) {
    bool changed;
    do {
        changed = false;
        for (int i = 0; i < 4; i++) {
            if (pointArray[i].getDistance() > pointArray[i+1].getDistance()) {
                change(pointArray[i], pointArray[i+1]);
                changed = true;
            }
        }
    } while (changed == true);
}

int main() {
    int number;
    Point myPoint;
    myPoint.coord_x = 0;
    myPoint.coord_y = 0;
    myPoint.n = 0;
    cout << "Enter N: " << endl;
    cin >> number;
    myPoint.n = number;
    myPoint.moveX(1);
    myPoint.moveY(2);
    myPoint.moveXY(-1, 1);
    myPoint.pointPos();
    Point pointArray[5];
    pointArray[0].coord_x = 1;
    pointArray[0].coord_y = 3;
    pointArray[1].coord_x = 1;
    pointArray[1].coord_y = 2;
    pointArray[2].coord_x = 1;
    pointArray[2].coord_y = 1;
    pointArray[3].coord_x = 1;
    pointArray[3].coord_y = 0;
    pointArray[4].coord_x = 0;
    pointArray[4].coord_y = 0;
    for (int i = 0; i < 5; i++) {
        cout << "The point is at position x: " << pointArray[i].coord_x << " and y: " << pointArray[i].coord_y
                << ", and distance " << pointArray[i].getDistance() << endl;
    }
    sortPoints(pointArray);
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << "The point is at position x: " << pointArray[i].coord_x << " and y: " << pointArray[i].coord_y
                << ", and distance " << pointArray[i].getDistance() << endl;
    }
    cout << endl;
    BankAccount myAccount("Alex");
    myAccount.deposit(200);
    myAccount.dispayOwner();
    myAccount.displayBalance();
    myAccount.withdraw(50);
    myAccount.dispayOwner();
    myAccount.displayBalance();
    myAccount.withdraw(200);
    return 0;
}

