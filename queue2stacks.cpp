#include <iostream>
#define NMAX 10

using namespace std;

template<typename T> class Stack {
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

    void push(T x) {
        if (topLevel >= NMAX - 1) {
            cout << "The stack is full." << endl;
        } else {
            theArray[++topLevel] = x;
        }
    }

    T pop() {
        if (isEmpty()) {
            cout << "The stack is empty!." << endl;
            T x;
            return x;
        } else {
            return theArray[topLevel--];
        }
    }

    T peek() {
        if (isEmpty()) {
            cout << "The stack is empty.";
            T x;
            return x;
        } else {
            return theArray[topLevel];
        }
    }
};

template <typename T> class Queue {
private:
    Stack<T> mainStack;
    Stack<T> helpStack;
public:
    Queue() {};
    
    ~Queue() {};
    
    bool isEmpty() {
        return mainStack.isEmpty();
    }
    
    void enque(T x) {
        mainStack.push(x);
    }
    
    T deque() {
        while (!mainStack.isEmpty()) {
            helpStack.push(mainStack.pop());
        }
        T r = helpStack.pop();
        while (!helpStack.isEmpty()) {
            mainStack.push(helpStack.pop());
        }
        return r;
    }
    
    T peek() {
        while (!mainStack.isEmpty()) {
            helpStack.push(mainStack.pop());
        }
        T r = helpStack.peek();
        while (!helpStack.isEmpty()) {
            mainStack.push(helpStack.pop());
        }
        return r;
    }
};
int main() {
    Queue<int> myQueue;
    if (myQueue.isEmpty()) cout << "The queue is empty." << endl;
    myQueue.enque(2);
    myQueue.enque(3);
    cout << myQueue.peek() << endl;
    myQueue.deque();
    cout << myQueue.peek() << endl;
    return 0;
}
