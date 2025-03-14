#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node(char c) {
        data = c;
        prev = nullptr;
    }
};
class Stack {
public:
    Node* head = nullptr;

    void push(char c) { 
        Node* newNode = new Node(c);
        newNode->prev = head;
        head = newNode;
    }
    char top() {  
        if (head == nullptr) return '\0';
        return head->data;
    }
    void pop() { 
        if (head != nullptr) {
            Node* temp = head;
            head = head->prev;
            delete temp;
        }
    }
    bool isEmpty() {  
        return head == nullptr;
    }
};

bool isValid(string s) {
    Stack myStack;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            myStack.push(c); 
        } else {
            if (myStack.isEmpty()) return false;  
            char top = myStack.top();
            if ((c == ')' && top == '(') || 
                (c == ']' && top == '[') || 
                (c == '}' && top == '{')) {
                myStack.pop();  
            } else {
                return false;  
            }
        }
    }
    
    return myStack.isEmpty(); 
}

int main() {
    string s;
    cin >> s;
    if (isValid(s)) {
        cout << "Valid";
    } else {
        cout << "Invalid";
    }

    return 0;
}
