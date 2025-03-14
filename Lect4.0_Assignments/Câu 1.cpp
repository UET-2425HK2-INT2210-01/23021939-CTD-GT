#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) {
        value = val;
        next = nullptr;
    }
};
class MyLinkedList {
public:
    ListNode* first = nullptr;
    ListNode* last = nullptr;

    void addNode(int val) {
        ListNode* newNode = new ListNode(val);
        if (!first) {
            first = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
    void findNode(int val) {
        ListNode* temp = first;
        int index = 1;
        while (temp) {
            if (temp->value == val) {
                cout << index << endl;
                return;
            }
            temp = temp->next;
            ++index;
        }
        cout << "NO" << endl;
    }
    void reverseList() {
        if (!first) return; 

        ListNode* prev = nullptr;
        ListNode* curr = first;
        ListNode* nxt = nullptr;
        last = first; 

        while (curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        first = prev; 
        displayList(); 
    }

    void displayList() {
        ListNode* temp = first;
        while (temp) {
            cout << temp->value;
            if (temp->next) cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int numOperations;
    cin >> numOperations;
    string operation;
    int val;
    MyLinkedList myList;

    for (int i = 0; i < numOperations; i++) {
        cin >> operation;
        if (operation == "append") {
            cin >> val;
            myList.addNode(val);
        } else if (operation == "search") {
            cin >> val;
            myList.findNode(val);
        } else if (operation == "reverse") {
            myList.reverseList();
        }
    }

    return 0;
}
