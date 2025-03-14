#include<iostream>
using namespace std;

struct Node{
	int data1;
	int data2;
	Node* next;
	Node* prev;
	Node(int x, int p){
		data1 = x;
		data2 = p;
		next = nullptr;
		prev = nullptr;
		
	}
};
class doublyLinkedList{
	public:
		Node* head = nullptr;
		Node* tail = nullptr;
		
	void print(){
		Node* temp = head;
		while(temp != nullptr){
			 cout << "(" << temp->data1 << "," << temp->data2 <<")";
			 temp = temp -> next;
			 if(temp != nullptr){
			 	cout << ";";
			 }
		}
		cout << endl;
	}
	void enqueue(int x, int p){
		Node* newNode = new Node(x,p);
		if(head == nullptr){
			head = newNode;
			tail = newNode;
		}else if(p > head->data2){
			newNode ->next = head;
			head -> prev = newNode;
			head = newNode;
		}else if( p <= tail->data2){
			tail -> next = newNode;
			newNode -> prev = tail;
			tail = newNode;
		}else{
			Node* temp = head;
			while(temp -> next && p <= temp -> next -> data2){
				temp = temp -> next;
			}
			 newNode->next = temp->next;
   			 if (temp->next) {
       		 temp->next->prev = newNode;
   			 }
  			  temp->next = newNode;
   			 newNode->prev = temp;
		}
	}
	void dequeue(){
		if(head != nullptr){
			Node *temp = head;
			head = head -> next;
			if(head != nullptr){
				head -> prev = nullptr;
			}else{
				tail = nullptr;
			}
		delete temp;
		}
	}
};
int main(){
	int n;
	cin >> n;
	int x,p;
	doublyLinkedList myList;
	string operat;
	for(int i = 0; i < n; i++){
		cin >> operat;
		if(operat == "enqueue"){
			cin >> x >> p;
			myList.enqueue(x,p);
		}else if(operat == "dequeue"){
			myList.dequeue();
		}else{
			cout <<" invalid";
		}
	}
	myList.print();
	return 0;
}