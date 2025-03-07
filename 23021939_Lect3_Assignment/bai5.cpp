#include<iostream>
#define max_stack 1000
class stack{
    int top;
    int arr[max_stack];
public:
    stack():top(-1){};
    void push(int x){
        if (top==max_stack){
            std::cout<<"Stack overflow"<<std::endl;
            return;
        }
        arr[++top] = x;
    }
    void pop(){
        if (top == -1){
            std::cout<<"Stack underflow"<<std::endl;
        }
        std::cout<<"Pop value: "<<arr[top--]<<std::endl;
    }
    void display(){
        if (top < 0) {
            std::cout<<"Stack is empty!"<<std::endl;
        }
        for (int i = 0;i<=top;i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }

};
int main(){
    int n;
    freopen("ex5.txt","r", stdin);
    std::cin>>n;
    stack my_stack ;
    for (int i = 0;i<n;i++){
        std::string s;
        std::cin>>s;
        if (s == "push"){
            int x;
            std::cin>>x;
            my_stack.push( x);
        } else if (s == "pop"){
            my_stack.pop();
        }
    }
    my_stack.display();
    return 0;
}
