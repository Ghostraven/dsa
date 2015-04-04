#include <iostream>
#include <string>
#include <cmath>
#include "queue.h"
#include "stack.h"
using namespace std;

struct Term {
    int coef;
    int expo;
    
    void printTerm() {
        if (coef == 0) {
            return;
        } else if (expo == 0) {
            cout << coef;
            return;
        }
        cout << coef << "X^" << expo;
    }
};

void fillPoly(int terms, Queue<Term> &theQueue) {
    for (int i = 0; i < terms; i++) {
        Term aTerm;
        int input;
        while (true) {
            cout << "Please enter an coeficient. Must be an integer." << endl;
            cin >> input;
            if (!cin) {
                cin.clear();
                cin.ignore(10000,'\n');
            } else {
                break;
            }
        } 
        aTerm.coef = input;
        while (true) {
            cout << "Please enter a exponent. Must be an integer." << endl;
            cin >> input;
            if (!cin) {
                cin.clear();
                cin.ignore(10000,'\n');
            } else {
                break;
            }
            
        } 
        aTerm.expo = input;
        theQueue.enque(aTerm);
    }
    cout << "The polynomial has been filled." << endl;
}

/*
void sortPoly(Queue<Term> &theQueue) {
    for (int i = 0; i <= theQueue.getSize(); i++) {
        Term aTerm = theQueue.deque();
        for (int i = 0; i <= theQueue.getSize()-1; i++) {
            Term bTerm = theQueue.deque();
            if (aTerm.expo < bTerm.expo) theQueue.enque(bTerm);
            else theQueue.enque(aTerm);
            aTerm = bTerm;
        }
        theQueue.enque(aTerm);
    }
}
*/
void printPoly(Queue<Term> theQueue) {
    while(!theQueue.isEmpty()) {
        Term aTerm = theQueue.deque();
        aTerm.printTerm();
        if (theQueue.getSize() > 0 && theQueue.peek().coef > 0) cout << "+";
    }
    cout << endl;
}

void printStack(Stack<Term> theStack) {
    while(!theStack.isEmpty()) {
        Term aTerm = theStack.pop();
        aTerm.printTerm();
        if (theStack.getTopLevel() >= 0 && theStack.peek().coef > 0) cout << "+";
    }
    cout << endl;
}

double computeValue(Queue<Term> theQueue, int x) {
    Stack<double> myResult;
    double partialSum;
    while(!theQueue.isEmpty()) {
        Term myTerm = theQueue.deque();
        partialSum = myTerm.coef * pow(x, myTerm.expo);
        myResult.push(partialSum + myResult.peek());
    }
    return myResult.peek();
}

void invertPoly(Queue<Term> theQueue) {
    Stack<Term> helpStack;
    while(!theQueue.isEmpty()) {
        helpStack.push(theQueue.deque());
    }
    while(!helpStack.isEmpty()) {
        theQueue.enque(helpStack.pop());
    }
    printPoly(theQueue);
}

void substract(Queue<Term> firstQueue, Queue<Term> secondQueue) {
    Queue<Term> helpQueue;
    Stack<Term> resultStack;
    while(!firstQueue.isEmpty()) {
        Term firstTerm = firstQueue.deque();
        while((firstTerm.expo != secondQueue.peek().expo) && (!secondQueue.isEmpty())) {
            helpQueue.enque(secondQueue.deque());
        }
        if (!secondQueue.isEmpty()) {
            Term aTerm;
            aTerm.expo = firstTerm.expo;
            aTerm.coef = firstTerm.coef - secondQueue.deque().coef;
            resultStack.push(aTerm);
            while(!secondQueue.isEmpty()) {
                helpQueue.enque(secondQueue.deque());
            }
        } else {
            if (firstQueue.isEmpty()) {
                while(!helpQueue.isEmpty()) {
                    resultStack.push(helpQueue.deque());
                }
            break;
            }
            resultStack.push(firstTerm);
        }
        while(!helpQueue.isEmpty()) {
            secondQueue.enque(helpQueue.deque());
        }
    }
    printStack(resultStack);
}

void multiply(Queue<Term> firstQueue, Queue<Term> secondQueue) {
    Stack<Term> resultStack;
    Queue<Term> helpQueue;
    Term aTerm, bTerm, cTerm;
    while (!firstQueue.isEmpty()) {
        aTerm = firstQueue.deque();
        while (!secondQueue.isEmpty()) {
            bTerm = secondQueue.deque();
            helpQueue.enque(bTerm);
            cTerm.expo = aTerm.expo * bTerm.expo;
            cTerm.coef = aTerm.coef * bTerm.coef;
            resultStack.push(cTerm);
        }
        while(!helpQueue.isEmpty()) {
            secondQueue.enque(helpQueue.deque());
        }
    }
    printStack(resultStack);
}

void cleanQueue(Queue<Term> &theQueue) {
    Queue<Term> helpQueue;
    while(!theQueue.isEmpty()) {
        if (theQueue.peek().coef != 0) {
            helpQueue.enque(theQueue.deque());
            continue;
        }
        theQueue.deque();
    }
    while(!helpQueue.isEmpty()) {
        theQueue.enque(helpQueue);
    }
}

void cleanStack(Stack<Term> &theStack) {
    Stack<Term> helpStack;
    while(!theStack.isEmpty()) {
        if (theStack.peek().coef != 0) {
            helpStack.push(theStack.pop());
            continue;
        }
        theStack.pop();
    }
    while(!helpStack.isEmpty()) {
        theStack.push(helpStack.pop());
    }
}

int main() {
    Queue<Term> firstQueue;
    Queue<Term> secondQueue;
    fillPoly(3, firstQueue);
    printPoly(firstQueue);
    fillPoly(3, secondQueue);
    printPoly(secondQueue);
    multiply(firstQueue, secondQueue);
    return 0;
}
