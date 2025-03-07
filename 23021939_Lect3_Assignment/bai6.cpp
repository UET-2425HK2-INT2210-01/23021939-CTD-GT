#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Stack{
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void print(){
        Node* tmp = head;
        while(tmp != nullptr){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
        return;
    }

    void push(int x){
        Node* newNode = new Node(x);
        Node* tmp = tail;
        if(tmp == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            newNode->prev = tmp;
            tmp->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        Node* tmp = tail;
        if(tmp == nullptr){
            return;
        }else{
            tail = tmp->prev;
            tail->next = tmp->next;
            delete tmp;
        }
    }
};

int main(){
    int n;
    cin >> n;
    string operat;
    int x;
    Stack stack;
    for(int i = 1; i <= n; i++){
        cin >> operat;
        if(operat == "push"){
            cin >> x;
            stack.push(x);
        }
        if(operat == "pop"){
            stack.pop();
        }
    }
    stack.print();
    return 0;
}

