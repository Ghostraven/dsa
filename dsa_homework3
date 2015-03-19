/* 
 * File:   main.cpp
 * Author: Alex
 *
 * Created on March 11, 2015, 9:09 PM
 */

#include <cstdlib>
#include <iostream>
#define NMAX 10

using namespace std;

template <typename T> class Queue {
private:
    T queueArray[NMAX];
    int topLevel, bottomLevel, size;
public:
    Queue() {
        this -> topLevel, bottomLevel, size = 0;
    }
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
            T x;
            return x;
        }
        T x = queueArray[bottomLevel];
        bottomLevel = (bottomLevel + 1) % NMAX;
        size--;
        return x;
    }
    T peek() {
        if (isEmpty()) {
            cout << "The queue is empty." << endl;
            T x;
            return x;
        }
        T x = queueArray[bottomLevel];
        return x;
    }
};

void decToBinary(int number) {
    if (number != 0) decToBinary(number/2);
    if (number != 0) cout << number % 2;
}

void decToFive(int number) {
    if (number != 0) decToFive(number/5);
    if (number != 0) cout << number % 5;
}

void decToEight(int number) {
    if (number != 0) decToFive(number/8);
    if (number != 0) cout << number % 8;
}

void decToSixteen(int number) {
    if (number != 0) decToFive(number/16);
    if (number != 0) cout << number % 16;
}

void decToBase(int number, int base) {
    if (number != 0) decToFive(number/base);
    if (number != 0) cout << number % base;
}
/*
 * 
 */
int main() {
    Queue<int> myQueue;
    if (myQueue.isEmpty()) cout << "The queue is empty." << endl;
    myQueue.enque(2);
    cout << myQueue.peek() << endl;
    myQueue.deque();
    myQueue.enque(3);
    cout << myQueue.peek() << endl;
    myQueue.deque();
    myQueue.enque(4);
    cout << myQueue.peek() << endl;
    myQueue.deque();
    decToBinary(114);
    cout << endl;
    decToBase(114, 5);
    return 0;
}

