#include <iostream>
#define NMAX 10

using namespace std;

template <typename T> class Queue {
public:
    T queueArray[NMAX];
    int topLevel, bottomLevel, size;
public:
    Queue() {
        topLevel = 0;
        bottomLevel = 0; 
        size = 0;
    }
    
    ~Queue() {}
    
    bool isEmpty() {
        if (size == 0) return true;
        return false;
    }
    void enque(T item) {
        if (topLevel >= NMAX) {
            cout << "The queue if full." << endl;
            return;
        }
        queueArray[topLevel] = item;
        topLevel = (topLevel + 1) % NMAX;
        size++;
    }
    T deque() {
        if (isEmpty()) {
            cout << "The queue is empty." << endl;
            return NULL;
        }
        T x = queueArray[bottomLevel];
        bottomLevel = (bottomLevel + 1) % NMAX;
        size--;
        return x;
    }
    T peek() {
        if (isEmpty()) {
            cout << "The queue is empty." << endl;
            return NULL;
        }
        T x = queueArray[bottomLevel];
        return x;
    }
};

template <typename T> class QueuedStack {
private:
    Queue<T> mainQueue;
    Queue<T> helpQueue;
public:
    QueuedStack() {};
    
    ~QueuedStack() {};
    
    bool isEmpty() {
        return mainQueue.isEmpty();
    }
    
    void push(T x) {
        mainQueue.enque(x);
    }
    
    T pop() {
        while(mainQueue.size >= 1) {
            helpQueue.enque(mainQueue.deque());
        }
        T r = mainQueue.deque();
        while(!helpQueue.isEmpty()) {
            mainQueue.enque(helpQueue.deque());
        }
        return r;
    }
    
    T peek() {
        while(mainQueue.size > 1) {
            helpQueue.enque(mainQueue.deque());
        }
        T r = mainQueue.peek();
        while(!helpQueue.isEmpty()) {
            mainQueue.enque(helpQueue.deque());
        }
        return r;
    }
};

int main() {
    QueuedStack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.peek() << endl;
    myStack.pop();
    cout << myStack.peek() << endl;
    return 0;
}
