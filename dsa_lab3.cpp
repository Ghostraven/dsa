#include <iostream>
#define NMAX 10

using namespace std;

template<typename T>
class Stack {
private:
    T theArray[NMAX];  
    int topLevel;
public:
Stack() {
    topLevel = -1;
}

~Stack() {};

 int isEmpty() {
    return (topLevel < 0); 
}

void push (T x) {
    if(topLevel >= NMAX - 1) {
        cout << "The stack is full." << endl;
    } else {
        theArray[++topLevel] = x;
    }
}

T pop () {
    if (isEmpty()) {
        cout << "The stack is empty!." << endl;
        return NULL;
    } else {
        return theArray[topLevel--];
    }
}

T peek () {
    if (isEmpty()) {
        cout << "The stack is empty.";
        return NULL;
    } else {
        return theArray[topLevel];
    }
}

void displayElements() {
    for (int i = topLevel; i >= 0; i--) {
        cout << theArray[i] << endl;
    }
}

void sortElements() {
    bool changed;
    do {
        changed = false;
        for (int i = 0; i < topLevel; i++) {
            if (theArray[i] > theArray[i+1]) {
                changed = true;
                int temp = theArray[i];
                theArray[i] = theArray[i+1];
                theArray[i+1] = temp;
            }
        }
        
    } while (changed == true);
}

bool checkPali() {
    Stack<T> helpStack;
    Stack<T> cloneStack;
    for (int i = 0; i < NMAX; i++) {
        cloneStack.theArray[i] = theArray[i];
    }
    for (int i = 0; i < NMAX; i++) {
        helpStack.theArray[i] = pop();
    }
    for (int i = 0; i< NMAX; i++) {
        if (helpStack.theArray[i] != cloneStack.theArray[i]) {
            return false;
        }
    }
    return true;
}
};
 
int main () {
    Stack<int> myStack;
    myStack.peek();
    myStack.push(8);
    myStack.push(7);
    myStack.push(6);
    myStack.push(5);
    myStack.displayElements();
    cout << "/////////////////////////" << endl;
    myStack.sortElements();
    myStack.displayElements();
    Stack<int> paliStack;
    paliStack.push(1);
    paliStack.push(1);
    paliStack.push(1);
    paliStack.push(3);
    paliStack.push(1);
    paliStack.push(1);
    paliStack.push(1);
    if (paliStack.checkPali()) {
        cout << "It's a palindrome!" << endl;
    }
    else {
        cout << "It's not a palindrome!" << endl;
    }
    return 0;
}
