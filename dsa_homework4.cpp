#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

class Message {
public:
    string message, sender, reciver, date;
    
    Message() {};
    
    void printMessage() {
        cout << "Sender : " << sender << "." << endl;
        cout << "Reciver: " << reciver << "." << endl;
        cout << "Date: " << date << "." << endl;
        cout << "Message: " << message << "." << endl;
    }
};

Queue<Message> messageQueue;

class MessageSender {
public:
    string name;
    
    MessageSender() {};
    
    void sendMessage(Message &theMessage) {
        messageQueue.enque(theMessage);
    }
};

class MessageReciver {
public:
    string name;
    
    MessageReciver() {};
    
    void checkMessages() {
        messageQueue.peek().printMessage();
    }
    
    void deleteLastMessage() {
        messageQueue.deque();
    }
};

int main() {
    Message myMessage;
    MessageSender mySender;
    mySender.name = "Alex";
    MessageReciver myReciver;
    myReciver.name = "Radu";
    myMessage.message = "What is up?";
    myMessage.reciver = myReciver.name;
    myMessage.sender = mySender.name;
    myMessage.date = "27/3/2015";
    mySender.sendMessage(myMessage);
    myReciver.checkMessages();
    return 0;
}
