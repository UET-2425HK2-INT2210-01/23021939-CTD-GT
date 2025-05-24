#include <iostream>
using namespace std;

// Node của stack, lưu ký tự và con trỏ tới node trước đó
struct Node {
    char data;     // ký tự dấu ngoặc
    Node* prev;    // con trỏ tới node trước đó trong stack
    Node(char c) {
        data = c;
        prev = nullptr;
    }
};

// Stack được cài đặt bằng linked list đơn giản
class Stack {
public:
    Node* head = nullptr;  // node ở đầu stack (đỉnh stack)

    // Thêm một ký tự vào đỉnh stack
    void push(char c) {
        Node* newNode = new Node(c);
        newNode->prev = head; // liên kết node mới với node cũ
        head = newNode;       // cập nhật đầu stack thành node mới
    }

    // Lấy ký tự ở đỉnh stack mà không xóa
    char top() {
        if (head == nullptr) return '\0'; // nếu stack rỗng trả về ký tự null
        return head->data;
    }

    // Xóa phần tử ở đỉnh stack
    void pop() {
        if (head != nullptr) {
            Node* temp = head;  // lưu lại node đầu
            head = head->prev;  // cập nhật đỉnh stack thành node trước đó
            delete temp;        // giải phóng node đầu cũ
        }
    }

    // Kiểm tra stack có rỗng không
    bool isEmpty() {
        return head == nullptr;
    }
};

// Hàm kiểm tra chuỗi dấu ngoặc có hợp lệ hay không
bool isValid(string s) {
    Stack myStack;  // tạo một stack rỗng

    // duyệt từng ký tự trong chuỗi
    for (char c : s) {
        // nếu là dấu ngoặc mở thì đẩy vào stack
        if (c == '(' || c == '[' || c == '{') {
            myStack.push(c);
        } else {
            // nếu là dấu ngoặc đóng mà stack rỗng tức không có dấu mở tương ứng -> sai
            if (myStack.isEmpty()) return false;

            // lấy dấu mở trên đỉnh stack
            char top = myStack.top();

            // kiểm tra xem dấu mở trên đỉnh có khớp với dấu đóng hiện tại không
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                myStack.pop();  // nếu khớp thì bỏ dấu mở khỏi stack
            } else {
                // không khớp tức dấu ngoặc đóng sai vị trí hoặc không tương ứng
                return false;
            }
        }
    }

    // sau khi duyệt hết chuỗi, nếu stack rỗng tức tất cả dấu ngoặc đều đúng
    return myStack.isEmpty();
}

int main() {
    string s;
    cin >> s;  // nhập chuỗi dấu ngoặc từ bàn phím

    if (isValid(s)) {
        cout << "Valid";  // chuỗi hợp lệ
    } else {
        cout << "Invalid";  // chuỗi không hợp lệ
    }

    return 0;
}
