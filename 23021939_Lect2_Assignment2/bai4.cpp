#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() { front = rear = nullptr; }
    void enqueue(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue() {
        if (front) {
            Node* temp = front;
            front = front->next;
            if (!front) rear = nullptr;
            delete temp;
        }
    }
    void print() {
        Node* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    Queue q;
    
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        
        if (command == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (command == "dequeue") {
            q.dequeue();
        }
    }
    
    q.print();
    return 0;
}
