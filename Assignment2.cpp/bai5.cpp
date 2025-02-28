#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void printReversed() {
        if (!top) return;

        int size = 0;
        Node* cur = top;
        while (cur) {
            size++;
            cur = cur->next;
        }

        int* arr = new int[size];
        cur = top;
        for (int i = size - 1; i >= 0; i--) {
            arr[i] = cur->data;
            cur = cur->next;
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        delete[] arr;
    }
};

int main() {
    int n;
    cin >> n;
    Stack s;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (command == "pop") {
            s.pop();
        }
    }

    s.printReversed();
    return 0;
}
