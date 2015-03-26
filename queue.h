#ifndef QUEUE_H
#define QUEUE_H
#define NMAX 10

template <typename T> class Queue {
private:
    T queueArray[NMAX];
    int topLevel, bottomLevel, size;
public:
    Queue() {
        topLevel = 0;
        bottomLevel = 0;
        size = 0;
    }
    
    ~Queue() {};

    bool isEmpty() {
        return (size>0?false:true);
    }

    int enque(T item) {
        if (topLevel >= NMAX) {
            return -1;
        }
        queueArray[topLevel] = item;
        topLevel = (topLevel + 1) % NMAX;
        size++;
        return 0;
    }

    T deque() {
        if (isEmpty()) {
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
            T x;
            return x;
        }
        T x = queueArray[bottomLevel];
        return x;
    }
};

#endif
