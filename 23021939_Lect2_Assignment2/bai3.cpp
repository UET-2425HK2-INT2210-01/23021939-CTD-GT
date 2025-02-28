#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

int count_triplets(Node* head){
    int cnt = 0;
    while (head->next != nullptr){
        if (head->prev == nullptr){
            head = head->next;
            continue;
        }
        if (head->data + head->prev->data + head->next->data == 0){
            cnt++;
        }
        head = head->next;
    }
    return cnt;
}

int main(){
    int n; cin >> n;
    Node* head = nullptr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        Node* newNode = new Node(x);
        if (head == nullptr){
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    cout << count_triplets(head);

    return 0;
}
