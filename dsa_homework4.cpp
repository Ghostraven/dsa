#include <iostream>
#define NMAX 10
#define MAXSTR 40
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

class MessageSender {
private:
    string name[MAXSTR];
public:
    MessageSender(string &(theName[])) {
        name = theName;
    }
    
    char showName() {
        return name;
    }
};

class MessageRecipient {
private:
    string name[MAXSTR];
public:
    MessageRecipient(string %(theName[])) {
        name = theName;
    }
    
    char showName() {
        return name;
    }
};

template <typename T> class Message {
private:  
    string message[MAXSTR];
    MessageSender sender;
    MessageRecipient recipient;
public: 
    Message(MessageSender theSender, MessageRecipient theRecipient, string &(theMessage[])) {
        sender = theSender;
        recipient = theRecipient;
        message = theMessage;
    }
    
    ~Message() {};
    
    void showMessage() {
        cout << "The sender: " << sender.showName() << "." << endl;
        cout << "The recipient: " << recipient.showName() << "." << endl;
        cout << "The message " << message << "." << endl;
    }
};



class MessageSystem {
private:
    Queue<Message> messageQueue;
    MessageSender sender;
    MessageRecipient recipient;
public:
    MessageSystem(MessageSender theSender, MessageRecipient theRecipient) {
        sender = theSender;
        recipient = theRecipient;
    }
    
    void sendMessage(string message[]) {
        messageQueue.enque("message");
    }
    
    void checkLastMessage() {
        cout << messageQueue.peek() << endl;
    }
    
    void deleteLastMessage() {
        messageQueue.deque();
        cout << "The message have been deleted." << endl;
    }
}

int main() {
    MessageSender mySender("Alex");
    MessageRecipient myRecipient("Radu");
    MessageSystem mySystem(mySender, myRecipient);
    mySystem.sendMessage("Ce faci ba?");
    mySystem.sendMessage("Raspunde!");
    mySystem.checkLastMessage();
    mySystem.deleteLastMessage();
    mySystem.checkLastMessage();
    
    return 0;
}
